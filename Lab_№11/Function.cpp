#include "Function.h"

void DataInitialization() { // Инициализация данных

	ofstream buf("Buffer.txt");

	if (!buf)
		cout << "Ошибка создания буферного файла!/n";

	buf.close();
}


void DataEntry() {	// Ввод данных
	string name;
	string dateOfBirth;
	string address;
	int n;

	cout << "Введите количество данных: ";
	cin >> n;

	
	ofstream record("Buffer.txt", ios::app); // Открываем буферный файл и записываем данные в него

	if (record) {
		for (int i = 0; i < n; i++) {
			cout << "Имя: ";
			cin >> name;

			cout << "Дата рождения: ";
			cin >> dateOfBirth;

			cout << "Адрес: ";
			cin >> address;

			record << name << "\n";
			record << dateOfBirth << "\n";
			record << address << "\n";
			record << "----------------------\n";

			cout << "----------------------\n";
		}
	}
	else {
		cout << "Ошибка открытия файла!\n";
	}
	record.close();
}


void DataReading(string fileName) { // Чтение данных
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string name;
			string dateOfBirth;
			string address;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++) {
				reading >> name;
				reading >> dateOfBirth;
				reading >> address;

				record << name << "\n";
				record << dateOfBirth << "\n";
				if (i < n - 1) {
					record << address << "\n";
				}
				else {
					record << address;
				}

			}
			cout << "Данные считаны!\n";
		}
		else
			cout << "Данные считаны!\n";
	}
	else
		cout << "Ошибка открытия файла!\n";


	reading.close(); 	// Закрытие файла
	record.close();
}


void Print() { // Вывод данных
	ifstream reading("Buffer.txt");

	if (reading) {
		string name;
		string dateOfBirth;
		string address;
		string line;
		int n;

		cout << "Введите количество данных: ";
		cin >> n;
		cout << "\n";

		for (int i = 0; i < n; i++) {
			reading >> name;
			cout << "Имя: " << name << "\n";

			reading >> dateOfBirth;
			cout << "Дата рождения: " << dateOfBirth << "\n";

			reading >> address;
			cout << "Адрес: " << address << "\n";

			reading >> line;
			cout << line << "\n";
		}
	}
	else {
		cout << "Ошибка открытия файла!\n";
	}

	reading.close();
}


bool DataCleaning() { // Очистка данных
	bool clear = false;

	fstream buf("Buffer.txt", ios::out);

	if (!buf) {
		cout << "Ошибка открытия буферного файла!\n";
	}

	buf.clear();

	if (buf.peek() == EOF) {
		clear = true;
		cout << "Файл очищен\n";
	}
	else {
		clear = false;
	}

	buf.close();

	return clear;
}


/*void DataChange() { // Изменение данных
	Copy();

	ifstream reading("Buffer2.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string name;
			string dateOfBirth;
			string address;
			int n, n2;

			reading >> n;

			cout << "Выберите номер изменяемого элемента: ";
			cin >> n2;
			n2--;

			system("cls");

			record << n << "\n";
			if (n2 >= 0 && n2 < n) {
				for (int i = 0; i < n; i++) {
					if (i != n2) {
						reading >> name;
						record << name << "\n";

						reading >> dateOfBirth;
						record << dateOfBirth << "\n";

						reading >> address;
						if (i < n - 1) {
							record << address << "\n";
						}
						else {
							record << address;
						}
					}
					else {
						cout << "Введите данные №1 (Имя): ";
						cin >> name;

						cout << "Введите данные №2 (Дата рождения): ";
						cin >> dateOfBirth;

						cout << "Введите данные №3 (Адрес): ";
						cin >> address;

						record << name << "\n";
						record << dateOfBirth << "\n";

						if (i < n - 1) {
							record << address << "\n";
						}
						else {
							record << address;
						}

						reading >> name;
						reading >> dateOfBirth;
						reading >> address;
					}
				}
				cout << "Данные изменены!\n";
			}
			else
				"Номер введен неверно!";
		}
		else
			cout << "Ошибка открытия файла!\n";
	}
	else
		cout << "Ошибка открытия буферного файла!\n";

	record.close();
	reading.close();

	remove("Buffer2.txt");
	DeleteData();
	DataEntry();
}*/

void Copy() {
	// Копирование данных
	ifstream reading("Buffer.txt");
	ofstream record("Buffer2.txt", ios::out);

	if (reading) {
		if (record) {
			string name;
			string dateOfBirth;
			string address;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++) {
				reading >> name;
				record << name << "\n";

				reading >> dateOfBirth;
				record << dateOfBirth << "\n";

				reading >> address;
				if (i < n - 1) {
					record << address << "\n";
				}
				else {
					record << address;
				}
			}
		}
		else
			cout << "Ошибка открытия файла!\n";
	}
	else
		cout << "Ошибка открытия буферного файла!\n";

	remove("Buffer2.txt");
	record.close();
	reading.close();
}


int AmountOfData() { // Кол-во данных из файла
	ifstream buf("Buffer.txt");
	int n;

	if (buf) {
		buf >> n;
	}
	else {
		cout << "Ошибка открытия буферного файла!\n";
	}

	buf.close();

	return n;
}


__inline unsigned long long hashcode(unsigned char* str) { // Хеш-функция
	unsigned long long hash = 5381;
	int c;

	while (c = *str++) {
		hash = hash % c;
	}
	return hash;
}


/*void DeleteData() { // Удаление данных
	Copy();

	ifstream reading("Buffer2.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string name;
			string dateOfBirth;
			string address;
			int n, n2;

			reading >> n;
			int b = n - 1;
			cout << "Выберите номер изменяемого элемента от 1 до " << n << "): ";
			cin >> n2;
			n2--;

			system("cls");

			if (n2 >= 0 && n2 < n) {
				for (int i = 0; 1 < n; i++) {
					if (i != n2) {
						reading >> name;
						record << name << "\n";

						reading >> dateOfBirth;
						record << dateOfBirth << "\n";

						reading >> address;
						if (i < n - 1) {
							record << address << "\n";
						}
						else {
							record << address;
						}
					}
					else {
						reading >> name;
						reading >> dateOfBirth;
						reading >> address;
					}
				}
				cout << "Данные удалены!\n";
			}
			else
				cout << "Номер введен неверно!\n";
		}
		else
			cout << "Ошибка открытия файла!\n";
	}
	else
		cout << "Ошибка открытия буферного файла!\n";

	record.close();
	reading.close();

	remove("Buffer2.txt");
}*/


/*void SaveData(string fileName) // Сохранение данных
{
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading)
	{
		if (record)
		{
			string name;
			string dateOfBirth;
			string address;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++)
			{
				reading >> name;
				record << name << "\n";

				reading >> dateOfBirth;
				record << dateOfBirth << "\n";

				reading >> address;
				if (i < n - 1)
				{
					record << address << "\n";
				}
				else
				{
					record << address;
				}
			}
			cout << "Данные сохранены в файле" << fileName << "\n";
		}
		else
			cout << "Ошибка открытия буферного файла!\n";
	}
	else
		cout << "Ошибка открытия файла!\n";

	record.close();
	reading.close();
}*/