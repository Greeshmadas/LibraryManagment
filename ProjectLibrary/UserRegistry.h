#pragma once
#include<string>
#include<vector>
class UserRegistry
{
		std::string userName;
		int userId;
		std::string mobileNo;
		std::vector <UserRegistry> userData;
public:
		void addUser();
		bool searchUser(int );
		void display();
	};