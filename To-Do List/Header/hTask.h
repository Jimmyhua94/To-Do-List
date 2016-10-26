#ifndef hTask_H_
#define hTask_H_

#include <string>
#include "task.h"

using namespace std;

class hTask : public task {
	public:
		explicit hTask();
		~hTask();
		void setSubject(string sub);
		string getSubject();

	private:
		string subject;
};

#endif