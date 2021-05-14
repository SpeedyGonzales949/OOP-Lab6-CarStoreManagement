#include "Client.h"
using namespace ClientController;
#include <algorithm>

Client::Client(shared_ptr<Repository::Garage> repo,string username,string password) {
	this->username = std::move(username);
	this->password = std::move(password);
	this->repo = repo;
}

void Client::delete_Car(Domain::Car car)
{
	this->favorites.erase(remove(this->favorites.begin(), this->favorites.end(), car), this->favorites.end());
}

string Client::get_username()
{
	return this->username;
}

string Client::get_password()
{
	return this->password;
}

void Client::add_Car(Domain::Car& car)
{
	this->favorites.push_back(car);
}

vector<Domain::Car> Client::get_favorites() {
	return this->favorites;
}