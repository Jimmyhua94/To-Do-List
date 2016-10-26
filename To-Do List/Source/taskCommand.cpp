#include <iostream>
#include "..\Header\taskCommand.h"
#include "..\Header\eTask.h"
#include "..\Header\hTask.h"
#include "..\Header\sTask.h"

using namespace std;

taskCommand::taskCommand()
{
}

taskCommand::taskCommand(vector<task*>* tasks, vector<task*>* completedTasks, vector<string>* doneCommands, vector<string>* redoCommands, vector<task*>* deletedTasks)
{
	taskCommand::tasks = tasks;
	taskCommand::completedTasks = completedTasks;
	taskCommand::doneCommands = doneCommands;
	taskCommand::redoCommands = redoCommands;
	taskCommand::deletedTasks = deletedTasks;
}

taskCommand::~taskCommand()
{
}

void taskCommand::add(task* item)
{
	redoCommands->clear();
	tasks->push_back(item);
	doneCommands->push_back("ADD");
	cout << "Task added successfully." << endl;
}

void taskCommand::remove()
{
	if (tasks->size() != 0) {
		cout << "Which task would you like to remove?" << endl;
		int item;
		string in;
		getline(cin, in, '\n');
		item = stoi(in) - 1;
		redoCommands->clear();
		deletedTasks->push_back(tasks->at(item));
		tasks->erase(tasks->begin() + item);
		doneCommands->push_back("REMOVE");
		cout << "Task removed successfully." << endl;
	}
	else cout << "You have no incomplete tasks!" << endl;
}

void taskCommand::complete()
{
	if (tasks->size() != 0) {
		cout << "Which task would you like to complete?" << endl;
		int item;
		string in;
		getline(cin, in, '\n');
		item = stoi(in) - 1;
		redoCommands->clear();
		completedTasks->push_back(tasks->at(item - 1));
		tasks->erase(tasks->begin() + item - 1);
		doneCommands->push_back("COMPLETE");
	}
	else cout << "You have no incomplete tasks!" << endl;
}

void taskCommand::print()
{
	for (int i = 0; i < tasks->size();i++) {
		task* temp = tasks->at(i);
		cout << i+1 << ". " << "(" << temp->getDeadLine();
		if (temp->getDeadLine() == 1) cout << " day from now)";
		else cout << " days from now) ";
		if (temp->getType() != "Generic") cout << "[" << temp->getType() << "] ";
		cout << temp->getDesc() << endl;
	}
}

void taskCommand::detailed()
{
	for (int i = 0; i < tasks->size(); i++) {
		task* temp = tasks->at(i);
		string type = temp->getType();
		cout << i + 1 << ". " << "(" << temp->getDeadLine();
		if (temp->getDeadLine() == 1) cout << " day from now)";
		else cout << " days from now) ";
		if (type != "Generic") cout << "[" << type << "] ";
		cout << temp->getDesc() << endl;

		if (type == "Event") {
			eTask* temp1 = static_cast<eTask*>(temp);
			cout << "\tWHERE: " << temp1->getLocation() << endl;
			cout << "\tWHEN: " << temp1->getTime() << endl;
		}
		else if (type == "Homework") {
			hTask* temp1 = static_cast<hTask*>(temp);
			cout << "\tSUBJECT: " << temp1->getSubject() << endl;
		}
		else if (type == "Shopping") {
			sTask* temp1 = static_cast<sTask*>(temp);
			cout << "\tITEMS TO PURCHASE:" << endl;
			for(string item : temp1->getItems()){
				cout << "\t" << item << endl;
			}
		}
	}
}

void taskCommand::completed()
{
	if (completedTasks->size() != 0) {
		for (int i = 0; i < completedTasks->size(); i++) {
			task* temp = completedTasks->at(i);
			cout << i + 1 << ". " << "(" << temp->getDeadLine();
			if (temp->getDeadLine() == 1) cout << " day from now)";
			else cout << " days from now) ";
			if (temp->getType() != "Generic") cout << "[" << temp->getType() << "] ";
			cout << temp->getDesc() << endl;
		}
	}
	else cout << "You have no completed tasks!" << endl;
}