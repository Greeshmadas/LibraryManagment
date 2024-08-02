#pragma once
#include<string>
#include<vector>


class BookRegistry
{

	std::string title;
	std::string author;
	int id;
	std::vector <BookRegistry> details;
public:
	void addBook();
	void rentBook();
	void display();

};

