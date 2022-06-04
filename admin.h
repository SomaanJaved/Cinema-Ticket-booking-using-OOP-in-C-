#pragma once
#include<iostream>
#include<string>

using namespace std;

class admin {
public:
	char username[25], pass[25];
	void signup();
	void login();
	void show();
	bool operator == (admin check) {
		admin temp;
		int chk = 0;

		strcpy_s(temp.username, check.username);
		strcpy_s(temp.pass, check.pass);
		for (int i = 0; check.username[i] != '\0'; i++) {
			if (username[i] == check.username[i]) chk = 1;
			else chk = 0;
		}
		for (int i = 0; check.pass[i] != '\0'; i++) {
			if (pass[i] == check.pass[i]) chk = 1;
			else chk = 0;
		}

		if (chk == 1) return true;
		else return false;
	}
};

void admin::show() {
	cout << "\n \nUsername: ";
	cout << username;
}

void admin::signup() {
	cout << "\nEnter Username: ";
	cin >> username;
	cout << "\nEnter Password: ";
	cin >> pass;
}

void admin::login() {
	cout << "\nEnter Your Username: ";
	cin >> username;
	cout << "\nEnter Your Password: ";
	cin >> pass;
}
