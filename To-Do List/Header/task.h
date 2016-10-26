#ifndef task_H_
#define task_H_

#include <string>

using namespace std;

class task {
    public:
		explicit task();
		~task();
		string getType();
		void setDeadLine(int dl);
		int getDeadLine();
		void setDesc(string des);
		string getDesc();
        
    protected:
        string type;
        int deadLine;
        string desc;
};

#endif