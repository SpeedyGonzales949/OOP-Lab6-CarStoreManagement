#pragma once
#include "User.h"
#include "Repository.h"

namespace ClientController {
	class Client :public Controller::User {
	private:
		vector<Domain::Car> favorites;
	public:
		//Constructor
		Client(shared_ptr<Repository::Garage> repo);
		//add car to favorites list
		void add_Car(Domain::Car& car) override;
		//delete car from favorites list
		void delete_Car(Domain::Car car) override;
		//getter
		vector<Domain::Car> get_favorites();

	};
}