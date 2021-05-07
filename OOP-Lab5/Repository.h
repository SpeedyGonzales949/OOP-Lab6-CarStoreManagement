#pragma once
#include "Domain.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace Repository {
	class Garage {
	private:
		vector<Domain::Car> cars;
	public:
	Garage(string file="date.txt");
	void add_Car(Domain::Car car);
	void delete_Car(Domain::Car car);
	void update_Car(Domain::Car car,int index);
	void update_km(Domain::Car x, double km);
	void update_price(Domain::Car x, double price);
	void show_all();
	vector<Domain::Car> get_all();
	~Garage();
	};
	
}