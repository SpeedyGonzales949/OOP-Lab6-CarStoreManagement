#include "Repository.h"
#include <fstream>
#include <iostream>
using namespace Repository;
Garage::Garage(std::string file)
{

	ifstream f;
	f.open(file);

	int f_year;
	double f_km, f_price, f_performance;
	std::string f_fuel;

	while (!f.eof())
	{

		//first 2 fields (name, origin) are separated by ":" (they may have multiple words separarted by space)
		std::string x, y;
		std::string f_model, f_brand;
		f >> x;
		while (x != ":")
		{
			f_model += x;

			f >> x;
			if (x != ":")
				f_model += " ";
		}
		f >> y;
		while (y != ":")
		{
			f_brand += y;

			f >> y;
			if (y != ":")
				f_brand += " ";
		}
		//date, amount, price are separated only by one space each
		f >> f_year >> f_km >> f_fuel >> f_performance >> f_price;
		Domain::Car car(f_model, f_brand, f_fuel, f_km, f_price, f_performance, f_year,this->assign_id());
		this->cars.push_back(car); //add the product in the list
	}
	f.close();

}

vector<Domain::Car> Garage::get_all() {
	return this->cars;
}

void Garage::delete_Car(Domain::Car car) {

	this->cars.erase(remove(this->cars.begin(), this->cars.end(), car), this->cars.end());

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
