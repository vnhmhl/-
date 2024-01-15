#include <iostream>
using namespace std;

struct NameDataSet {
	double data;
	NameDataSet* next;
};

struct SingleList {
	NameDataSet* first = NULL;
	NameDataSet* last = NULL;

	~SingleList() {
		delete first;
		delete last;
	}

	void AddDataQueue(double d) {
		if (first == NULL) {
			first = new NameDataSet;
			last = first;
		}
		else {
			last->next = new NameDataSet;
			last = last->next;
		}
		last->data = d;
		last->next = NULL;
	}

	void AddDataStack(double d) {
		NameDataSet* tmp = new NameDataSet;
		tmp->data = d;
		tmp->next = first;
		first = tmp;
	}

	void GetData(bool stack = false) {
		double data;

		do {
			cin >> data;
			if (stack) {
				AddDataStack(data);
			}
			else {
				AddDataQueue(data);
			}
		} while (data != 0);
	}

	void InsertDataAfterNegative() {
		NameDataSet* newData = NULL;
		last = first;

		while (last) {
			if (last->data < 0.0) {
				newData = new NameDataSet;
				newData->data = 0.0;
				newData->next = last->next;
				last->next = newData;
				last = newData->next;
			}
			else {
				last = last->next;
			}
		}
	}

	void PrintData() {
		NameDataSet* current = first;

		while (current) {
			cout << current->data << "\t";
			current = current->next;
		}
		cout << endl;
	}

	void DeleteFirst() {
		first = NULL;
	}
};