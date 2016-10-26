#include "..\Header\hTask.h"

hTask::hTask()
{
	type = "Homework";
	deadLine = 0;
	desc = "";
	subject = "";
}

hTask::~hTask()
{
}

void hTask::setSubject(string sub)
{
	subject = sub;
}

string hTask::getSubject()
{
	return subject;
}
