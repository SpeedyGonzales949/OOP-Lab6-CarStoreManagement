#pragma once
#include "Domain.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace Repository {
	class Garage {
	private:
		vector<Domain::Car> cars;
	public:

		//Constructor
		Garage(string file = "date.txt");
		//add
		void add_Car(Domain::Car car);
		//delete
		void delete_Car(Domain::Car car);
		//update km
		void update_km(Domain::Car x, double km);
		//update price
		void update_price(Domain::Car x, double price);
		//update a car
		void update_Car(Domain::Car car, int index);
		//show all cars
		void show_all();

		//return vector of cars
		vector<Domain::Car> get_all();
		//Destructor
		~Garage();
	};

}