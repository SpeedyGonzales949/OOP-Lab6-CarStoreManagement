#include "User.h"
#include <algorithm>
using namespace Controller;


User::User() {}
vector<Domain::Car> User::search_brand(string brand,string user)
{
	vector<Domain::Car> new_list = this->repo->get_all();
	if(user=="client")
	{
		new_list.erase(remove_if(new_list.begin(), new_list.end(),
			[brand, user](Domain::Car car) {
				if (car.get_brand() != brand || car.get_state()==0)
					return true;
				return false;
			}), new_list.end());
		return new_list;
	}
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[brand,user](Domain::Car car) {
			if (car.get_brand() != brand)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

User::~User(){}
vector<Domain::Car> User::search_model(string model, string user)
{
	vector<Domain::Car> new_list = this->repo->get_all();
	if(user=="client")
	{
		new_list.erase(remove_if(new_list.begin(), new_list.end(),
			[model](Domain::Car car) {
				if (car.get_model() != model||car.get_state()==0)
					return true;
				return false;
			}), new_list.end());
		return new_list;
	}
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[model](Domain::Car car) {
			if (car.get_model() != model)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

vector<Domain::Car> User::sort_by_price( string user)
{
	vector<Domain::Car> sortedList = this->repo->get_all();
	if(user=="client")
	{
		sortedList.erase(remove_if(sortedList.begin(), sortedList.end(),
			[](Domain::Car car) {
				if (car.get_state()==0)
					return true;
				return false;
			}), sortedList.end());
	}
	std::sort(sortedList.begin(), sortedList.end(), [](Domain::Car& p, Domain::Car& q) {
		if (p.get_price() < q.get_price())
			return true;
		return false; });
	return sortedList;
}

void User::show_repo(string choice)
{
	if(choice=="client")
	{
		int ct = 1;
		for (Domain::Car car : this->repo->get_all()) {
			if(car.get_state()==1)
				cout << ct << "." << car << endl;
			ct++;
		}
		return;
	}
	int ct = 1;
	for (Domain::Car car : this->repo->get_all()) {
		cout << ct << "." << car << endl;
		ct++;
	}


}

vector<Domain::Car> User::get_repo() {
return this->repo->get_all();
}


vector<Domain::Car> User::filter_by_km(double km, string user)
{
	vector<Domain::Car> new_list = this->repo->get_all();
	if(user=="client")
	{
		new_list.erase(remove_if(new_list.begin(), new_list.end(),
			[km](Domain::Car car) {
				cout << car.get_km() << " " << km;
				if (car.get_km() > km||car.get_state()==0)
					return true;
				return false;
			}), new_list.end());
		return new_list;
	}
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[km](Domain::Car car) {
			if (car.get_km() > km)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

vector<Domain::Car> User::filter_by_year(int year, int choice, string user)
{
	vector<Domain::Car>return_vec;
	vector<Domain::Car> new_list = this->repo->get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[year](Domain::Car car) {
			if (car.get_registration_year() > year)
				return true;
			return false;
		}), new_list.end());
	if (choice == -1) {
		vector <Domain::Car> repo = this->repo->get_all();
		/*
		* sort(repo.begin(), repo.end(), [](Domain::Car& car1, Domain::Car& car2) {
			if (car1.get_registration_year() < car2.get_registration_year())
				return true;
			else
				return false;
			});
		sort(new_list.begin(), new_list.end(), [](Domain::Car& car1, Domain::Car& car2) {
			if (car1.get_registration_year() < car2.get_registration_year())
				return true;
			else
				return false;
			});
		set_difference(repo.begin(), repo.end(), new_list.begin(), new_list.end(),back_inserter(return_vec), [](Domain::Car& car1, Domain::Car& car2) {
			if (car1.get_registration_year() < car2.get_registration_year())
				return true;
			else
				return false;
			});
		*/


		sort(repo.begin(), repo.end());
		sort(new_list.begin(), new_list.end());
		set_difference(repo.begin(), repo.end(), new_list.begin(), new_list.end(), back_inserter(return_vec));



	}
	else
		return_vec = new_list;
	if(user=="client")
	{
		return_vec.erase(remove_if(return_vec.begin(), return_vec.end(),
			[](Domain::Car car) {
				if (car.get_state() == 0)
					return true;
				return false;
			}), return_vec.end());
	}
	return return_vec;
}

vector<Domain::Car> User::search_id(int id)
{
	vector<Domain::Car> new_list = this->repo->get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[id](Domain::Car car) {
			if (car.get_id() != id)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}
