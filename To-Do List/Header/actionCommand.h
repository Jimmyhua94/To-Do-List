#ifndef actionCommand_H_
#define actionCommand_H_

#include <string>
#include <vector>
#include "task.h"

using namespace std;

class actionCommand {
    public:
		explicit actionCommand();
		explicit actionCommand(vector<string>* doneCommands, vector<task*>* deletedTasks, vector<string>* redoCommands, vector<task*>* redoTasks, vector<task*>* tasks, vector<task*>* completedTasks);
		~actionCommand();
        void undo();
        void redo();
	private:
		vector<string>* doneCommands;
		vector<task*>* deletedTasks;
		vector<string>* redoCommands;
		vector<task*>* redoTasks;
		vector<task*>* tasks;
		vector<task*>* completedTasks;
};

#endif