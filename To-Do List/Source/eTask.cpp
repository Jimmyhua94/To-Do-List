#include "..\Header\eTask.h"

eTask::eTask()
{
	type = "Event";
	deadLine = 0;
	desc = "";
	location = "";
	time = "";
}

eTask::~eTask()
{
}

void eTask::setLocation(string loc)
{
	location = loc;
}

string eTask::getLocation()
{
	return location;
}

void eTask::setTime(string tim)
{
	time = tim;
}

string eTask::getTime()
{
	return time;
}
