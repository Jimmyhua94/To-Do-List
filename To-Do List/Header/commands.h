#ifndef commands_H_
#define commands_H_

#include <vector>
#include "task.h"
#include "taskCommand.h"
#include "actionCommand.h"
#include "managerCommand.h"

using namespace std;

class commands {
	public:
		explicit commands();
		~commands();
		taskCommand taskC;
		actionCommand actionC;
		managerCommand managerC;
	protected:
		vector<string> doneCommands;
		vector<task*> deletedTasks;
		vector<string> redoCommands;
		vector<task*> redoTasks;
		vector<task*> tasks;
		vector<task*> completedTasks;
};

#endif