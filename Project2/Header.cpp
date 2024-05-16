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


