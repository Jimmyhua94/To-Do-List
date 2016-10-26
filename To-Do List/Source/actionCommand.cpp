#include <iostream>
#include <algorithm>
#include "..\Header\actionCommand.h"

using namespace std;

actionCommand::actionCommand()
{
}

actionCommand::actionCommand(vector<string>* doneCommands, vector<task*>* deletedTasks, vector<string>* redoCommands, vector<task*>* redoTasks, vector<task*>* tasks, vector<task*>* completedTasks)
{
	actionCommand::doneCommands = doneCommands;
	actionCommand::deletedTasks = deletedTasks;
	actionCommand::redoCommands = redoCommands;
	actionCommand::redoTasks = redoTasks;
	actionCommand::tasks = tasks;
	actionCommand::completedTasks = completedTasks;
}

actionCommand::~actionCommand()
{
}

void actionCommand::undo()
{
	if (doneCommands->size() != 0) {
		string command = doneCommands->back();
		if (command == "ADD") {
			redoTasks->push_back(tasks->back());
			tasks->pop_back();
			redoCommands->push_back("ADD");
			cout << "ADD command undone successfully." << endl;
		}
		else if (command == "REMOVE") {
			tasks->push_back(deletedTasks->back());
			deletedTasks->pop_back();
			redoCommands->push_back("REMOVE");
			cout << "REMOVE command undone successfully." << endl;
		}
		else if (command == "COMPLETE") {
			tasks->push_back(completedTasks->back());
			completedTasks->pop_back();
			redoCommands->push_back("COMPLETE");
			cout << "COMPLETE command undone successfully." << endl;
		}
		doneCommands->pop_back();
	}
	else {
		cout << "You have no commands to undo!" << endl;
	}
}

void actionCommand::redo()
{
	if (redoCommands->size() != 0) {
		string command = redoCommands->back();
		if (command == "ADD") {
			tasks->push_back(redoTasks->back());
			redoTasks->pop_back();
			doneCommands->push_back("ADD");
			cout << "ADD command redone successfully." << endl;
		}
		else if (command == "REMOVE") {
			deletedTasks->push_back(tasks->back());
			tasks->pop_back();
			doneCommands->push_back("REMOVE");
			cout << "REMOVE command redone successfully." << endl;
		}
		else if (command == "COMPLETE") {
			completedTasks->push_back(tasks->back());
			tasks->pop_back();
			doneCommands->push_back("COMPLETE");
			cout << "COMPLETE command redone successfully." << endl;
		}
		redoCommands->pop_back();
	}
	else {
		cout << "You have no commands to redo!" << endl;
	}
}
