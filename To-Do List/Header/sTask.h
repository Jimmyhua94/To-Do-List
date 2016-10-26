#ifndef sTask_H_
#define sTask_H_

#include <string>
#include <list>
#include "task.h"

using namespace std;

class sTask : public task{
    public:
		explicit sTask();
		~sTask();
		void addItems(string it);
		list<string> getItems();
        
    private:
        list<string> items;
};

#endif