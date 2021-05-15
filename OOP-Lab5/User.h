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
		//Constructor
		User();
		//add car
		virtual void add_Car(Domain::Car& car) = 0;
		//delete car
		virtual void delete_Car(Domain::Car car) = 0;
		//get a list of all cars with searched brand
		vector<Domain::Car> search_brand(string brand);
		//get a list of all cars with searched model
		vector<Domain::Car> search_model(string model);
		//get a list of all cars with given maximal km number
		vector<Domain::Car> filter_by_km(double km);
		//get a list of all cars, choice meaning filtered maximum or minimum year
		vector<Domain::Car> filter_by_year(int year, int choice);
		//get a sorted list of cars, by price 
		vector<Domain::Car> sort_by_price();

		//return the car with the specified id
		vector<Domain::Car> search_id(int id);
		//getter
		vector<Domain::Car> get_repo();
		//show list of cars
		void show_repo();
		virtual ~User()=0;



	};

}