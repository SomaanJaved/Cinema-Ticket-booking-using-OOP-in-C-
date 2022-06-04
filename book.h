#pragma once
#include<iostream>
#include<string>
#include "person.h"

class book : public person {
private: int a_num;
		 string a_time;
		 string a_customers;
		 string a_movies;
public: book() {
	a_num = 0;
}
		void make_a(string p_name, string d_name, int a_number);
		void queue();
};

book * boo[60];

void book::make_a(string p_name, string d_name, int a_number) {
	a_customers = p_name;
	a_movies = d_name;
	a_num = a_number;
}

void book::queue() {
	cout << "\nAppointment ID :" << a_num << "\tcustomers name :" << a_customers << "\tmovies name :" << a_movies << endl;
}