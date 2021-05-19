#include "Manager.h"
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace ManagerController;
Manager::Manager(shared_ptr<Repository::Garage>repo) {
	this->repo = repo;
};
void Manager::add_Car(Domain::Car& car) {
	this->repo->add_Car(car);
	this->repo->saveToFile();
};

void Manager::delete_Car(Domain::Car car)
{
	this->repo->delete_Car(car);
	this->repo->saveToFile();
}

void Manager::update_km(Domain::Car x, double km)
{
	this->repo->update_km(x, km);
	this->repo->saveToFile();
}

void Manager::update_price(Domain::Car x, double price)
{
	this->repo->update_price(x, price);
	this->repo->saveToFile();
}
shared_ptr<Repository::Garage> ManagerController::Manager::get_full_repo()  const
{
	return this->repo;
}
