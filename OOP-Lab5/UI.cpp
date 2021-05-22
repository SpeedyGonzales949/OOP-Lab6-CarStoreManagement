#include "UI.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace UI;

Ui::Ui(ManagerController::Manager& manager, string file) : client(client), manager(manager), credentials_file(file) {}

bool Ui::login(string username, string  password)
{
	ifstream f;
	f.open(credentials_file);
	string f_username, f_password;
	while (f >> f_username >> f_password)
	{
		if (username == f_username && password == f_password)
			return true;
	}
	return false;

}
void Ui::sign_User(string username,string password)
{
	
	ClientController::Client new_client = ClientController::Client(this->manager.get_full_repo(), username, password);
	this->clients.push_back(new_client);

}

bool Ui::validate_username(string username)
{
	for(int i=0;i<this->clients.size();i++)
	{
		if (this->clients[i].get_username() == username)
			return false;
	}
	return true;
}

bool Ui::login_User(string username, string password)
{
	
	auto it=std::find_if(this->clients.begin(), this->clients.end(), [username, password](ClientController::Client& client)
		{ 
			if (client.get_password() == password && client.get_username() == username)
			{
				return true;
			}
			
			return false;
		});
	
	
	if (it!=this->clients.end())
	{
		this->client = *it;
		return true;
	}
	cout << "Invalid credentials" << endl;
	return false;

}



void Ui::show_ManagerMenu() {
	system("CLS");
	cout << "Enter your option: \n";
	cout << "0. Log Out" << "\n";
	cout << "1. Add new car " << "\n";
	cout << "2. Delete car " << "\n";
	cout << "3. Search by model " << "\n";
	cout << "4. Search by brand " << "\n";
	cout << "5. Filter by km " << "\n";
	cout << "6. Filter by registration year " << "\n";
	cout << "7.  Sort by price " << "\n";
	cout << "8. Update car price" << "\n";
	cout << "9. Update car km" << "\n";
}

void Ui::show_ClientMenu() {
	system("CLS");
	cout << "Enter your option: \n";
	cout << "0. Log Out" << "\n";
	cout << "1. Add new car " << "\n";
	cout << "2. Delete car " << "\n";
	cout << "3. Search by model " << "\n";
	cout << "4. Search by brand " << "\n";
	cout << "5. Filter by km " << "\n";
	cout << "6. Filter by registration year " << "\n";
	cout << "7.  Sort by price " << "\n";
	cout << "8. List favorites cars " << "\n";
}
void Ui::pick_option_client() {
	string option;
	char op;
	do
	{
		cout << "Option: ", cin >> option;
	} while (option < "0" || option>"8" || this->validate_number(option)==0);
	op = option[0];
	switch (op) {
	case '0': {system("CLS");  this->choice = 0; break; }
	case '1': {system("CLS"); option1(); system("pause"); break; }
	case '2': {system("CLS"); option2(); system("pause"); break; }
	case '3': {system("CLS"); option3(); system("pause"); break; }
	case '4': {system("CLS"); option4(); system("pause"); break; }
	case '5': {system("CLS"); option5(); system("pause"); break; }
	case '6': {system("CLS"); option6(); system("pause"); break; }
	case '7': {system("CLS"); option7(); system("pause"); break; }
	case '8': {system("CLS"); option8(); system("pause"); break; }
	}
}

void Ui::pick_option_manager() {
	string option;
	char op;
	do
	{
		cout << "Option: ", cin >> option;
	} while (option < "0" || option>"9" || this->validate_number(option)==0);
	op = option[0];
	switch (op) {
	case '0': {system("CLS"); this->choice = 0; break; }
	case '1': {system("CLS"); option1(); system("pause"); break; }
	case '2': {system("CLS"); option2(); system("pause"); break; }
	case '3': {system("CLS"); option3(); system("pause"); break; }
	case '4': {system("CLS"); option4(); system("pause"); break; }
	case '5': {system("CLS"); option5(); system("pause"); break; }
	case '6': {system("CLS"); option6(); system("pause"); break; }
	case '7': {system("CLS"); option7(); system("pause"); break; }
	case '8': {system("CLS"); option8(); system("pause"); break; }
	case '9': {system("CLS"); option9(); system("pause"); break; }
	}
}

void Ui::option1() {
	if (this->choice == '2')
	{
		this->client.show_repo("client");
		int option;
		read_integers(option, "Which car would you like to add to your favorites list? CarNr:");
		if (option > 0 && option <= this->client.sort_by_price().size()&&this->client.get_repo()[option-1].get_state()==1)
		{
			this->client.add_Car(this->client.get_repo().at(option - 1));
			this->update_database();
		}
			
		else
			cout << "!!Error 404!!" << endl;
	}
	else
	{
		string input, brand, model, fuel;
		double km, price, performance;
		int year;

		cout << "Enter the new car specifications:\n";
		cout << "Brand: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, brand);
		cout << "\n";
		cout << "Model: ";

		getline(cin, model);
		cout << "\n";
		cout << "Fuel type: ";

		getline(cin, fuel);
		cout << "\n";
		UI::read_double(km, "Km: ");
		cout << "\n";
		input = "Registration year: ";
		UI::read_integers(year, input);
		cout << "\n";
		input = "Performance: ";
		UI::read_double(performance, input);
		cout << "\n";
		input = "New price: ";
		UI::read_double(price, input);
		cout << "\n";
		int new_id = this->manager.get_repo().size();
		Domain::Car new_car = Domain::Car(model, brand, fuel, km, price, performance, year, new_id,1);
		this->manager.add_Car(new_car);
	}

}

