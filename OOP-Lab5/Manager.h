#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Repository.h"

namespace ManagerController {

	class Manager : public Controller::User
	{
	public:
		Manager(shared_ptr<Repository::Garage>repo);
		void add_Car(Domain::Car& car) override;
		void delete_Car(Domain::Car car) override;
		void update_km(Domain::Car x, double km);
		void update_price(Domain::Car x, double price);
		void update_Car(Domain::Car car, int index);
	};
}