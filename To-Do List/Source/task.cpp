#include "..\Header\task.h"

task::task()
{
	type = "Generic";
	deadLine = 0;
	desc = "";
}


task::~task()
{
}

string task::getType()
{
	return type;
}

void task::setDeadLine(int dl)
{
	deadLine = dl;
}

int task::getDeadLine()
{
	return deadLine;
}

void task::setDesc(string des)
{
	desc = des;
}

string task::getDesc()
{
	return desc;
}
