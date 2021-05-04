#pragma once
#include "User.h"
#include "Repository.h"

namespace ClientController {
	class Client :public Controller::User {
	private:
		vector<Domain::Car> favorites;
	public:
		Client(Repository::Garage& repo);
		void add_Car(Domain::Car& car) override ;
		void delete_Car(Domain::Car car) override;
		vector<Domain::Car> get_favorites();
	
	};
}


