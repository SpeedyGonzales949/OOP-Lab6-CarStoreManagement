#pragma once
#include <vector>
#include "Repository.h"
using namespace Repository;

namespace Controller {
	class User
	{
	protected:
		shared_ptr<Garage> repo;
		
	public:
		User();
		virtual void add_Car(Domain::Car& car)=0;
		virtual void delete_Car(Domain::Car car) = 0;
		vector<Domain::Car> search_brand(string brand);
		vector<Domain::Car> search_model(string model);
		vector<Domain::Car> filter_by_km(double km);
		vector<Domain::Car> filter_by_year(int year, int choice);
		vector<Domain::Car> sort_by_price();
		vector<Domain::Car> get_repo();

		void show_repo();
		
		
	
	};
	
}
