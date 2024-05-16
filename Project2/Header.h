#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include "json/json.h"
#include <string.h>
using namespace std;

class Person
{
private:
	string id;
	string password;
public:
	Person();
	~Person();
	string first_name;
	string last_name;
	bool is_admin;
	void set_id(string);
	void set_password(string);
	string get_id();
	string get_password();
};


class Teacher :public Person
{
public:
	Teacher();
	~Teacher();
	friend istream& operator >> (istream& input, Teacher& obj);

private:

};


class Student :public Person
{
public:
	Student();
	~Student();
	friend istream& operator >> (istream& input, Student& obj);

private:

	string major;
};



class Taklif
{
public:
	Taklif();
	~Taklif();
	string name;
	string dead_line;
	string mohtava;
};


class notif
{
public:
	string name;
	notif();
	~notif();
	string mohtava;
};



class Dars
{
public:
	Dars();
	~Dars();
	string name;
	Taklif taklif[10];
	notif notification[10];
	Teacher teacher;
	Student student[100];
	int zarfiat;
	int capacity;
	friend istream& operator>>(istream&, Dars&);
};

