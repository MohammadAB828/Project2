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

