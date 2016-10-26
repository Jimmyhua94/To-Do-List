#ifndef taskCommand_H_
#define taskCommand_H_

#include <vector>
#include "..\Header\task.h"

using namespace std;

class taskCommand {
    public:
		explicit taskCommand();
		explicit taskCommand(vector<task*>* tasks, vector<task*>* completedTasks, vector<string>* doneCommands, vector<string>* redoCommands, vector<task*>* deletedTasks);
		~taskCommand();
        void add(task* item);
        void remove();
        void complete();
		void print();
		void detailed();
		void completed();
	protected:
		vector<task*>* tasks;
		vector<task*>* completedTasks;
		vector<string>* doneCommands;
		vector<string>* redoCommands;
		vector<task*>* deletedTasks;
};

#endif