#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <conio.h>

using namespace std;

// CLASS FOR STUDENT PAGE
class issuebooks
{
public:
	int ch, pages;
	char name[50];
	long int id;
	char sname[50];
	long int sid;
	void issuebook();
	void displayissuedbooks();
	void returnbook();
	void studentpageswitch();
	void studentpage()
	{
		system("CLS");
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------- ";
		cout << "GEHU Library";
		cout << " ------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "     				1. DISPLAY ALL ISSUED BOOKS DETAILS" << endl;
		cout << "     				2. ISSUE BOOK" << endl;
		cout << "     				3. RETURN BOOK" << endl;
		cout << "     				4. EXIT" << endl
			 << endl;
		cout << "     				ENTER CHOICE" << endl;
		cout << "     				";
		cin >> ch;
		studentpageswitch();
	}
};

// SWITCH CASE IMPLEMENTATION FOR STUDENT PAGE

void issuebooks::studentpageswitch()
{
	while (ch != 1 || ch != 2 || ch != 3 || ch != 4)
	{
		switch (ch)
		{
		case 1:
			displayissuedbooks();
			break;
		case 2:
			issuebook();
			break;
		case 3:
			returnbook();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << endl
				 << "     				INVALID CHOICE" << endl;
			cout << "     				ENTER CHOICE" << endl;
			cout << "     				";
			cin >> ch;
			break;
		}
	}
}

// FUNCTION TO ADD BOOK

void issuebooks::issuebook()
{

	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "ENTER YOUR NAME AND STUDENT ID" << endl;
	cout << "NAME : ";
	cin >> sname;
	cout << "ID : ";
	cin >> sid;

	bool flag = false;

	ifstream book1("BOOKS.txt");
	ofstream book2("ISSUEDBOOKS.txt", ios::app);
	char bname[50];
	cout << "     				ENTER NAME OF BOOK YOU WANT TO ISSUE" << endl;
	cout << "     				";
	cin >> bname;
	while (book1 >> name >> pages >> id)
	{
		if (strcmp(name, bname) == 0)
		{
			book2 << name << ' ' << sname << ' ' << sid << endl;
			flag = true;
			break;
		}
	}

	if (flag == false)
	{
		cout << "\nBOOK NOT FOUND!!" << endl;
		system("PAUSE");
		return;
	}

	book1.close();
	book2.close();
	cout << endl
		 << "     BOOK ISSUED" << endl;
	cout << endl
		 << "     PRESS ANY KEY TO CONTINUE";
	cout << "     ";
	getch();
	studentpage();
}

// FUNCTION TO DISPLAY BOOK STORED

void issuebooks::displayissuedbooks()
{
	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	ifstream book("ISSUEDBOOKS.txt");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "		BOOK		Student Name		Student ID" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	while (book >> name >> sname >> sid)
	{
		cout << "		" << name << "		" << sname << "		" << sid << endl;
	}
	book.close();
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl
		 << "     PRESS ANY KEY TO CONTINUE" << endl;
	cout << "     ";
	getch();
	studentpage();
}

