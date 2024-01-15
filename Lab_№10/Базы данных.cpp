#include <iostream>
#include "Functions.h"
using namespace std;

int stateMenu;

void Menu() { 
	cout << "Веберите действие:\n\n"
		"0. Выйти из программы\n"
		"1. Изменить данные\n"
		"2. Показать данные\n"
		"3. Удалить данные\n"
		"4. Добавить данные\n\n";
	cin >> stateMenu;
}

int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//DataInitialization();

	Menu();

	int actions;
	string fileName;

	while (stateMenu != 0) {
		switch (stateMenu) {
		case 1:
			// Чистим консоль
			system("cls");
			
			//DataEntry();
			DataCleaning();
			AddData();

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			Print();

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			DataCleaning();

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			AddData();

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Пункт меню выбран неверно!\n";
			break;
		}
	}

	system("cls");

	cout << "Работа завершена\n";
	system("pause");

	return 0;
}
