#pragma once
#include "Client.h"
#include "Manager.h"
namespace UI {
	class Ui{
	private:
		ClientController::Client client;
		ManagerController::Manager manager;
		char choice;
	public:
		Ui(ClientController::Client& client,ManagerController::Manager& manager);
		void start();
		void show_ClientMenu();
		void show_ManagerMenu();
		void pick_option();

		void run_ClientSide();
		void run_ManagerSide();

		void option0();
		void option1();
		void option2();
		void option3();
		void option4();
		void option5();
		void option6();
		void option7();
		void option8();
		void option9();

		
	};
	void read_integers(int& x, string input);
	void read_double(double& x, string input);
	void show_contents(vector<Domain::Car> cars);
}

