#pragma once
#include <vector>
#include "Repository.h"
using namespace Repository;

namespace Controller {
	class User
	{
	protected:
		Garage repo;
	public:
		User();
		virtual void add_Car(Domain::Car& e)=0;
		virtual void delete_Car(Domain::Car e) = 0;
		vector<Domain::Car> search_brand(string brand);
		vector<Domain::Car> search_model(string model);
		vector<Domain::Car> filter_by_km(double km);
		vector<Domain::Car> filter_by_year(int year, int choice);
		vector<Domain::Car> sort_by_price();
	
	};
}
