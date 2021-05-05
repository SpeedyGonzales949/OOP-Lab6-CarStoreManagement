#include "UI.h"
using namespace UI;

Ui::Ui(ClientController::Client& client): client(client){}

void Ui::show_ClientMenu() {
		system("CLS");
		cout << "Enter your option: \n";
		cout << "0. Exit Menu" << "\n";
		cout << "1. Add new car " << "\n";
		cout << "2. Delete car " << "\n";
		cout << "3. Search by model " << "\n";
		cout << "4. Search by brand " << "\n";
		cout << "5. Filter by km " << "\n";
		cout << "6. Filter by registration year " << "\n";
		cout << "7.  Sort by price " << "\n";
		cout << "8. List favorites cars " << "\n";
}

void Ui::pick_option() {
	char option;
	do
	{
	cout << "Option: ", cin >> option;
	} while (option < '0' || option>'9');

	switch (option) {
	case '0': {system("CLS"); option0(); system("pause"); break; }
	case '1': {system("CLS"); option1(); system("pause"); break; }
	case '2': {system("CLS"); option2(); system("pause"); break; }
	case '3': {system("CLS"); option3(); system("pause"); break; }
	case '4': {system("CLS"); option4(); system("pause"); break; }
	case '5': {system("CLS"); option5(); system("pause"); break; }
	case '6': {system("CLS"); option6(); system("pause"); break; }
	case '7': {system("CLS"); option7(); system("pause"); break; }
	case '8': {system("CLS"); option8(); system("pause"); break; }
	//case '9': {system("CLS"); option9(); system("pause"); break; }
	}
}

void Ui::option0() {
	exit(0);
}

void Ui::option1() {
	this->client.show_repo();
	int option;
	read_integers(option, "Which car would you like to add to your favorites list? CarNr:");
	if (option > 0 && option <= this->client.sort_by_price().size())
		this->client.add_Car(this->client.get_repo().at(option-1));
	else
		cout << "!!Error 404!!" << endl;
}

void Ui::option2() {
	for (Domain::Car car : this->client.get_favorites()) {
		cout<< car << endl;
	}
	int option;
	read_integers(option, "Which car would you like to delete to your favorites list? CarNr:");
	if (option > 0 && option <= this->client.get_favorites().size())
		this->client.delete_Car(this->client.get_favorites().at(option-1));
	else
		cout << "!!Error 404!!" << endl;
	
}

void Ui::option3() {
	string model;
	cout << "Searched Model: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, model);
	vector<Domain::Car> list = this->client.search_model(model);
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
	vector<Domain::Car> list = this->client.search_brand(brand);
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
	vector<Domain::Car> list = this->client.filter_by_km(km);
	if (list.size() == 0)
	{
		cout << "Km too low";
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
	vector<Domain::Car> list=this->client.filter_by_year(year,choice);
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
	vector<Domain::Car> list = this->client.sort_by_price();
	show_contents(list);
}
void Ui::option8() {
	cout << "<3:";
	vector<Domain::Car>list = this->client.get_favorites();
	show_contents(list);
}


void Ui::start() {
	cout << "Press 1 for Manager or 2 for Client" << endl;
	char option;
	do{
		cout << "Option: ", cin >> option;
	} while (option != '1' && option!='2');

	if (option == '2')
		run_ClientSide();
	else
		cout << "Wrong option \n";

}

void Ui::run_ClientSide() {
	while (1) {
		show_ClientMenu();
		pick_option();
	}
		
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