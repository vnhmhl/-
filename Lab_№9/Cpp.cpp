#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Handle1 {

	void PrintFile1(string path) { 	// Выводим файл в консоль
		ifstream file;
		file.open(path);

		if (!file.is_open()) {
			cout << "Ошибка открытия файла!\n";
		}
		else {
			string str;

			while (!file.eof()) {
				str = "";
				getline(file, str);
				cout << str << "\n";
			}
		}
		file.close();
	}

	// Добавляем строку
	void AddString1(string path, string newString) {
		ofstream out(path, ios::app);
		if (out.is_open()) {
			out << newString << "\n";
		}
		out.close();
	}

	// Удаляем элементы, у которых год выпуска меньше заданного
	void DeleteLessNotes1(string path, int nLessThan) {
		ifstream file(path);
		ofstream out(path);

		int a = 0;

		while (file >> a) {
			if (a < nLessThan) {
				string s = to_string(a);
				out << s << endl;
			}
		}

		file.close();
		out.close();
	}
};