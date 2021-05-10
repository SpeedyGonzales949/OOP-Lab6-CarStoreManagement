#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Repository.h"

namespace ManagerController {

	class Manager : public Controller::User
	{
	public:
		//Constructor
		Manager(shared_ptr<Repository::Garage>repo);
		//add a new car
		void add_Car(Domain::Car& car) override;
		//delete a car
		void delete_Car(Domain::Car car) override;
		//update km from given car with new km
		void update_km(Domain::Car x, double km);
		//update price from given car with new price
		void update_price(Domain::Car x, double price);
		~Manager() { cout << "Manager Destructor" << "\n"; };
	};
}