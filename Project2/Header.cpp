#include "Header.h"


Person::Person()
{
}

Person::~Person()
{

}

void Person::set_id(string ID)
{
	id = ID;
}

void Person::set_password(string Pass)
{
	password = Pass;
}

string Person::get_id()
{
	return id;
}

string Person::get_password()
{
	return password;
}

///////


Teacher::Teacher()
{
	is_admin = true;
}

Teacher::~Teacher()
{
}


istream& operator>>(istream& input, Teacher& obj) {

	string first_name, last_name, password, re_password, id;
	cout << "Id : ";
	input >> id;
	cout << "First Name : ";
	input >> first_name;
	cout << "Last Name : ";
	input >> last_name;
password:
	cout << "Password : ";
	input >> password;
	cout << "Repeat Password : ";
	input >> re_password;

	if (password == re_password) {
		obj.set_id(id);
		obj.first_name = first_name;
		obj.last_name = last_name;
		obj.set_password(password);
	}
	else {
		cout << "password is not verified\n";
		Sleep(3000);
		system("cls");
		cout << "Id : ";
		cout << id << endl;
		cout << "First Name : ";
		cout << first_name << endl;
		cout << "Last Name : ";
		cout << last_name << endl;
		goto password;
	}

	delete_last_line("teacher.json");

	//write
	Json::Value x, y;
	x["id"] = obj.get_id();
	x["first_name"] = obj.first_name;
	x["last_name"] = obj.last_name;
	x["password"] = obj.get_password();
	y = x;

	write_object(y, "teacher.json");

	return input;
}



//////


Student::Student()
{
	is_admin = false;
}

Student::~Student()
{

}


istream& operator>>(istream& input, Student& obj) {

	string first_name, last_name, password, re_password, id;
	cout << "Id : ";
	input >> id;
	cout << "First Name : ";
	input >> first_name;
	cout << "Last Name : ";
	input >> last_name;
password:
	cout << "Password : ";
	input >> password;
	cout << "Repeat Password : ";
	input >> re_password;

	if (password == re_password) {
		obj.set_id(id);
		obj.first_name = first_name;
		obj.last_name = last_name;
		obj.set_password(password);
	}
	else {
		cout << "password is not verified\n";
		Sleep(3000);
		system("cls");
		cout << "Id : ";
		cout << id << endl;
		cout << "First Name : ";
		cout << first_name << endl;
		cout << "Last Name : ";
		cout << last_name << endl;
		goto password;
	}

	delete_last_line("student.json");

	//write
	Json::Value x, y;
	x["id"] = obj.get_id();
	x["first_name"] = obj.first_name;
	x["last_name"] = obj.last_name;
	x["password"] = obj.get_password();
	y = x;

	write_object(y, "student.json");

	return input;
}


/////


Taklif::Taklif()
{
}

Taklif::~Taklif()
{
}

//////

notif::notif()
{
}

notif::~notif()
{
}

///


Dars::Dars()
{
}

Dars::~Dars()
{
}


inline istream& operator>>(istream& input, Dars& obj)
{
	string name, id;
	int zarf;
	cout << "Enter your id : ";
	input >> id;
	cout << "Enter the name of the class : ";
	input >> obj.name;
	cout << "Enter the capacity : ";
	input >> zarf;



	delete_last_line("class.json");

	//write
	Json::Value x, y;
	x["name"] = obj.name;
	x["capacity"] = zarf;
	x["static_capacity"] = zarf;
	x["teacher_id"] = id;
	x["student_id"][zarf];
	y = x;

	write_object(y, "class.json");

	return input;
}


///





