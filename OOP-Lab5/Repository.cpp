#include "Repository.h"
#include <fstream>
#include <iostream>
using namespace Repository;
Garage::Garage(std::string file)
{
	//0,Modell,Marke,Erstzulassungsjahr,Kilometer,Preis,Leistung,Treibstoff
	ifstream f;
	f.open(file, ios::in);

	vector<string> row;
	string line, word, field;
	
	while (f>>line) {
		row.clear();

		//getline(f, line);
		stringstream s(line);
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
		//cout << row[8] << stoi(row[8]);
		Domain::Car new_car(row[1],row[2],row[7], stod(row[4]), stod(row[5]), stod(row[6]), stoi(row[3]), stoi(row[0]), stoi(row[8]));
		this->cars.push_back(new_car);
	}
	f.close();
}

void Garage::saveToFile()
{
	ofstream g;
	string file = "date.csv";
	g.open("date.csv", ios::out);

	for (int i = 0; i < this->cars.size(); i++)
	{
		g << this->cars[i].get_id() << ',' <<
			this->cars[i].get_brand() << ',' <<
			this->cars[i].get_model() << ',' <<
			this->cars[i].get_registration_year() << ',' <<
			this->cars[i].get_km() << ',' <<
			this->cars[i].get_price() << ',' <<
			this->cars[i].get_performance() << ',' <<
			this->cars[i].get_fuel() << ',' <<
			this->cars[i].get_state() << endl;
	}

	g.close();
}

vector<Domain::Car> Garage::get_all() {
	return this->cars;
}

void Garage::delete_Car(Domain::Car& car) {
	for(int i=0;i<this->get_all().size();i++)
	{
		if(this->get_all()[i]==car)
		{
			cout << "aici";
			this->get_all()[i].set_state(0);
		}
	}
}

void Garage::add_Car(Domain::Car car) {
	this->cars.push_back(car);
}

void Garage::update_Car(Domain::Car car, int index) {
	this->cars[index] = car;
}

void Garage::show_all() {
	for (int i = 0; i < this->cars.size(); i++)
		cout << this->cars[i] << "\n";
}

Garage::~Garage() {
	this->cars.clear();
	this->cars.shrink_to_fit();
}

void Garage::update_km(Domain::Car x, double km)
{
	for (int i = 0; i < this->cars.size(); i++)
		if (this->cars[i] == x)
		{
			this->cars[i].set_km(km);
		}
}

void Repository::Garage::update_price(Domain::Car x, double price)
{
	for (int i = 0; i < this->cars.size(); i++)
		if (this->cars[i] == x)
		{
			this->cars[i].set_price(price);
		}
}
int Garage::assign_id()
{
	return this->id++;
}
