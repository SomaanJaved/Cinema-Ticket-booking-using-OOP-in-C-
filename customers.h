#pragma once
#include<iostream>
#include<string>
#include "person.h"

using namespace std;


class customers : public person {
private: string F_Name;
		 string P_No;
		 string address;
		 
public: void enterdata();
		void showdata();
};

void customers::enterdata() {
	person::enterdata();
	cout << "Enter Father Name :";
	cin >> F_Name;
	cout << "Enter Phone Number :";
	cin >> P_No;
	cout << "Enter Address :";
	cin >> address;
	
}
void customers::showdata() {
	person::showdata();
	cout << "Father Name \n :" << F_Name << endl;
	cout << "Phone Number :" << P_No << endl;
	cout << "Address :" << address << endl;
	
}