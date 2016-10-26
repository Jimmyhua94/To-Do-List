#ifndef eTask_H_
#define eTask_H_

#include <string>
#include "task.h"

using namespace std;

class eTask : public task{
    public:
		explicit eTask();
		~eTask();
		void setLocation(string loc);
		string getLocation();
		void setTime(string tim);
		string getTime();
        
    private:
        string location;
		string time;
};

#endif