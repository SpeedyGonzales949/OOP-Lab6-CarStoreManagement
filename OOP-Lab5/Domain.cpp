#include "Domain.h"
using namespace Domain;
Car::Car(std::string  model, std::string brand, std::string fuel, double km, double price, double performance, int year, int id, int state)
{	
	this->model = model;
	this->brand = brand;
	this->registration_year = year;
	this->fuel = fuel;
	this->km = km;
	this->price=price;
	this->performance = performance;
	this->id = id;
	this->state = state;
}

Car::Car(const Car& car) {
	this->model = car.model;
	this->brand = car.brand;
	this->fuel = car.fuel;
	this->registration_year = car.registration_year;
	this->km = car.km;
	this->price = car.price;
	this->performance = car.performance;
	this->id = car.id;
	this->state = car.state;
}
void Car::set_model(std::string model)
{
	this->model = model;
}

void Car::set_brand(std::string brand)
{
	this->brand = brand;
}

void Car::set_registration_year(int registration_year)
{
	this->registration_year = registration_year;
}

void Car::set_fuel(std::string fuel)
{
	this->fuel = fuel;
}

void Car::set_km(double km)
{
	this->km = km;
}

void Car::set_price(double price)
{
	this->price = price;
}
void Car::set_performamce(double performance)
{
	this->performance = performance;
}

void Car::set_id(int id)
{
	this->id = id;
}
void Car::set_state()
{
	this->state = 0;
}
std::string Car::get_model() {
	return this->model;
}

std::string Car::get_fuel() {
	return this->fuel;
}
std::string Car::get_brand() {
	return this->brand;
}

double Car::get_km() {
	return this->km;
}

double Car::get_price() {
	return this->price;
}

double Car::get_performance() {
	return this->performance;
}

int Car::get_registration_year() {
	return this->registration_year;
}

int Car::get_id()
{
	return this->id;
}

int Car::get_state()
{
	return this->state;
}
bool Car::operator==(Car other)
{
	if (this->brand == other.get_brand() && this->fuel == other.get_fuel() && this->km == other.get_km() && this->model == other.get_model() && this->performance == other.get_performance() && this->price == other.get_price() && this->registration_year == other.get_registration_year())
		return true;
	return false;
}

bool Car::operator<(Car other) {
	if (this->registration_year < other.get_registration_year())
		return true;
	return false;
}