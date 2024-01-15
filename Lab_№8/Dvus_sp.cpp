#include <iostream>
using namespace std;

struct NameDataDouble {
	int data;
	NameDataDouble* prev, *next;
};

struct DoubleList {
	NameDataDouble* first = NULL;
	NameDataDouble* last = NULL;

	/*~DoubleList() {
		delete first;
		delete last;
	}*/

	void AddData(int d) {
		if (first == NULL) {
			first = new NameDataDouble;
			last = first;
			last->prev = NULL;
		}
		else {
			last->next = new NameDataDouble;
			last->next->prev = last;
			last = last->next;
		}
		last->data = d;
		last->next = NULL;
	}

	void GetData() {
		int data;

		do {
			cin >> data;
			AddData(data);
		} while (data != 0);
	}

	void DeleteEvenNumbers() {
		NameDataDouble* current = first->next;

		if (current->next == NULL) {
			last = first;
			first->next = NULL;;
		}

		while (current->next) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			if (current->next->next != NULL) {
				current = current->next->next;
			}
			else {
				last = current->next;
				return;
			}
			if (current->next == NULL) {
				last = current->prev;
				current->prev->next = NULL;
			}
		}
	}

	void PrintData() {
		NameDataDouble* current = first;

		while (current) {
			cout << current->data << "\t";
			current = current->next;
		}
		cout << endl;
	}
};