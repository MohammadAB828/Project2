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



istream& operator>>(istream& input, Dars& obj)
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



void delete_last_line(string file_name) {
	std::string filename = file_name;


	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Unable to open input file" << std::endl;

	}

	std::vector<std::string> lines;
	std::string line;


	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}

	inputFile.close();


	std::ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "Unable to open output file" << std::endl;

	}


	for (size_t i = 0; i < lines.size() - 1; ++i) {
		outputFile << lines[i] << std::endl;
	}

	outputFile.close();

}


void write_object(Json::Value y, string file_name) {

	Json::StreamWriterBuilder builder;
	string json_str = Json::writeString(builder, y);

	ofstream file(file_name, ios::app);
	if (file.is_open()) {
		file << "," << json_str << endl << "]";
		file.close();
		std::cout << "your information saved successfully" << std::endl;
	}
	else {
		std::cerr << "error from database" << std::endl;
	}

	Sleep(3000);
}





Json::Value find_or_fail(string file_name) {
	string id, password;
	cout << "id : ";
	cin >> id;
	cout << "password : ";
	cin >> password;
	ifstream file(file_name);
	Json::Value x;
	Json::Reader r;
	r.parse(file, x);
	Json::Value temp;
	for (int i = 0; x[i] != temp; i++) {
		if (x[i]["id"] == id && x[i]["password"] == password) {
			return x[i];
		}
	}
	cout << "The id or Password is incorrect";
	Sleep(3000);
	system("cls");
	return NULL;
}


Json::Value get_all_class(string file_name) {
	ifstream file(file_name);
	Json::Value x;
	Json::Reader r;
	r.parse(file, x);
	return x;
}