//FUNCTION TO RETURN BOOK
void issuebooks::returnbook()
{
	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	char tname[50];
	ifstream book1("ISSUEDBOOKS.txt");
	ofstream book2("temp.txt");
	cout << "		ENTER THE NAME OF BOOK YOU WANT TO RETURN" << endl;
	cout << "		";
	cin >> tname;
	bool flag = false;
	while (book1 >> name >> sname >> sid)
	{
		if (strcmp(name, tname) != 0)
		{
			book2 << name << ' ' << sname << ' ' << sid << endl;
		}
		else if (strcmp(name, tname) == 0)
		{
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "\nBOOK NOT FOUND !!!" << endl;
		system("PAUSE");
		return;
	}

	book1.close();
	book2.close();
	remove("ISSUEDBOOKS.txt");
	rename("temp.txt", "ISSUEDBOOKS.txt");
	cout << endl
		 << "		BOOK RETURNED" << endl;
	cout << endl
		 << "     PRESS ANY KEY TO CONTINUE" << endl;
	cout << "     ";
	getch();
	studentpage();
}

// CLASS BOOK TO ADD, REMOVE AND DISPLAY BOOK DETAILS
class books
{
public:
	int ch, pages;
	char name[50];
	long int id;
	void addbook();
	void displaybooks();
	void removebook();
	void facultypageswitch();
	friend void loginpage();
	void facultypage()
	{
		system("CLS");
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------- ";
		cout << "GEHU Library";
		cout << " ------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "     				1. DISPLAY ALL BOOKS DETAILS" << endl;
		cout << "     				2. ADD NEW BOOK DETAILS" << endl;
		cout << "     				3. REMOVE OLD BOOK DETAILS" << endl;
		cout << "     				4. EXIT" << endl
			 << endl;
		cout << "     				ENTER CHOICE" << endl;
		cout << "     				";
		cin >> ch;
		facultypageswitch();
	}
};

// SWITCH CASE IMPLEMENTATION FOR FACULTY PAGE

void books::facultypageswitch()
{
	while (ch != 1 || ch != 2 || ch != 3 || ch != 4)
	{
		switch (ch)
		{
		case 1:
			displaybooks();
			break;
		case 2:
			addbook();
			break;
		case 3:
			removebook();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << endl
				 << "     INVALID CHOICE" << endl;
			cout << "     ENTER CHOICE" << endl;
			cout << "     ";
			cin >> ch;
			break;
		}
	}
}

// FUNCTION TO ADD BOOK

void books::addbook()
{
	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	ofstream newbook("BOOKS.txt", ios::app);
	cout << "     				ENTER NAME OF BOOK" << endl;
	cout << "     				";
	cin >> name;
	cin.sync();
	cout << "     				ENTER NUMBER OF PAGES" << endl;
	cout << "     				";
	cin >> pages;
	cout << "     				ENTER ID OF BOOK" << endl;
	cout << "     				";
	cin >> id;
	newbook << name << ' ' << pages << ' ' << id << endl;
	newbook.close();
	cout << endl
		 << "     				BOOK ADDED" << endl;
	cout << endl
		 << "     				PRESS ANY KEY TO CONTINUE";
	cout << "     				";
	getch();
	facultypage();
}

// FUNCTION TO DISPLAY BOOK STORED

void books::displaybooks()
{
	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	ifstream book("BOOKS.txt");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "		BOOK		PAGES		ID" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	while (book >> name >> pages >> id)
	{
		cout << "		" << name << "		" << pages << "			" << id << endl;
	}
	book.close();
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl
		 << "     PRESS ANY KEY TO CONTINUE" << endl;
	cout << "     ";
	getch();
	facultypage();
}

// FUNCTION TO REMOVE BOOK

void books::removebook()
{
	system("CLS");
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- ";
	cout << "GEHU Library";
	cout << " ------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	char bname[50];
	ifstream book1("BOOKS.txt");
	ofstream book2("temp.txt");
	cout << "     				ENTER THE NAME OF BOOK YOU WISH TO REMOVE" << endl;
	cout << "     				";
	cin >> bname;
	while (book1 >> name >> pages >> id)
	{
		if (strcmp(name, bname) != 0)
		{
			book2 << name << " " << pages << " " << id << endl;
		}
	}
	book1.close();
	book2.close();
	remove("BOOKS.txt");
	rename("temp.txt", "BOOKS.txt");
	cout << endl
		 << "     				BOOK REMOVED" << endl;
	cout << endl
		 << "     				PRESS ANY KEY TO CONTINUE" << endl;
	cout << "     ";
	getch();
	facultypage();
}

//CLASS TO IMPLEMENT HOMEPAGE AND LOGIN PAGE
class login
{
public:
	string pass = "";
	int ch;
	char c;
	void loginpageswitch();
	void homepageswitch();
	void facultylogin();
	void studentlogin();
	void emp();
	void own();

	void homepage()
	{
		system("CLS");
		// gotoxy(40, 1);
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "----------------------------- ";
		cout << "WELCOME TO GEHU LIBRARY";
		// gotoxy(40, 2);
		cout << " -----------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "     				1. LOGIN" << endl;
		cout << "    				2. EXIT" << endl
			 << endl;
		cout << "     				ENTER YOUR CHOICE : " << endl;
		cout << "     				";
		cin >> ch;
		homepageswitch();
	}
	void loginpage()
	{
	loginpage:;
		system("CLS");
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------- ";
		cout << "GEHU Library";
		cout << " ------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "     				1. Student LOGIN" << endl;
		cout << "     				2. Faculty LOGIN" << endl;
		cout << "     				3. EXIT" << endl
			 << endl;
		cout << "     				ENTER CHOICE" << endl;
		cout << "     				";
		cin >> ch;
		loginpageswitch();
	}
};
void login::homepageswitch()
{
	while (ch != 1 || ch != 2)
	{
		switch (ch)
		{
		case 1:
			loginpage();
			break;
		case 2:
			exit(0);
			break;
		default:
			cout << endl
				 << "     				INVALID CHOICE" << endl;
			cout << "     				ENTER CHOICE" << endl;
			cout << "     				";
			cin >> ch;
		}
	}
}
void login::loginpageswitch()
{
	while (ch != 1 || ch != 2 || ch != 3)
	{
		switch (ch)
		{
		case 1:
			studentlogin();
			break;
		case 2:
			facultylogin();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << endl
				 << "     				INVALID CHOICE" << endl;
			cout << "     				ENTER CHOICE" << endl;
			cout << "     				";
			cin >> ch;
		}
	}
}
void login::studentlogin()
{
	while (pass != "STU")
	{
		pass = "";
		cout << endl
			 << "     				ENTER STUDENT PASSWORD" << endl;
		cout << "     				";
		c = _getch();
		while (c != 13)
		{
			pass.push_back(c);
			cout << "*";
			c = getch();
		}
		if (pass == "STU")
		{
			cout << endl
				 << "     				STUDENT ACCESS GRANTED" << endl;
			cout << endl
				 << "     				PRESS ANY KEY TO CONTINUE" << endl;
			cout << "     				";
			getch();
			own();
		}
		else
		{
			cout << endl
				 << "     				INVALID PASSWORD" << endl;
		}
	}
}
void login::facultylogin()
{
	while (pass != "FAC")
	{
		pass = "";
		cout << "     				ENTER FACULTY PASSWORD" << endl;
		cout << "     				";
		c = _getch();
		while (c != 13)
		{
			pass.push_back(c);
			cout << "*";
			c = getch();
		}
		if (pass == "FAC")
		{
			cout << endl
				 << "     				FACULTY ACCESS GRANTED" << endl;
			cout << endl
				 << "     				PRESS ANY KEY TO CONTINUE" << endl;
			cout << "     				";
			getch();
			emp();
		}
		else
		{
			cout << endl
				 << "     				INVALID PASSSWORD" << endl;
		}
	}
}
void login::emp()
{
	books s;
	s.facultypage();
}
void login::own()
{
	issuebooks e;
	e.studentpage();
}

//MAIN FUNCTION
int main()
{
	system("title LIBRARY MANGEMENT SYSTEM");
	login l;
	l.homepage();
	return 0;
}