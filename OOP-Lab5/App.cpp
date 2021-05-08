#include "Test.h"
#include "Ui.h"
#include <iostream>
int main() {
	TestAll();

	shared_ptr<Repository::Garage> garage(new Repository::Garage("date.txt"));
	ClientController::Client client = ClientController::Client(garage);
	ManagerController::Manager manager = ManagerController::Manager(garage);
	UI::Ui ui = UI::Ui(client, manager, "Login.txt");
	ui.start();
	std::cout << "Good Job!";
	return 0;
}
