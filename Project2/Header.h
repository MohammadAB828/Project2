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