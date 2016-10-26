#ifndef managerCommand_H_
#define managerCommand_H_

#include <iostream>
#include "..\Header\taskCommand.h"

using namespace std;

class managerCommand{
    public:
		explicit managerCommand();
		explicit managerCommand(vector<task*>* tasks);
		~managerCommand();
        void save();
        void load();
        int exit();
        void help();
	private:
		vector<task*>* tasks;
};

#endif