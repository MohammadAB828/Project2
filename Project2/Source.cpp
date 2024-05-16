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

			default:
				goto menu;
				break;
		}

	}
}