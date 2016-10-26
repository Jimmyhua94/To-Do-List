#include <iostream>
#include <algorithm>
#include "..\Header\eTask.h"
#include "..\Header\hTask.h"
#include "..\Header\sTask.h"
#include "..\Header\commands.h"
#include "..\Header\taskCommand.h"
#include "..\Header\actionCommand.h"
#include "..\Header\managerCommand.h"

using namespace std;

int main()
{
	commands command = commands();
	string input;
	cout << "Welcome to To-Do List, type HELP for a list of commands" << endl;
	while (1) {
		getline(cin, input, '\n');
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "EXIT") {
			return command.managerC.exit();
		}
		else if (input == "HELP") {
			command.managerC.help();
		}
		else if (input == "LOAD") {
			command.managerC.load();
		}
		else if (input == "SAVE") {
			command.managerC.save();
		}
		else if (input == "ADD") {
			string type;
			cout << "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]" << endl;
			getline(cin, type, '\n');
			std::transform(type.begin(), type.end(), type.begin(), ::toupper);
			if (type == "G") {
				task* temp = new task();
				cout << "In how many days is this task due?" << endl;
				string in;
				getline(cin, in, '\n');
				temp->setDeadLine(stoi(in));
				cout << "How would you describe this task?" << endl;
				getline(cin, in, '\n');
				temp->setDesc(in);
				command.taskC.add(temp);
			}
			else if (type == "E") {
				eTask* temp = new eTask();
				cout << "In how many days is this task due?" << endl;
				string in;
				getline(cin, in, '\n');
				temp->setDeadLine(stoi(in));
				cout << "How would you describe this task?" << endl;
				getline(cin, in, '\n');
				temp->setDesc(in);
				cout << "Where is this event taking place?" << endl;
				getline(cin, in, '\n');
				temp->setLocation(in);
				cout << "When is this event taking place?" << endl;
				getline(cin, in, '\n');
				temp->setTime(in);
				command.taskC.add(temp);
			}
			else if (type == "H") {
				hTask* temp = new hTask();
				cout << "In how many days is this task due?" << endl;
				string in;
				getline(cin, in, '\n');
				temp->setDeadLine(stoi(in));
				cout << "How would you describe this task?" << endl;
				getline(cin, in, '\n');
				temp->setDesc(in);
				cout << "What subject is this homework task for?" << endl;
				getline(cin, in, '\n');
				temp->setSubject(in);
				command.taskC.add(temp);
			}
			else if (type == "S") {
				sTask* temp = new sTask();
				cout << "In how many days is this task due?" << endl;
				string in;
				getline(cin, in, '\n');
				temp->setDeadLine(stoi(in));
				cout << "How would you describe this task?" << endl;
				getline(cin, in, '\n');
				temp->setDesc(in);
				cout << "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" << endl;
				getline(cin, in, '\n');
				std::transform(in.begin(), in.end(), in.begin(), ::toupper);
				while (in != "DONE") {
					temp->addItems(in);
					getline(cin, in, '\n');
					std::transform(in.begin(), in.end(), in.begin(), ::toupper);
				}
				command.taskC.add(temp);
			}
		}
		else if (input == "PRINT") {
			command.taskC.print();
		}
		else if (input == "DETAILED") {
			command.taskC.detailed();
		}
		else if (input == "REMOVE") {
			command.taskC.remove();
		}
		else if (input == "COMPLETE") {
			command.taskC.complete();
		}
		else if (input == "UNDO") {
			command.actionC.undo();
		}
		else if (input == "REDO") {
			command.actionC.redo();
		}
		else cout << "Invalid command! Type HELP for list of commands" << endl;
	}
	return 0;
}