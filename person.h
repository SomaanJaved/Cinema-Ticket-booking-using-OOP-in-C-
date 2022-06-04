#pragma once
#include<iostream>
#include<string>

using namespace std;

class person {
private:
	int id;
	string name;

public:
	void assign_id(int _id);
	int return_id();
	string return_name();
	virtual void enterdata();
	virtual void showdata();
	virtual string search_(string search_type);
};

person * mov[100];
person * sho[20];
person *cus[100];
person * staff[100];

void person::assign_id(int _id) {
	id = _id;
}

int person::return_id() {
	return id;
}

string person::return_name() {
	return name;
}

void person::enterdata() {
	cout << "\n~~~~~~~~~~~~~~~~~\nEnter Information!\n~~~~~~~~~~~~~~~~~\n\n\n";
	cout << "Enter Name :";
	cin >> name;

}

void person::showdata() {
	//cout<<"Registration Time :"<<time<<endl;
	cout << "ID :" << id << endl;
	cout << "Name :" << name << endl;

}

string person::search_(string search_type) {
	if (search_type == "name")
		return name;
	//else if (search_type == "address")
		//return address;
	//else if (search_type == "bloodgroup")
		//return bloodgroup;
}