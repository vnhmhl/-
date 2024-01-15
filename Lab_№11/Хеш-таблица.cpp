
#include "Function.h"

using namespace std;

int stateMenu;
void Menu() {
	cout << "Выберите действие:\n\n"
		"0. Выйти\n"
		"1. Добавить данные\n"
		"2. Показать данные\n"
		"3. Измененить данные\n"
		"4. Удалить данные\n\n";
	cin >> stateMenu;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	Menu();

	int actions;
	string fileName;

	while (stateMenu != 0) {
		switch (stateMenu) {
		case 1:
		
			system("cls");

			DataEntry();

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
			DataEntry();

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			DataCleaning();

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Пункт меню выбран неверно!\n";
			break;
		}
	}

	/*system("cls");
	if (DataCleaning()) {
		cout << "Данные очищены\n";
	}
	else {
		cout << "Данные не очищены!\n";
	}*/
	cout << "Работа завершена\n";

	return 0;
}
