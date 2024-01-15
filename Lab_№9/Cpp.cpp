#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Handle1 {

	void PrintFile1(string path) { 	// ������� ���� � �������
		ifstream file;
		file.open(path);

		if (!file.is_open()) {
			cout << "������ �������� �����!\n";
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

	// ��������� ������
	void AddString1(string path, string newString) {
		ofstream out(path, ios::app);
		if (out.is_open()) {
			out << newString << "\n";
		}
		out.close();
	}

	// ������� ��������, � ������� ��� ������� ������ ���������
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