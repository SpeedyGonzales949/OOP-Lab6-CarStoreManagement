#pragma once
#include "Client.h"
#include "Manager.h"
namespace UI {
	class Ui {
	private:
		vector<ClientController::Client>clients;
		ClientController::Client client;
		ManagerController::Manager manager;
		string credentials_file;
		char choice;
	public:
		//Constructor
		Ui(ManagerController::Manager& manager, string file);
		//verify if login data is stored as manager accounts
		bool login(string username, string password);
		//start app, contains two functions (client side and manager side)
		void start();
		//show Client menu options
		void show_ClientMenu();
		//show Manager menu options
		void show_ManagerMenu();
		//pick function option for client
		void pick_option_client();
		//pick function option for manager
		void pick_option_manager();
		//client menu containing all functions
		void run_ClientSide();
		//manager menu containing login verify and then all functions
		void run_ManagerSide();
		//user logins into the app
		bool login_User(string username,string password);
		//user signs up into the app
		void sign_User(string username,string password);

		//reads clientdata from file.csv
		void read_database();
		//stores clietdata to file.csv
		void update_database();

		//each function for each menu
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
	//check if introduced data is integer
	void read_integers(int& x, string input);
	//check if introduced data is double
	void read_double(double& x, string input);
	//show all cars
	void show_contents(vector<Domain::Car> cars);
}