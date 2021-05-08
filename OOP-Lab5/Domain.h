#pragma once
#include<string>
#include <iostream>


namespace Domain {
	class Car {
	private:
		std::string model, brand, fuel;
		int  registration_year;
		double km, price, performance;
	public:
		Car(std::string model, std::string brand, std::string fuel, double km, double price, double performance, int year);
		Car(const Car& car);

		std::string get_model();
		std::string get_brand();
		std::string get_fuel();
		int get_registration_year();
		double get_km();
		double get_price();
		double get_performance();


		void set_model(std::string model);
		void set_brand(std::string brand);
		void set_registration_year(int registration_year);
		void set_fuel(std::string fuel);
		void set_km(double km);
		void set_price(double price);
		void set_performamce(double performance);

		bool operator==(Car other);
		bool operator<(Car other);
		friend std::ostream& operator<<(std::ostream& os, Car& car) {
			os << car.get_brand() << " | " << car.get_model() << " | " << car.get_fuel() << " | CP: " << car.get_performance() << " | Km: " << car.get_km() <<" | Price: "<< car.get_price()<<" | Year: " <<car.get_registration_year();
			return os;
		};
		
		
		
	};
}

