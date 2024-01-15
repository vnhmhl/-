#include "Function.h"

void DataInitialization() { // ������������� ������

	ofstream buf("Buffer.txt");

	if (!buf)
		cout << "������ �������� ��������� �����!/n";

	buf.close();
}


void DataEntry() {	// ���� ������
	string name;
	string dateOfBirth;
	string address;
	int n;

	cout << "������� ���������� ������: ";
	cin >> n;

	
	ofstream record("Buffer.txt", ios::app); // ��������� �������� ���� � ���������� ������ � ����

	if (record) {
		for (int i = 0; i < n; i++) {
			cout << "���: ";
			cin >> name;

			cout << "���� ��������: ";
			cin >> dateOfBirth;

			cout << "�����: ";
			cin >> address;

			record << name << "\n";
			record << dateOfBirth << "\n";
			record << address << "\n";
			record << "----------------------\n";

			cout << "----------------------\n";
		}
	}
	else {
		cout << "������ �������� �����!\n";
	}
	record.close();
}


void DataReading(string fileName) { // ������ ������
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
			cout << "������ �������!\n";
		}
		else
			cout << "������ �������!\n";
	}
	else
		cout << "������ �������� �����!\n";


	reading.close(); 	// �������� �����
	record.close();
}


void Print() { // ����� ������
	ifstream reading("Buffer.txt");

	if (reading) {
		string name;
		string dateOfBirth;
		string address;
		string line;
		int n;

		cout << "������� ���������� ������: ";
		cin >> n;
		cout << "\n";

		for (int i = 0; i < n; i++) {
			reading >> name;
			cout << "���: " << name << "\n";

			reading >> dateOfBirth;
			cout << "���� ��������: " << dateOfBirth << "\n";

			reading >> address;
			cout << "�����: " << address << "\n";

			reading >> line;
			cout << line << "\n";
		}
	}
	else {
		cout << "������ �������� �����!\n";
	}

	reading.close();
}


bool DataCleaning() { // ������� ������
	bool clear = false;

	fstream buf("Buffer.txt", ios::out);

	if (!buf) {
		cout << "������ �������� ��������� �����!\n";
	}

	buf.clear();

	if (buf.peek() == EOF) {
		clear = true;
		cout << "���� ������\n";
	}
	else {
		clear = false;
	}

	buf.close();

	return clear;
}


/*void DataChange() { // ��������� ������
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

			cout << "�������� ����� ����������� ��������: ";
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
						cout << "������� ������ �1 (���): ";
						cin >> name;

						cout << "������� ������ �2 (���� ��������): ";
						cin >> dateOfBirth;

						cout << "������� ������ �3 (�����): ";
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
				cout << "������ ��������!\n";
			}
			else
				"����� ������ �������!";
		}
		else
			cout << "������ �������� �����!\n";
	}
	else
		cout << "������ �������� ��������� �����!\n";

	record.close();
	reading.close();

	remove("Buffer2.txt");
	DeleteData();
	DataEntry();
}*/

void Copy() {
	// ����������� ������
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
			cout << "������ �������� �����!\n";
	}
	else
		cout << "������ �������� ��������� �����!\n";

	remove("Buffer2.txt");
	record.close();
	reading.close();
}


int AmountOfData() { // ���-�� ������ �� �����
	ifstream buf("Buffer.txt");
	int n;

	if (buf) {
		buf >> n;
	}
	else {
		cout << "������ �������� ��������� �����!\n";
	}

	buf.close();

	return n;
}


__inline unsigned long long hashcode(unsigned char* str) { // ���-�������
	unsigned long long hash = 5381;
	int c;

	while (c = *str++) {
		hash = hash % c;
	}
	return hash;
}


/*void DeleteData() { // �������� ������
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
			cout << "�������� ����� ����������� �������� �� 1 �� " << n << "): ";
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
				cout << "������ �������!\n";
			}
			else
				cout << "����� ������ �������!\n";
		}
		else
			cout << "������ �������� �����!\n";
	}
	else
		cout << "������ �������� ��������� �����!\n";

	record.close();
	reading.close();

	remove("Buffer2.txt");
}*/


/*void SaveData(string fileName) // ���������� ������
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
			cout << "������ ��������� � �����" << fileName << "\n";
		}
		else
			cout << "������ �������� ��������� �����!\n";
	}
	else
		cout << "������ �������� �����!\n";

	record.close();
	reading.close();
}*/