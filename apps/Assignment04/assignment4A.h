#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct task
{
	int number;
	char status;
	std::string description;
};

vector<task>* load_file(char* filename)
{
	vector<task>* tasks = new vector<task>();
	ifstream file_stream(filename);

	if (file_stream.is_open())
	{
		string line;
		while (getline(file_stream, line))
		{
			std::istringstream stream(line);
			task entry;

			if ((stream >> entry.number >> entry.status) && getline(stream, entry.description))
			{
				tasks->push_back(entry);
			}
			else
			{
				cout << "Error processing line \"" << line << "\"!" << std::endl;
				continue;
			}
		}
	}
	else
	{
		cout << "ERROR: could not open task list for reading." << endl;
	}

	return tasks;
}

void display_tasks(vector<task>* tasks)
{
	cout << "-------------------------------" << endl <<
		"Number\tStatus\tDescription" << endl;
	for (const auto& task : *tasks)
	{
		cout << task.number << "\t" << task.status << "\t" << task.description << endl;
	}
}

void display_task(vector<task>* tasks, int number)
{
	bool found = false;

	for (const auto& task : *tasks)
	{
		if (task.number == number)
		{
			cout << task.number << "\t" << task.status << "\t" << task.description << endl;
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Task with number " << number << " not found in list" << endl;
	}
}

void mark_task(vector<task>* tasks, int number)
{
	bool found = false;

	for (auto& task : *tasks)
	{
		if (task.number == number)
		{
			task.status = 'D';
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Task with number " << number << " not found in list" << endl;
	}
}

void write_tasks(vector<task>* tasks, string filename)
{
	fstream file_stream(filename);
	if (file_stream.is_open())
	{
		for (const task& task : *tasks)
		{
			file_stream << task.number << " " << task.status << " " << task.description << endl;
		}
		file_stream.close();
	}
	else
	{
		cout << "ERROR: Could not open task list for writing" << endl;
	}
}

int main(int argc, char** argv)
{
	// Make sure we have a filename argument
	if (argc > 1)
	{
		vector<task>* tasks = load_file(argv[1]);

		if (tasks->size() > 0)
		{

			bool running = true;

			while (running)
			{
				cout << "----Select an option----" << endl <<
					"1. Display all items" << endl <<
					"2. Display a selected item" << endl <<
					"3. Mark a task as done" << endl <<
					"4. Exit" << endl << endl << "Selection: ";

				int option;
				cin >> option;

				switch (option)
				{
				case 1:
				{
					display_tasks(tasks);
					break;
				}
				case 2:
				{
					cout << "Task number: ";
					int number;
					cin >> number;
					display_task(tasks, number);
					break;
				}
				case 3:
				{
					cout << "Task number: ";
					int number;
					cin >> number;
					mark_task(tasks, number);
					break;
				}
				case 4:
				{
					write_tasks(tasks, argv[1]);
					running = false;
					break;
				}
				default:
				{
					cout << "Invalid option " << option << " selected." << endl;
				}
				}
			}
		}
		else
		{
			cout << "No tasks" << endl;
		}
	}
	else
	{
		cout << "No input filename!" << endl;
		return -1;
	}

	return 0;
}