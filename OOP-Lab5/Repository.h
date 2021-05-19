#pragma once
#include "Domain.h"
#include <vector>
#include "Crud_Repo.h"
#include <iostream>
#include <string>
using namespace std;

namespace Repository {
	class Garage:public CrudRepository<Domain::Car>  {
	private:
		vector<Domain::Car> cars;
		int id = 0;
	public:

		//Constructor
		Garage(string file = "date.csv");
		void saveToFile();
		//assigns id to the car
		int assign_id();
		//add
		void add_Car(Domain::Car car) override;
		//delete
		void delete_Car(Domain::Car car) override;
		//update km
		void update_km(Domain::Car x, double km) override;
		//update price
		void update_price(Domain::Car x, double price) override;
		//update a car
		void update_Car(Domain::Car car, int index) override;
		//show all cars
		void show_all() override;

		//return vector of cars
		vector<Domain::Car> get_all() override;
		
		//Destructor
		~Garage();
	};

}
