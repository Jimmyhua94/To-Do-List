#include "..\Header\commands.h"

commands::commands()
{
	taskC = taskCommand(&tasks, &completedTasks, &doneCommands, &redoCommands, &deletedTasks);
	actionC = actionCommand(&doneCommands, &deletedTasks, &redoCommands, &redoTasks, &tasks,&completedTasks);
	managerC = managerCommand(&tasks);
}
commands::~commands()
{

}