
#include "Test.h"
#include "Ui.h"
#include <iostream>
int main() {
	shared_ptr<Repository::Garage> garage(new Repository::Garage("date.csv"));
	ManagerController::Manager manager = ManagerController::Manager(garage);
	UI::Ui ui = UI::Ui(manager, "Login.txt");
	ui.start();
	return 0;
}
