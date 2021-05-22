/*
#include "Client.h"
#include "Manager.h"
#include "Test.h"
#include <assert.h>
#include <algorithm>
void testRepository() {
	Repository::Garage garage = Repository::Garage("date.csv");

	for (int i = 0; i < 100; i++) {
		auto car = Domain::Car("X6", "BMW", "Disel", i * 2, i * 3, 200 + i, 2000 + i,i,1);
		garage.add_Car(car);
		if (garage.get_all().back() == car)
			assert(true);
		else
			assert(false);
		car.set_state();
		garage.delete_Car(car);
		if (garage.get_all().back() == car)
			assert(true);
		else {

			assert(false);
		}
		
	}


	for (int i = 0; i < garage.get_all().size() - 1; i++) {
		auto car = garage.get_all()[i + 1];
		garage.update_Car(car, i);
		if (garage.get_all()[i] == garage.get_all()[i + 1])
			assert(true);
		else
			assert(false);
	}


}


void testClientController() {

	shared_ptr<Repository::Garage> garage(new Repository::Garage("date.csv"));
	ClientController::Client client = ClientController::Client(garage, "username", "parola");
	Domain::Car car = Domain::Car("Q3", "Audi", "Disel", 2, 3, 200, 2000, 0, 1);

	client.add_Car(car);
	if (client.get_favorites()[0] == car)
		assert(true);
	else
		assert(false);

	client.delete_Car(car);
	if (client.get_favorites().empty())
		assert(true);
	else
		assert(false);

	vector<Domain::Car> test;

	test = client.search_brand("BMW");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_brand() == "BMW")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = client.search_model("Octavia");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_model() == "Octavia")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = client.sort_by_price();
	if (is_sorted(test.begin(), test.end(), [](Domain::Car& car1, Domain::Car& car2) {
		if (car1.get_price() < car2.get_price())
			return true;
		else
			return false;
		}))
		assert(true);
	else
		assert(false);

	test = client.search_model("Octavia");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_model() == "Octavia")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = client.filter_by_km(500);
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_km() <= 500)
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = client.filter_by_year(2001, 1);

	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_registration_year() <= 2001)
			return true;
		else
			return false;
		}), test.end());

	if (test.empty())
		assert(true);
	else
		assert(false);

	test = client.filter_by_year(2001, -1);
	
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_registration_year() >= 2001)
			return true;
		else
			return false;
		}), test.end());
	
	if (test.empty())
		assert(true);
	else
		assert(false);
	
}

void testManagerController() {
	shared_ptr<Repository::Garage> garage(new Repository::Garage("date.csv"));
	ManagerController::Manager manager = ManagerController::Manager(garage);
	Domain::Car car = Domain::Car("Q3", "Audi", "Disel", 2, 3, 200, 2000,1,1);
	int size = manager.get_repo().size();
	manager.add_Car(car);
	assert(manager.get_repo().size() == size + 1);

	manager.delete_Car(car);
	assert(manager.get_repo()[size].get_state()==0);

	vector<Domain::Car> test;

	test = manager.search_brand("Bmw");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_brand() == "Bmw")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = manager.search_model("Passat");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_model() == "Passat")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = manager.sort_by_price();
	if (is_sorted(test.begin(), test.end(), [](Domain::Car& car1, Domain::Car& car2) {
		if (car1.get_price() < car2.get_price())
			return true;
		else
			return false;
		}))
		assert(true);
	else
		assert(false);

	test = manager.search_model("Octavia");
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_model() == "Octavia")
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = manager.filter_by_km(500);
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_km() <= 500)
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = manager.filter_by_year(2001, 1);

	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_registration_year() <= 2001)
			return true;
		else
			return false;
		}), test.end());
	if (test.empty())
		assert(true);
	else
		assert(false);

	test = manager.filter_by_year(2001, -1);
	test.erase(remove_if(test.begin(), test.end(), [](Domain::Car& car) {
		if (car.get_registration_year() >= 2001)
			return true;
		else
			return false;
		}), test.end());

	if (test.empty())
		assert(true);
	else
		assert(false);
}

int main()
{
	testRepository();
	testClientController();
	testManagerController();
	return 0;
}
*/