#include "..\Header\sTask.h"

sTask::sTask()
{
	type = "Shopping";
	deadLine = 0;
	desc = "";
	items = list<string>();
}

sTask::~sTask()
{
}

void sTask::addItems(string it)
{
	items.push_back(it);
}

list<string> sTask::getItems()
{
	return items;
}
