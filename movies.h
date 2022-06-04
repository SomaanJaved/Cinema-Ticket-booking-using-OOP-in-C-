#pragma once
#include<iostream>
#include<string>
#include"person.h"
using namespace std;

class movies : public person {
private: string cast;
		 string type;
		 float rating;
		 int price;
public: void enterdata();
		void showdata();
};

void movies::enterdata() {
	person::enterdata();
	cout << "Enter Cast :";
	cin >> cast;
	cout << "Enter Type :";
	cin >> type;
	cout << "Enter Rating :";
	cin >> rating;
	cout << "Enter Price: ";
	cin>>price;
}
void movies::showdata() {
	person::showdata();
	cout << "Cast :" << cast << endl;
	cout << "Type :" << type << endl;
	cout << "Rating :" << rating << endl;
	cout << "Price :" << price << endl << endl;
}