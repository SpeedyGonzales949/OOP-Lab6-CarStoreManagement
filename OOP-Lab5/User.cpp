#include "User.h"
#include <algorithm>
using namespace Controller;


User::User(){}
vector<Domain::Car> User::search_brand(string brand)
{
	vector<Domain::Car> new_list = this->repo.get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[brand](Domain::Car car) {
			if (car.get_brand() != brand)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

vector<Domain::Car> User::search_model(string model)
{
	vector<Domain::Car> new_list = this->repo.get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[model](Domain::Car car) {
			if (car.get_model() != model)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

vector<Domain::Car> User::sort_by_price()
{
	vector<Domain::Car> sortedList = this->repo.get_all();
	std::sort(sortedList.begin(), sortedList.end(), [](Domain::Car& p, Domain::Car& q) {
		if (p.get_price() < q.get_price())
			return true;
		return false; });
	return sortedList;
}

vector<Domain::Car> User::filter_by_km(double km)
{
	vector<Domain::Car> new_list = this->repo.get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[km](Domain::Car car) {
			if (car.get_km() > km)
				return true;
			return false;
		}), new_list.end());
	return new_list;
}

vector<Domain::Car> User::filter_by_year(int year, int choice)
{
	vector<Domain::Car>return_vec;
	vector<Domain::Car> new_list = this->repo.get_all();
	new_list.erase(remove_if(new_list.begin(), new_list.end(),
		[year](Domain::Car car) {
			if (car.get_registration_year() > year)
				return true;
			return false;
		}), new_list.end());
	if (choice == -1) {
		vector <Domain::Car> repo = this->repo.get_all();
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
	return return_vec;
}

