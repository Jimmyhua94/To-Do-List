#include <fstream>
#include <sstream>
#include "..\Header\managerCommand.h"
#include "..\Header\task.h"
#include "..\Header\eTask.h"
#include "..\Header\hTask.h"
#include "..\Header\sTask.h"

managerCommand::managerCommand()
{
}

managerCommand::managerCommand(vector<task*>* tasks)
{
	managerCommand::tasks = tasks;
}

managerCommand::~managerCommand()
{
}

void managerCommand::save()
{
	if (tasks->size() != 0) {
		string fileName;
		cout << "Where would you like to save your incomplete tasks?" << endl;
		getline(cin, fileName, '\n');
		ofstream saveData(fileName);
		if (saveData.is_open()) {
			for (task* item : *tasks) {
				string type = item->getType();
				if (type == "Generic") {
					saveData << "G|" << item->getDeadLine() << "|" << item->getDesc() << endl;
				}
				else if (type == "Event") {
					eTask* temp = static_cast<eTask*>(item);
					saveData << "E|" << temp->getDeadLine() << "|" << temp->getDesc() << "|" << temp->getLocation() << "|" << temp->getTime() << endl;
				}
				else if (type == "Homework") {
					hTask* temp = static_cast<hTask*>(item);
					saveData << "H|" << temp->getDeadLine() << "|" << temp->getDesc() << "|" << temp->getSubject() << endl;
				}
				else if (type == "Shopping") {
					sTask* temp = static_cast<sTask*>(item);
					saveData << "S|" << temp->getDeadLine() << "|" << temp->getDesc();
					for (string sItems : temp->getItems()) {
						saveData << "|" << sItems;
					}
					saveData << endl;
				}
			}
			saveData.close();
		}
		cout << "Tasks saved successfully!" << endl;
	}
	cout << "You have no incomplete tasks!" << endl;
}

void managerCommand::load()
{
	string fileName;
	cout << "What file would you like to load incomplete tasks from?" << endl;
	getline(cin, fileName, '\n');
	string line;
	ifstream loadData(fileName);
	if (loadData.is_open()) {
		while (getline(loadData,line)) {
			stringstream ss;
			ss.str(line);
			string element;
			getline(ss, element, '|');
			if (element == "G") {
				task* tempTask = new task();
				getline(ss, element, '|');
				tempTask->setDeadLine(stoi(element));
				getline(ss, element, '|');
				tempTask->setDesc(element);
				tasks->push_back(tempTask);
			}
			else if (element == "E") {
				eTask* tempTask = new eTask();
				getline(ss, element, '|');
				tempTask->setDeadLine(stoi(element));
				getline(ss, element, '|');
				tempTask->setDesc(element);
				getline(ss, element, '|');
				tempTask->setLocation(element);
				getline(ss, element, '|');
				tempTask->setTime(element);
				tasks->push_back(tempTask);
			}
			else if (element == "H") {
				hTask* tempTask = new hTask();
				getline(ss, element, '|');
				tempTask->setDeadLine(stoi(element));
				getline(ss, element, '|');
				tempTask->setDesc(element);
				tempTask->setSubject(element);
				tasks->push_back(tempTask);
			}
			else if (element == "S") {
				sTask* tempTask = new sTask();
				getline(ss, element, '|');
				tempTask->setDeadLine(stoi(element));
				getline(ss, element, '|');
				tempTask->setDesc(element);
				while (getline(ss, element, '|')) {
					tempTask->addItems(element);
				}
				tasks->push_back(tempTask);
			}
		}
		loadData.close();
	}
	cout << "Tasks loaded successfully!" << endl;
}

int managerCommand::exit()
{
	cout << "Thank you for using To-Do List" << endl;
	return 0;
}

void managerCommand::help()
{
	cout << "ADD - Adds a new task to your To-Do list" << endl;
	cout << "PRINT - Displays your incomplete tasks succinctly" << endl;
	cout << "DETAILED - Displays your incomplete tasks with specialized task details" << endl;
	cout << "DELETE - Deletes an incomplete task" << endl;
	cout << "COMPLETE - Marks an incomplete task as complete" << endl;
	cout << "COMPLETED - Displays your completed tasks" << endl;
	cout << "UNDO - Undoes the last ADD, DELETE, or COMPLETE command" << endl;
	cout << "REDO - Redoes the last undone command" << endl;
	cout << "SAVE - Saves your incomplete tasks to a file" << endl;
	cout << "LOAD - Loads a file of incomplete tasks" << endl;
	cout << "EXIT - Exits the application immediately" << endl;
}
