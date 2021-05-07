#include "Client.h"
using namespace ClientController;
#include <algorithm>

Client::Client(shared_ptr<Repository::Garage> repo){
	this->repo = repo;
}

void Client::delete_Car(Domain::Car car) 
{
	this->favorites.erase(remove(this->favorites.begin(), this->favorites.end(), car),this->favorites.end());
}

void Client::add_Car(Domain::Car& car) 
{
	this->favorites.push_back(car);
}

vector<Domain::Car> Client::get_favorites() {
	return this->favorites;
}
