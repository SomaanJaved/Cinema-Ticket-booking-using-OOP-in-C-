/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					
					Cinema Booking Ticket Managment
 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//*********************** Cinema Ticket Managment System ***********************//
#include < iomanip > 
#include < iostream > 
#include < string > 
#include < conio.h > 
#include < fstream > 
#include < cstdlib >
#include "person.h"
#include "movies.h"
#include "book.h"
#include "admin.h"
#include "shows.h"
#include "customers.h"


using namespace std;

const int max_movies = 100;
const int max_shows = 20;
const int max_customer = 100;
const int max_book = 60;

int m_m = 0, m_s = 0, m_c = 0, m_b = 0;


//person
//Movies
//shows


//customers

//book

//admin




//---------STYLE---------
void main_style();
//-----------------------

//----------------------
void intin(int & x);
bool login_s();
void add();
void edit();
void display();
void search();
void admin_s();
void view();
void book_list();

//----------------------

int main() {
login: main_style(); // Project Name
	if (login_s() == true) {
	menu: main_style();
		cout << "\n~~~~~~~~~\nMain menu\n~~~~~~~~~\n\n\n"
			<< "1) Admin\n" << "2) book\n"
			<< "3) Queue\n" << "4) Records\n"
			<< "5) Exit\n" << "\n\n<PERSS 'E' TO LOGOUT>";
		switch (_getche()) {
		case 'e':
			system("cls");
			goto login;
		case '1':
			system("cls");
			admin_s();
			system("cls");
			goto menu;
			break;
		case '2':
			system("cls");
			book_list();
			system("cls");
			goto menu;
			break;
		case '3':
		{
			system("cls");
			if (m_b > 0) {
				for (int c = 0; c < m_b; c++) {
					boo[c]->queue();
				}
			}
			else
				cout << "\nNo Booking Made yet!\n";
			system("pause");
			system("cls");
			goto menu;
			break;
		}
		case '4':
		{
			system("cls");
			view();
			system("pause");
			system("cls");
			goto menu;
			break;
		}
		
		default:
		{
			cout << "Invalid option";
			system("cls");
			goto menu;
		}

		}
	}
	else
		cout << "\nPlease Login First!\n";
	goto menu;
end: system("pause");
}

