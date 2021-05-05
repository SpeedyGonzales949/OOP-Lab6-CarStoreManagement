#include "Test.h"
#include "Ui.h"
#include <iostream>
int main() {
	TestAll();

	Repository::Garage garage = Repository::Garage("date.txt");
	ClientController::Client client = ClientController::Client(garage);
	UI::Ui ui = UI::Ui(client);
	ui.start();
	std::cout << "Good Job!";
	return 0;
}