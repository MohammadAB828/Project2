#include <limits>
#include "Header.h"

int main()
{

	while (true)
	{

	menu:
		system("cls");
		cout << "WELCOME\n\n" << "1.Login\n" << "2.Sign in\n" << "3.Exit\n";

		int Entry_Number;
		cin >> Entry_Number;

		switch (Entry_Number)
		{
			case 3:
			{
				system("cls");
				cout << "Good Luck";
				Sleep(3000);
				system("cls");
				break;
			}

			case 1:
			{
			login:
				system("cls");
				int temp;
				cout << "1.Teacher\n2.Student\n3.Back\n";
				cin >> temp;
				system("cls");
				if (temp == 1) {
					Json::Value json_object = find_or_fail("teacher.json");
					if (json_object != NULL) {
					teacher:
						system("cls");
						cout << "Welcome mr." << json_object["last_name"].asString() << endl;
						cout << "Your class's : \n";
						ifstream file("class.json");
						Json::Value teacher_class;
						Json::Reader r;
						r.parse(file, teacher_class);
						Json::Value temp2;
						int i, j = 0;
						for (i = 0; teacher_class[i] != temp2; i++) {
							if (teacher_class[i]["teacher_id"] == json_object["id"]) {
								cout << j + 1 << "." << teacher_class[i]["name"].asString() << endl;
								j++;
							}
						}
						cout << j + 1 << "." << "Add class\n";
						cout << j + 2 << "." << "Logout\n";
						int temp85;
						cin >> temp85;
						system("cls");
						if (temp85 == j + 1) {
							Dars clas;
							cin >> clas;
							goto teacher;
						}
						else if (temp85 == j + 2) {
							goto login;
						}
						else {
						nav_bar:
							system("cls");
							cout << "1.Add HomeWork" << endl << "2.Add Notificaton" << endl << "3.Back" << endl;
							int temp75;
							cin >> temp75;

							system("cls");

							if (temp75 == 3) {
								goto teacher;
							}
							else if (temp75 == 1) {

								Taklif homework;
								cout << "Enter the name of the homework" << endl;
								cin >> homework.name;

								cout << "Write homework to your student's" << endl;
								cin.ignore(32767, '\n');
								getline(cin, homework.mohtava);

								cout << "Enter the dead line of the homework" << endl;
								cin >> homework.dead_line;


								delete_last_line("homework.json");

								//write
								Json::Value x, y;
								x["class_name"] = teacher_class[temp85 - 1]["name"].asString();
								x["message"] = homework.mohtava;
								x["dead_line"] = homework.dead_line;
								x["name"] = homework.name;
								y = x;

								write_object(y, "homework.json");

								Sleep(2000);
								goto nav_bar;
							}
							else {
								notif notification;
								cout << "Enter the name of the notification" << endl;
								cin >> notification.name;

								cout << "Write your message to your student's" << endl;
								cin.ignore(32767, '\n');
								getline(cin, notification.mohtava);

								delete_last_line("notification.json");

								//write
								Json::Value x, y;
								x["class_name"] = teacher_class[temp85 - 1]["name"].asString();
								x["message"] = notification.mohtava;
								x["name"] = notification.name;
								y = x;

								write_object(y, "notification.json");

								Sleep(2000);
								goto nav_bar;
							}
						}
						Sleep(3000);
					}
					else {
						goto login;
					}
				}
				else if (temp == 2) {
					Json::Value json_object = find_or_fail("student.json");
					if (json_object != NULL) {
					student:
						system("cls");
						cout << "Welcome " << json_object["first_name"].asString() << endl;
						cout << "Your class's : \n";
						ifstream file("class.json");
						Json::Value student_class;
						Json::Reader r;
						r.parse(file, student_class);
						Json::Value temp2;
						string xxx;
						int i, j = 0;
						for (i = 0; student_class[i] != temp2; i++) {

							for (int k = student_class[i]["static_capacity"].asInt() - 1; k >= 0; k--) {
								if (student_class[i]["student_id"][k].asString() == json_object["id"].asString()) {
									cout << j + 1 << "." << student_class[i]["name"].asString() << endl;
									j++;
								}
							}
						}
						cout << j + 1 << "." << "Join new class\n";
						cout << j + 2 << "." << "Logout\n";
						int temp85;
						cin >> temp85;
						system("cls");
						if (temp85 == j + 1) {
							system("cls");
						join:
							for (i = 0; student_class[i] != temp2; i++) {
								cout << i + 1 << "." << student_class[i]["name"].asString() << endl;
							}
							int new_temp;
							cin >> new_temp;
							if (student_class[new_temp - 1]["capacity"] != 0) {

								for (int k = student_class[new_temp - 1]["static_capacity"].asInt() - 1; k >= 0; k--) {
									if (student_class[new_temp - 1]["student_id"][k].asString() == json_object["id"].asString()) {
										cout << "You already joined this class" << endl;
										goto join;
										j++;
									}
								}

								Json::Value root;
								Json::Reader reader;
								std::ifstream filee("class.json", std::ifstream::binary);
								reader.parse(filee, root);
								root[new_temp - 1]["student_id"][student_class[new_temp - 1]["capacity"].asInt() - 1] = json_object["id"];
								root[new_temp - 1]["capacity"] = student_class[new_temp - 1]["capacity"].asInt() - 1;
								Json::StyledWriter writer;
								std::ofstream outputFile("class.json");

								outputFile << writer.write(root);
								outputFile.close();
								cout << "you join this class succefuly" << endl;
							}
							else
							{
								cout << "there is no capacity left in this class" << endl;
							}
							goto student;
						}
						else if (temp85 == j + 2) {
							goto login;
						}
						else {
						url:
							system("cls");
							cout << "1.HomeWork" << endl << "2.Notificaton" << endl << "3.Back" << endl;
							int temp755;
							cin >> temp755;
							if (temp755 == 3) {
								goto student;
							}
							else if (temp755 == 1) {
							homeworky:
								system("cls");
								cout << "Your HomeWork's : \n";
								ifstream file("homework.json");
								Json::Value homework;
								Json::Reader r;
								r.parse(file, homework);
								Json::Value temp21;
								string xxx;
								int i, j = 0;
								for (i = 0; student_class[i] != temp2; i++) {
									for (int k = student_class[i]["static_capacity"].asInt() - 1; k >= 0; k--) {
										if (student_class[i]["student_id"][k].asString() == json_object["id"].asString()) {
											for (int p = 0; homework[p] != temp2; p++) {
												if (student_class[i]["name"].asString() == homework[p]["class_name"].asString()) {
													cout << j + 1 << "." << homework[p]["name"].asString() << endl;
													j++;
												}
											}
										}
									}
								}
								cout << j + 1 << "." << "Back\n";
								int temp855;
								cin >> temp855;
								system("cls");
								if (temp855 == j + 1) {
									goto url;
								}
								else {
									cout << "The name of the homework : " << homework[temp855]["name"] << endl << endl << endl;
									cout << "The main text of the homework : " << endl << homework[temp855]["message"].asString() << endl << endl << endl;
									cout << "The dead line of the homework : " << homework[temp855]["dead_line"].asString() << endl << endl << endl;
									cout << "press any buttom to go back" << endl;
									char s;
									cin >> s;

									goto homeworky;
								}
							}
							else {
							notify:
								cout << "Your Notification's : \n";
								ifstream file("notification.json");
								Json::Value notification;
								Json::Reader r;
								r.parse(file, notification);
								Json::Value temp21;
								string xxx;
								int i, j = 0;
								for (i = 0; student_class[i] != temp2; i++) {
									for (int k = student_class[i]["static_capacity"].asInt() - 1; k >= 0; k--) {
										if (student_class[i]["student_id"][k].asString() == json_object["id"].asString()) {
											for (int p = 0; notification[p] != temp2; p++) {
												if (student_class[i]["name"].asString() == notification[p]["class_name"].asString()) {
													cout << j + 1 << "." << notification[p]["name"].asString() << endl;
													j++;
												}
											}
										}
									}
								}
								cout << j + 1 << "." << "Back\n";
								int temp855;
								cin >> temp855;
								system("cls");
								if (temp855 == j + 1) {
									goto url;
								}
								else {
									cout << "The name of the notification : " << notification[temp855]["name"] << endl << endl << endl;
									cout << "The main text of the notification : " << endl << notification[temp855]["message"].asString() << endl << endl << endl;
									cout << "press 0 buttom to go back" << endl;
									char s;
									cin >> s;
									goto notify;
								}
							}
						}
					}
					else {
						goto login;
					}
				}
				else {
					goto menu;
				}
			}

			case 2 :
			{
				system("cls");
				int temp;
				cout << "1.Teacher\n2.Student\n3.Back\n";
				cin >> temp;
				if (temp == 1) {
					system("cls");
					Teacher teacher;
					cin >> teacher;


				}
				else if (temp == 2) {
					system("cls");
					Student student;
					cin >> student;

				}
				else {
					goto menu;
				}
			}

			default:
				goto menu;
				break;
		}

	}
}