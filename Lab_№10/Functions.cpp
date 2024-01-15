// ����� ���� � ��������� �������
#include "Functions.h"

// ������������� ������
void DataInitialization() {
	ofstream buf("Buffer.txt");

	if (!buf)
		cout << "������ �������� ��������� �����!/n";
	buf.close();
}

// ���� ������
void DataEntry() {
	string name;
	int creditAmount;
	string creditType;
	int term;
	int n;

	cout << "������� ���������� ������: ";
	cin >> n;

	// ��������� �������� ���� � ���������� ������ � ����
	ofstream record("Buffer.txt", ios::app);

	if (record) {
		for (int i = 0; i < n; i++) {
			cout << "������� ���: ";
			cin >> name;

			cout << "������� ����� ������� (� ���.): ";
			cin >> creditAmount;

			cout << "������� ��� �������: ";
			cin >> creditType;

			cout << "������� ���� ������ ������� (���-�� �������): ";
			cin >> term;

			record << name << "\n";
			record << creditAmount << " ���.\n";
			record << creditType << "\n";
			if (i < n - 1) {
				record << term << " ���.\n";
			}
			else {
				record << term << " ���.";
			}
			record << endl;

			cout << "----------------------\n";
		}
	}
	else {
		cout << "������ �������� �����!\n";
	}

	record.close();
}

// ������ ������
void DataReading(string fileName) {
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string name;
			int creditAmount;
			string creditType;
			int term;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++) {
				reading >> name;
				reading >> creditAmount;
				reading >> creditType;
				reading >> term;

				record << name << "\n";
				record << creditAmount << "\n";
				record << creditType << "\n";
				if (i < n - 1) {
					record << term << "\n";
				}
				else {
					record << term;
				}

			}
			cout << "������ �������!\n";
		}
		else
			cout << "������ �������� ������!\n";
	}
	else
		cout << "������ �������� �����!\n";

	// �������� �����
	reading.close();
	record.close();
}

// ����� ������
void Print() {
	ifstream reading("Buffer.txt");

	if (reading) {
		string line;
		string name;
		string creditAmount;
		string creditType;
		string term;
		int n;

		cout << "������� ���������� ������: ";
		cin >> n;
		cout << "\n";

		for (int i = 0; i < n; i++) {
			reading >> line;
			cout << line << "\n";

			reading >> name;
			cout << "���: " << name << "\n";

			reading >> creditAmount;
			cout << "����� �������: " << creditAmount << " ���.\n";

			reading >> creditType;
			cout << "��� �������: " << creditType << "\n";

			reading >> term;
			cout << "���� ������ �������: " << term << " ���.\n";
		}
	}
	else {
		cout << "������ �������� �����!\n";
	}

	reading.close();
}

// ������� ������
void DataCleaning() {
	fstream buf("Buffer.txt", ios::out);

	if (!buf) {
		cout << "������ �������� ��������� �����!\n";
	}

	cout << "���� ������\n";
	buf.clear();
	buf.close();
}

// ��������� ������
/*void DataChange() {
	Copy();

	ifstream reading("Buffer2.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string name, creditType;
			int creditAmount, term, n, n2;

			reading >> n;
			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
			cin >> n2;
			n2--;

			system("cls");

			record << n << "\n";
			if (n2 >= 0 && n2 < n) {
				for (int i = 0; i < n; i++) {
					if (i != n2) {
						reading >> name;
						record << name << "\n";

						reading >> creditAmount;
						record << creditAmount << "\n";

						reading >> creditType;
						record << creditType << "\n";

						reading >> term;
						if (i < n - 1) {
							record << term << "\n";
						}
						else {
							record << term;
						}
					}
					else {
						cout << "������� ������ �1 (���): ";
						cin >> name;

						cout << "������� ������ �2 (����� �������): ";
						cin >> creditAmount;

						cout << "������� ������ �3 (��� �������): ";
						cin >> creditType;

						cout << "������� ������ �4 (���� ������ �������): ";
						cin >> term;

						record << name << "\n";
						record << creditAmount << "\n";
						record << creditType << "\n";
						if (i < n - 1) {
							record << term << "\n";
						}
						else {
							record << term;
						}

						reading >> name;
						reading >> creditAmount;
						reading >> creditType;
						reading >> term;
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
}*/

// ����������� ������
void Copy() {
	ifstream reading("Buffer.txt");
	ofstream record("Buffer2.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string name;
			int creditAmount;
			string creditType;
			int term;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++)
			{
				reading >> name;
				record << name << "\n";

				reading >> creditAmount;
				record << creditAmount << "\n";

				reading >> creditType;
				record << creditType << "\n";

				reading >> term;
				if (i < n - 1)
				{
					record << term << "\n";
				}
				else
				{
					record << term;
				}
			}
		}
		else
			cout << "������ �������� �����!\n";
	}
	else
		cout << "������ �������� ��������� �����!\n";

	record.close();
	reading.close();
}

// ���-�� ������ �� �����
int AmountOfData() {
	ifstream buf("Buffer.txt");
	int n;

	if (buf)
	{
		buf >> n;
	}
	else
	{
		cout << "������ �������� ��������� �����!\n";
	}

	buf.close();

	return n;
}

// �������� ������
/*void DeleteData() {
	Copy();

	ifstream reading("Buffer2.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string name, creditType;
			int creditAmount, term, n, n2;

			reading >> n;
			int b = n - 1;
			cout << "�������� ����� ����������� �������� �� 1 �� " << n << "): ";
			cin >> n2;
			n2--;

			system("cls");

			if (n2 >= 0 && n2 < n)
			{
				for (int i = 0; 1 < n; i++)
				{
					if (i != n2)
					{
						reading >> name;
						record << name << "\n";

						reading >> creditAmount;
						record << creditAmount << "\n";

						reading >> creditType;
						record << creditType << "\n";

						reading >> term;
						if (i < n - 1)
						{
							record << term << "\n";
						}
						else
						{
							record << term;
						}
					}
					else
					{
						reading >> name;
						reading >> creditAmount;
						reading >> creditType;
						reading >> term;
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

	//remove("Buffer2.txt");
}*/

// ���������� ������
void AddData() {
	string name;
	int creditAmount;
	string creditType;
	int term;
	int n = AmountOfData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record2("Buffer.txt", ios::out | ios::in);

	if (!record2) {
		cout << "������ �������� ��������� �����!\n";
	}

	if (record) {
		cout << "������� ���: ";
		cin >> name;

		cout << "������� ����� ������� (� ���.): ";
		cin >> creditAmount;

		cout << "������� ��� �������: ";
		cin >> creditType;

		cout << "������� ���� ������ ������� (���-�� �������): ";
		cin >> term;

		record << "----------------------\n";
		record << name << "\n";
		record << creditAmount << "\n";
		record << creditType << "\n";
		record << term << "\n";
	}
	else {
		cout << "������ �������� �����!\n";
	}

	record.close();
	record2.close();
}

// ���������� ������
void SaveData(string fileName) {
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {
			string name;
			int creditAmount;
			string creditType;
			int term;
			int n;

			reading >> n;
			record << n << "\n";

			for (int i = 0; i < n; i++) {
				reading >> name;
				record << name << "\n";

				reading >> creditAmount;
				record << creditAmount << "\n";

				reading >> creditType;
				record << creditType << "\n";

				reading >> term;
				if (i < n - 1) {
					record << term << "\n";
				}
				else {
					record << term;
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
}