void Ui::option2() {
	if (choice == '2') {
		for (Domain::Car car : this->client.get_favorites()) {
			cout << car << endl;
		}
		int option;
		read_integers(option, "Which car would you like to delete to your favorites list? CarNr:");
		if (option > 0 && option <= this->client.get_favorites().size())
		{
			this->client.delete_Car(this->client.get_favorites().at(option - 1));
			this->update_database();
		}
			
		else
			cout << "!!Error 404!!" << endl;
	}
	else
	{
		string input;
		system("CLS");
		int position;
		char answear;
		this->manager.show_repo();
		cout << "\n";
		input = "Enter the number of the car you want to delete: ";
		UI::read_integers(position, input);

		if (position > 0 && position <= this->manager.get_repo().size())
		{
			cout << "Are you sure you want to delete the car " << position << " ? (Y/N): ";
			cin >> answear;
			if (answear == 'Y')
			{
				Domain::Car deleted = this->manager.get_repo()[position - 1];
				this->manager.delete_Car(deleted);
				cout << "\n";
			}
		}
		else
		{
			cout << "Position not valid.\n";
		}
	}
}

void Ui::option3() {
	string model;
	cout << "Searched Model: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, model);
	vector<Domain::Car> list;
	if(this->choice=='2')
		list = this->client.search_model(model,"client");
	else
		list = this->manager.search_model(model);
	if (list.size() == 0)
	{
		cout << "The searched model was not found ";
	}
	else
	{
		for (int i = 0; i < list.size(); i++)
			cout << list[i] << "\n";
	}

}
void Ui::option4() {
	string brand;
	cout << "Searched Brand: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, brand);
	vector<Domain::Car> list;
	if (this->choice == '2')
	{
		 list = this->client.search_brand(brand,"client");
	}
	else
	{
		 list = this->manager.search_brand(brand);
	}
	if (list.size() == 0)
	{
		cout << "The searched model was not found ";
	}
	else
	{
		show_contents(list);
	}
}

void Ui::option5() {
	string input;
	double km;
	input = "Maximal Km : ";
	UI::read_double(km, input);
	cout << "\n";
	cout << "FILTERED LIST: \n";
	vector<Domain::Car> list;
	if (this->choice == '2')
		list=this->client.filter_by_km(km,"client");
	else
		list=this->manager.filter_by_km(km);
	if (list.size() == 0)
	{
		cout << "Km too low" << endl;
	}
	else
	{
		show_contents(list);
	}
}
void Ui::option6() {
	string input;
	int year;
	int choice;
	input = "Maximal Registration year: ";
	UI::read_integers(year, input);
	cout << "\n";
	UI::read_integers(choice, "Choice (-1 for reverse filtering):");
	cout << "FILTERED LIST: \n";
	vector<Domain::Car> list;
	if(this->choice=='2')
		list=this->client.filter_by_year(year, choice, "client");
	else
		list= this->manager.filter_by_year(year, choice);
	if (list.size() == 0)
	{
		cout << "There is no car with that specification";
	}
	else
	{
		show_contents(list);
	}
}

void Ui::option7() {
	cout << "SORTED LIST BY PRICE: \n";
	vector<Domain::Car> list;
	if(this->choice=='2')
		list= this->client.sort_by_price("client");
	else
		list = this->manager.sort_by_price();
	show_contents(list);
}
void Ui::option8() {
	if (this->choice == '2')
	{
		cout << "<3:";
		vector<Domain::Car>list = this->client.get_favorites();
		show_contents(list);
	}
	else
	{
		string input;
		int position;
		double price;
		this->manager.show_repo();
		cout << "\n";
		input = "Enter the number of the car you want to update: ";
		UI::read_integers(position, input);
		if (position > 0 && position <= this->manager.get_repo().size())
		{
			Domain::Car updated = this->manager.get_repo()[position - 1];
			input = "New Price: ";
			UI::read_double(price, input);
			this->manager.update_price(updated, price);
			cout << "\n";
		}
		else
		{
			cout << "Position not valid.\n";
		}
	}

}

void Ui::option9()
{
	int position;
	double km;
	this->manager.show_repo();
	cout << "\n";
	string input = "Enter the number of the car you want to update: ";
	UI::read_integers(position, input);
	if (position > 0 && position <= this->manager.get_repo().size())
	{
		Domain::Car updated = this->manager.get_repo()[position - 1];
		input = "New Km: ";
		UI::read_double(km, input);
		this->manager.update_km(updated, km);
		cout << "\n";
	}
	else
	{
		cout << "Position not valid.\n";
	}
}