//~~~~~~~~~~~~~~~STYLE~~~~~~~~~~~~~~~~~~~~
void main_style() {
	cout << setfill('~') << setw(110) << "" << endl;
	cout << setfill(' ') << setw(70) << "Cinema Ticket Booking System\n";
	cout << setfill('~') << setw(110) << "" << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//****************Functions***********************//
void intin(int & x) {
	while (true) {
		cin >> x;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Incorrect input\n";
		cin.ignore(10, '\n');
	}
}

bool login_s() {
	admin a, chk;
	fstream file;
	int users = 0;
	int check = 0;
	int kick = 0;

	//~~~~~~~~~~~~~~~~~~~~~~~OPENFILE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	file.open("login.txt", ios::app | ios::out | ios::in | ios::binary);
	if (!file) {
		cerr << "Could not open log file\n";
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//~~~~~~~~~~~~~~~~~~~~~~~Users Counter~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	//file.seekg(0); //reset to start of file
	file.seekg(0, ios::end); //go to 0 bytes from end
	int endposition = file.tellg(); //where we are
	int x = (endposition / sizeof(a)); //number of users
	users = x;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

start:
	cout << setfill(' ') << setw(60) << "~~~~~~~~~~~~~~~~" << endl;
	cout << setfill(' ') << setw(60) << "Control Panel\n";
	cout << setfill(' ') << setw(60) << "~~~~~~~~~~~~~~~~" << endl;

	cout << setfill(' ') << setw(55) << "1: Signup\n" << setfill(' ') << setw(54) << "2: Login\n" << setfill(' ') << setw(70) << "3: View Registered Users\n";

	switch (_getch()) {

	case '1':
		system("cls");
		cout << "~~~~~~~~~~~~~~~~~~\nSignup New Account\n~~~~~~~~~~~~~~~~~~";
		a.signup();
		file.write(reinterpret_cast <char *> (&a), sizeof(a));
		file.close();
		cout << "\nYou are successfully Signedup!\n";
		users++;
		system("pause");
		system("cls");
		main_style();
		goto start;
		break;

	case '2':
		system("cls");
		if (users <= 0) {
			system("cls");
			cout << "\n\nPlease Signup first!\n";
			system("pause");
			system("cls");
			main_style();
			goto start;
		}
		cout << "~~~~~~~~~~~~~~~~~~\nLogin Your Account\n~~~~~~~~~~~~~~~~~~";
	st:
		chk.login();
		file.seekg(0);
		file.read(reinterpret_cast <char *> (&a), sizeof(a));
		while (!file.eof()) {
			//if(a.check(a,chk)==true){
			if (a == chk == true) {
				check = 1;
				cout << "\nYou have Successfully Logedin!\n";
				system("pause");
				system("cls");
				return true;
				break;
			}
			else
				kick++;
			cout << endl << "Incorrect username or Password " << kick << " Attempt!";
			if (kick > 5) {
				kick = 0;
				system("cls");
				cout << "\nYou are failed to login\n";
				system("pause");
				system("cls");
				goto start;
			}
			goto st;
		}

		break;

	case '3':
		system("cls");
		do {
			system("cls");
			file.seekg(0); //reset to start of file
			file.seekg(0, ios::end); //go to 0 bytes from end
			int endposition = file.tellg(); //where we are
			int x = (endposition / sizeof(a)); //number of users
			cout << "~~~~~~~~~~~~~~~~~~\nRegistered Accounts\n~~~~~~~~~~~~~~~~~~";
			cout << "\n\nNumber of Accounts :" << x;
			file.seekg(0);
			int n;
			cout << "\nEnter user index to search: ";
			intin(n);
			if (n > x || n <= 0) {
				cout << "\nNo User exist at this index!\n";
				goto start;
			}
			int position = (n - 1) * sizeof(a); //number times size
			file.seekg(position); //bytes from start
			file.read(reinterpret_cast <char *> (&a), sizeof(a));
			a.show(); //display the person
			cout << "\nDo you want to search more users! (y/n)\n";
		} while (_getch() == 'y');
		system("cls");
		main_style();
		goto start;
		break;

	default:
	{
		cout << "\nInvalid input!\n";
		system("cls");
		main_style();
		goto start;
	}
	}

}

void add() {
start: cout << "\n~~~~~~~~~~\nAdmin menu\n~~~~~~~~~~\n";
	cout << "1) Add Moviess\n";
	cout << "2) Add Shows\n";
	cout << "3) Add Customerss\n";
	cout << "b) Previous menu\n";
	switch (_getche()) {
	case '1':
	{
		system("cls");
		for (int c = 0; c < max_movies; c++) {
			system("cls");
			mov[c] = new movies;
			mov[c]->assign_id(m_m);
			mov[c]->enterdata();
			m_m++;
			cout << endl << m_m << " Records added Successfully!\n";
			cout << "\nDo you want to add more records!\n (Press Y to continue!)";
			if (_getch() == 'y')
				continue;
			else {
				system("cls");
				break;
			}

		}
		system("cls");
		goto start;
		break;
	}
	case '2':
	{
		system("cls");
		for (int c = 0; c < max_shows; c++) {
			system("cls");
			sho[c] = new shows;
			sho[c]->assign_id(m_s);
			sho[c]->enterdata();
			m_s++;
			cout << endl << m_s << " Records added Successfully!\n";
			cout << "\nDo you want to add more records!\n (Press Y to continue!)";
			if (_getche() == 'y')
				continue;
			else {
				system("cls");
				break;
			}

		}
		system("cls");
		goto start;
		break;
	}
	case '3':
	{
		system("cls");
		for (int c = 0; c < max_customer; c++) {
			system("cls");
			cus[c] = new customers;
			cus[c]->assign_id(m_c);
			cus[c]->enterdata();
			m_c++;
			cout << endl << m_c << " Records added Successfully!\n";
			cout << "\nDo you want to add more records!\n (Press Y to continue!)";
			if (_getche() == 'y')
				continue;
			else {
				system("cls");
				break;
			}

		}
		system("cls");
		goto start;
		break;
	}
	case 'b':
	{
		break;
	}
	default:
	{
		cout << "Invalid Input";
		system("cls");
		goto start;
	}

	}
}

void edit() {
	int id;
start:
	cout << "\n~~~~~~~~~~\nAdmin menu\n~~~~~~~~~~\n";
	cout << "1) Edit Movies Record\n";
	cout << "2) Edit Shows Record\n";
	cout << "3) Edit Customers Record\n";
	cout << "b) Previous menu\n";
	switch (_getche()) {
	case '1':
	{
		system("cls");
		if (m_m > 0) {
			cout << "Enter Movie ID :";
			do {
				intin(id);
				if (id >= m_m || id < 0)
					cout << "\nID Doesn't exist\n";
			} while (id >= m_m || id < 0);
			system("cls");
			cout << "Current Information!\n";
			mov[id]->showdata();
			mov[id]->enterdata();
			cout << endl << id << " Saved Successfully!\n";
		}
		else
			cout << "\nAdd Records First!\n";
		system("pause");
		system("cls");
		goto start;
		break;
	}
	case '2':
	{
		system("cls");
		if (m_s > 0) {
			cout << "Enter shows ID :";
			do {
				intin(id);
				if (id >= m_s || id < 0)
					cout << "\nID Doesn't exist\n";
			} while (id >= m_s || id < 0);
			system("cls");
			cout << "Current Information!\n";
			mov[id]->showdata();
			sho[id]->enterdata();
			cout << endl << id << " Saved Successfully!\n";
		}
		else
			cout << "\nAdd Records First!\n";
		system("pause");
		system("cls");
		goto start;
		break;
	}
	case '3':
	{
		system("cls");
		if (m_c > 0) {
			cout << "Enter Customer ID :";
			do {
				intin(id);
				if (id >= m_c || id < 0)
					cout << "\nID Doesn't exist\n";
			} while (id >= m_c || id < 0);
			system("cls");
			cout << "Current Information!\n";
			mov[id]->showdata();
			cus[id]->enterdata();
			cout << endl << id << " Saved Successfully!\n";
		}
		else
			cout << "\nAdd Records First!\n";
		system("pause");
		system("cls");
		goto start;
		break;
	}
	case 'b':
	{
		break;
	}
	default:
	{
		cout << "Invalid Input";
		system("cls");
		goto start;
	}

	}
}

void display() {
start: cout << "\n~~~~~~~~~~\nAdmin menu\n~~~~~~~~~~\n";
	cout << "1) Display Movies\n";
	cout << "2) Display Shows\n";
	cout << "3) Display Customers\n";
	cout << "b) Previous menu\n";
	switch (_getche()) {
	case '1':
	{
		system("cls");
		for (int c = 0; c < m_m; c++) {
			system("cls");
			mov[c]->showdata();
			cout << "\nDo you want to see next record!\n (Press Y to continue!)";
			if (_getche() == 'y')
				continue;
			else {
				system("cls");
				break;
			}
		}
		system("cls");
		goto start;
		break;
	}
	case '2':
	{
		system("cls");
		for (int c = 0; c < m_s; c++) {
			system("cls");
			sho[c]->showdata();
			cout << "\nDo you want to see next record!\n (Press Y to continue!)";
			if (_getche() == 'y')
				continue;
			else {
				system("cls");
				break;
			}
		}
		system("cls");
		goto start;
		break;
	}
	case '3':
	{
		system("cls");
		for (int c = 0; c < m_c; c++) {
			system("cls");
			cus[c]->showdata();
			cout << "\nDo you want to see next record!\n (Press Y to continue!)";
			if (_getche() == 'y')
				continue;
			else {
				system("cls");
				break;
			}
		}
		system("cls");
		goto start;
		break;
	}
	case 'b':
	{
		system("cls");
		break;
	}
	default:
	{
		cout << "Invalid Input";
		system("cls");
		goto start;
	}

	}
}

void search() {

	if (m_c > 0 || m_s > 0 || m_c > 0) {

		string search, retrn, type;

		cout << "Select Search Type!\n\n";
		cout << "Search By:\n";
		cout << "1) Name\n";
		cout << "2) Address\n";
		cout << "3) Blood Group\n";
		switch (_getche()) {
		case '1':
		{
			type = "name";
			break;
		}
		case '2':
		{
			type = "address";
			break;
		}
		
		case '5':
		{
			break;
		}
		default:
		{
			cout << "Invalid Input!";
			system("cls");
			goto start;
		}
		}

		cout << "\nEnter " << type << " :";
		cin >> search;

	start:
		cout << "Select Search!\n\n";
		cout << "1) Search in Movies Record\n";
		cout << "2) Search in Shows Record\n";
		cout << "3) Search in Customers Record\n";
		cout << "b) Previous menu\n";
		switch (_getche()) {
		case '1':
		{
			system("cls");
			for (int c = 0; c < m_m; ++c) {
				retrn = mov[c]->search_(type);
				if (retrn == search) {
					mov[c]->showdata();
				}

			}
			goto start;
			break;
		}
		case '2':
		{
			system("cls");
			for (int c = 0; c < m_s; c++) {
				retrn = sho[c]->search_(type);
				if (retrn == search) {
					sho[c]->showdata();
				}

			}
			goto start;
			break;
		}
		case '3':
		{
			system("cls");
			for (int c = 0; c < m_c; c++) {
				retrn = cus[c]->search_(type);
				if (retrn == search) {
					cus[c]->showdata();
				}

			}
			goto start;
			break;
		}
		case 'b':
		{
			system("cls");
			break;
		}
		default:
		{
			cout << "Invalid Input";
			system("cls");
			goto start;
		}

		}

	}
	else
		cout << "\nAdd Multiple Records!\n";
	system("pause");
}

void admin_s() {
start: cout << "\n~~~~~~~~~~\nAdmin menu\n~~~~~~~~~~\n";
	cout << "1) Add Records\n";
	cout << "2) Display Records\n";
	cout << "3) Search Records\n";
	cout << "4) Edit Records\n";
	cout << "b) Main menu\n";
	switch (_getche()) {
	case '1':
	{
		system("cls");
		add();
		system("cls");
		goto start;
		break;
	}
	case '2':
	{
		system("cls");
		display();
		system("cls");
		goto start;
		break;
	}
	case '3':
	{
		system("cls");
		search();
		system("cls");
		goto start;
		break;
	}
	case '4':
	{
		system("cls");
		edit();
		system("cls");
		goto start;
		break;
	}
	case 'b':
	{
		system("cls");
		break;
	}
	default:
	{
		cout << "Invalid Input";
		system("cls");
		goto start;
	}

	}
}

void view() {
	cout << "\nTotal Records\n\n";
	cout << "Movies :" << m_m << endl;
	cout << "Customers :" << m_c << endl;
	cout << "Shows :" << m_s << endl;
	cout << "books :" << m_b << endl << endl;
}

void book_list() {
start: int p_id,
	d_id, a_id;
	   string pname, dname;
	   cout << "\n~~~~~~~~~~~~~\nBook Menu\n~~~~~~~~~~~~~\n\n";
	   cout << "1) Make Booking\n";
	   cout << "2) Remove Booking\n";
	   cout << "3) View Booking list\n";
	   cout << "b) Previous Menu";
	   switch (_getch()) {
	   case '1':
	   {
		   system("cls");
		   if (m_m && m_c > 0) {
			   for (int c = 0; c < max_book; c++) {
				   system("cls");
				   for (int c = 0; c < m_c; c++) {
					   cus[c]->showdata();
				   }
				   cout << "\n\nSelect Customers ID :";
				   do {
					   intin(p_id);
					   if (p_id >= m_c || p_id < 0)
						   cout << "\nID Doesn't exist\n";
				   } while (p_id >= m_c || p_id < 0);

				   pname = cus[p_id]->return_name();
				   //------------------------------------

				   system("cls");

				   for (int c = 0; c < m_m; c++) {
					   mov[c]->showdata();
				   }
				   cout << "\n\nSelect Movies ID :";
				   do {
					   intin(d_id);
					   if (d_id >= m_m || d_id < 0)
						   cout << "\nNo Record exist\n";
				   } while (d_id >= m_m || d_id < 0);
				   dname = mov[d_id]->return_name();
				   //------------------------------------

				   boo[m_b] = new book;
				   boo[m_b]->make_a(pname, dname, m_b);
				   m_b++;
				   cout << "\nDo you want to make another Booking!\n (Press Y to continue!)";
				   if (_getche() == 'y')
					   continue;
				   else {
					   system("cls");
					   goto start;
					   break;
				   }
			   }

		   }
		   else {
			   cout << "\nNo Customers or movies Records Added yet!\n";
			   system("pause");
		   }

		   system("cls");
		   goto start;
		   break;
	   }
	   case '2':
	   {
		   system("cls");
		   if (m_b > 0) {
			   cout << "Enter Booking ID :";
			   do {
				   intin(a_id);
				   if (a_id >= m_b || a_id < 0)
					   cout << "\nID Doesn't exist\n";
			   } while (a_id >= m_b || a_id < 0);
			   for (int c = 0; c < m_b; c++) {
				   delete boo[a_id];
				   m_b--;
			   }
		   }
		   else
			   cout << "\nMake Booking First!\n";
		   system("pause");
		   system("cls");
		   goto start;
		   break;
	   }
	   case '3':
	   {
		   system("cls");
		   if (m_b > 0) {
			   for (int c = 0; c < m_b; c++) {
				   boo[c]->queue();
			   }
		   }
		   else
			   cout << "\nMake Booking First!\n";
		   system("pause");
		   system("cls");
		   goto start;
		   break;
	   }
	   case 'b':
	   {
		   system("cls");
		   break;
	   }
	   default:
	   {
		   cout << "Invalid option";
		   goto start;
	   }
	   }
}



//***********Ends Here**************************//

//****************Member functions***************//

//Class person



// class movies

//class book

//class admin


//************Ends here************//