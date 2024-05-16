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


//////


Student::Student()
{
	is_admin = false;
}

Student::~Student()
{

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