void Ui::start() {


	string option;
	char op;
	do
	{
		this->read_database();
		cout << "Press: " << endl;
		cout << " -------- 1 - Manager --------" << endl;
		cout << " -------- 2 - Client --------" << endl;
		cout << " -------- 0 - Exit App --------" << endl;
		do {
			cout << "Option: ", cin >> option;
			

		} while (option != "1" && option != "2" && option != "0" && this->validate_number(option)==0);
		op = option[0];
		this->choice = op;
		switch (op) {
		case '1':
		{	run_ManagerSide();
		break;
		}
		case '2':
		{	run_ClientSide();
		break;
		}
		case '0':
			exit(0);
		}
	} while (op != '0');
	//exit(0);
}

void Ui::run_ClientSide() {
	system("CLS");
	bool end = true;
	do
	{
		string option;
		bool invalid = true;
		system("cls");
		do
		{
			
			cout << "Press: " << endl;
			cout << "-------- 1 - Login --------" << endl;
			cout << "-------- 2 - Create new account --------" << endl;
			cout << "Option:";
			cin >> option;
			cout << endl;
			if (option == "1" || option == "2")
				invalid = false;
			else
				cout << "Invalid option! Try again!" << endl;
		}
		while (invalid);

		
		system("cls");
		if(option=="1")
			cout << "-------- Log In --------" << endl;
		else
			cout << "-------- Sign Up --------" << endl;
		string user, pass;
		cout << "Enter Username:";
		cin >> user;
		cout << "Enter Password:";
		cin >> pass;

		if (option == "2")
		{
			if(this->validate_username(user))
			{
				this->sign_User(user, pass);
				this->update_database();
				
			}
			else
			{
				cout << "Username already exists! Plsease try again!" << endl;
			}
			system("pause");
			
		}
			
		else
		{
			if (this->login_User(user, pass))
				end = false;
			else
			{
				system("pause");
			}
		}
		
			
	}
	while (end);
	
	while (this->choice!=0) {
		show_ClientMenu();
		pick_option_client();
	}

}


void Ui::run_ManagerSide() {
	string username, password;
	int ok = 1;
	do {
		system("cls");

		cout << "-------- Authentication--------" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		char op;
		if (login(username, password) == true)
		{
			ok = 1;
			while (this->choice!=0) {
				show_ManagerMenu();
				pick_option_manager();
			}
			if (this->choice == 0)
				ok = 1;
		}
		else
		{
			cout << "Incorrect username or password! Choose an option:" << endl;
			cout << "1. Try again" << endl;
			cout << "0. Exit" << endl;
			cin >> op;
			if (op != '1')
				ok = 1;
			else
				ok = 0;
		}

	} while (ok == 0);
}


void UI::read_integers(int& x, string msg) {
	string option;
	int ct = 0;
	while (ct == 0) {
		try {
			cout << msg;
			cin >> option;
			x = stoi(option);
			ct = 1;
		}
		catch (exception& ex) {
			cout << "Please enter a number!" << endl;
		}
	}
}

void UI::read_double(double& x, string msg) {
	string option;
	int ct = 0;
	while (ct == 0) {
		try {
			cout << msg;
			cin >> option;
			x = stod(option);
			ct = 1;
		}
		catch (exception& ex) {
			cout << "Please enter a number!" << endl;
		}
	}
}

void UI::show_contents(vector<Domain::Car> cars) {
	for (Domain::Car car : cars)
		cout << car << endl;
}

void Ui::update_database()
{
	fstream file;
	file.open("clients-data.csv");
	for(ClientController::Client client:this->clients)
	{
		file << client.get_username() << "," << client.get_password() << ",";
		if(client.get_username()==this->client.get_username()&&this->client.get_password()==client.get_password())
		{
			for (Domain::Car car : this->client.get_favorites())
			{
			
				file << car.get_id() << ",";
			}
			
		}
		else
		{
			for (Domain::Car car : client.get_favorites())
			{
				
				file << car.get_id() << ",";
			}
		}
	
		file << "\n";
	}
	file.close();
	
}

void Ui::read_database()
{
	fstream file;
	file.open("clients-data.csv", ios::in);
	vector<string>row;
	string line, word;

	while(!file.eof())
	{
		row.clear();
		getline(file, line);
		if(!line.empty())
		{
			stringstream s(line);
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}

			ClientController::Client new_client = ClientController::Client(this->manager.get_full_repo(), row[0], row[1]);
			for (int i = 2; i < row.size(); i++)
			{

				Domain::Car new_car = new_client.search_id(stoi(row[i]))[0];
				new_client.add_Car(new_car);
			}
			this->clients.push_back(new_client);

		}
		
		
	}
	file.close();
	
}

bool Ui::validate_number(string input) {
	if (input.size() >1)
		return false;
	if (isdigit(input[0]) == false) //not a digit
		return false;
	
	return true;
}