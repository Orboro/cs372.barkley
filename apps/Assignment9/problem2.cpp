#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Task
{
	int number;
	char status;
	std::string description;
	int priority;
};

bool comp(Task A, Task B) 
{
	return (A.priority < B.priority);
}

vector<Task>* load_file(char *filename)
{
	ifstream file_stream(filename);

	auto queue_comp = [](Task A, Task B) { return(A.priority < B.priority); };

	vector<Task>* tasks = new vector<Task>();
	std::priority_queue<Task, std::vector<Task>, decltype(queue_comp)> queue(queue_comp);

	if (file_stream.is_open())
	{
		string line;
		while (getline(file_stream, line))
		{
			std::istringstream stream(line);
			Task entry;

			std::string descAndPriority;
			if ((stream >> entry.number >> entry.status) && getline(stream, descAndPriority))
			{
				std::size_t i = descAndPriority.find_last_of(' ');
				entry.description = descAndPriority.substr(0, i);
				entry.priority = atoi(descAndPriority.substr(i + 1).c_str());
				queue.push(entry);
			}
			else
			{
				cout << "Error processing line \"" << line << "\"!" << std::endl;
				continue;
			}
		}
		
		while (!queue.empty())
		{
			tasks->push_back(queue.top());
			queue.pop();
		}

		cout << "Is heap: " << (std::is_heap(tasks->begin(), tasks->end(), comp) ? "true\n" : "false\n");
	}
	else
	{
		cout << "ERROR: could not open task list for reading." << endl;
	}


	
	return tasks;
}

inline void printTask(const Task& t)
{
	cout << t.number << "\t" << t.status << "\t" << t.priority << "\t" << t.description << endl;
}

void output(vector<Task> &tasks)
{
	cout << "-------------------------------" << endl <<
			     "Number\tStatus\tPriority  Description" << endl;
	for (const auto& t : tasks)
	{
		printTask(t);
	}
}

void displayTask(vector<Task> &tasks, int number)
{
	bool found = false;

	for (const auto& t : tasks)
	{
		if (t.number == number)
		{
			printTask(t);
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Task with number " << number << " not found in list" << endl;
	}
}

void markTask(vector<Task> &tasks, int number)
{
	bool found = false;

	for (auto& t : tasks)
	{
		if (t.number == number)
		{
			t.status = 'D';
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Task with number " << number << " not found in list" << endl;
	}
}

void changePriority(vector<Task> &tasks, int number, int newPriority)
{
	bool found = false;

	for (auto& t : tasks)
	{
		if (t.number == number)
		{
			t.priority = newPriority;

			std::make_heap(tasks.begin(), tasks.end(), comp);

			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Task with number " << number << " not found in list" << endl;
	}
}

void writeTasks(vector<Task> &tasks, string filename)
{
	fstream file_stream(filename);
	if (file_stream.is_open())
	{
		for (const Task& t : tasks)
		{
			file_stream << t.number << " " << t.status << " " << t.description << " " << t.priority << endl;
		}
		file_stream.close();
	}
	else
	{
		cout << "ERROR: Could not open task list for writing" << endl;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		vector<Task>* tasks = load_file(argv[1]);

		if (tasks->size() > 0)
		{

			bool running = true;

			while (running)
			{
				cout << "----Select an option----" << endl <<
					"1. Display all items" << endl <<
					"2. Display a selected item" << endl <<
					"3. Mark a task as done" << endl <<
					"4. Change task priority" << endl <<
					"5. Exit" << endl << endl << "Selection: ";

				int option;
				cin >> option;

				switch (option)
				{
				case 1:
				{
					output(*tasks);
					break;
				}
				case 2:
				{
					cout << "Task number: ";
					int number;
					cin >> number;
					displayTask(*tasks, number);
					break;
				}
				case 3:
				{
					cout << "Task number: ";
					int number;
					cin >> number;
					markTask(*tasks, number);
					break;
				}
				case 4:
				{
					cout << "Task number: ";
					int number;
					cin >> number;
					cout << "New priority: ";
					int newPriority;
					cin >> newPriority;
					changePriority(*tasks, number, newPriority);
					break;
				}
				case 5:
				{
					writeTasks(*tasks, argv[1]);
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