#include"BookRegistry.h"
#include"UserRegistry.h"
#include<iostream>
#include <iomanip>
using namespace std;
void BookRegistry::addBook()
{
	int numberOfbooks;
	cout << "enter the number of books" << endl;
	cin >> numberOfbooks;

	for (int i = 0; i < numberOfbooks; i++)
	{
		BookRegistry b1;
		cout << "enter the title of book" << endl;
		cin >> b1.title;
		cout << "enter the author of book" << endl;
		cin >> b1.author;
		cout << "enter the id of book" << endl;
		cin >> b1.id;
		details.push_back(b1);
	}
}
void BookRegistry::rentBook()
{
	string name;
	cout << "\nEnter the title of the book you need" << endl;
	cin >> name;

	for (auto it = details.begin(); it != details.end(); it++)
	{
		//cout << " " << (*it).author << endl;
		if (name == (*it).title)
		{
			details.erase(it);
			break;
		}
	}
}
void BookRegistry::display()
{
	for (int i = 0; i < 70; i++)
		cout << "=";
	cout << endl;
	cout << setw(45) << "BOOKS AVAILABLE" << endl;
	for (int i = 0; i < 70; i++)
		cout << "=";
	cout << endl;
	cout << "ID" << setw(35) << "Title of Book" << setw(35) << "Author" << endl;
	for (unsigned int i = 0; i < details.size(); i++)
	{
		cout << details[i].id << setw(35) << details[i].title << setw(35) << details[i].author << endl;
	}
}
void UserRegistry::addUser() {
	UserRegistry u1;
	cout << "Register User" << endl;
	cout << "enter the name" << endl;
	cin >> u1.userName;
	cout << "enter the mobileno" << endl;
	cin >> u1.mobileNo;
	cout << "enter the id" << endl;
	cin >> u1.userId;
	userData.push_back(u1);
}
bool UserRegistry::searchUser(int id)
{
	bool result;
	for (auto i = userData.begin(); i != userData.end(); ++i)
	{
		if (id == (*i).userId)
		{
			result = 1;
			break;
		}
		else
			result = 0;
	}
	return result;
}
void UserRegistry::display() {
	for (int i = 0; i < 70; i++)
		cout << "-";
	cout << endl;
	cout << setw(45) << "REGISTERED USERS" << endl;
	for (int i = 0; i < 70; i++)
		cout << "-";
	cout << endl;
	cout << "ID" << setw(35) << "Name" << setw(35) << "MobileNo" << endl;
	for (unsigned int i = 0; i < userData.size(); i++)
	{
		cout << userData[i].userId << setw(35) << userData[i].userName << setw(35) << userData[i].mobileNo << endl;

	}
}
int main()
{
	BookRegistry B1;
	UserRegistry U1;

	B1.addBook();
	system("cls");
	B1.display();

	U1.addUser();
	U1.addUser();
	system("cls");
	U1.display();

	char op;
	int User_Id;
	bool searchResult;
	cout << "Do you want to rent a book?(y/n)" << endl;
	cin >> op;
	if (op == 'y')
	{
		cout << "enter the user ID" << endl;
		cin >> User_Id;

		searchResult = U1.searchUser(User_Id);
		if (searchResult == 1)
		{
			B1.rentBook();
			B1.display();
		}
	}
	else
		cout << "Thankyou" << endl;
	
	system("pause>0");
	return 0;
}