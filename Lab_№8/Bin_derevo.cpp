#include <iostream>
using namespace std;


struct NameDataTree {
	char* data;
	NameDataTree* left, * right;
};

struct Tree {
	NameDataTree* treetop = NULL;

	void AddData(struct NameDataTree** root, char* d) {

		if ((!root) && (treetop)) {
			root = &treetop;
		}

		struct NameDataTree* _root = NULL;

		if (root) {
			_root = (*root);
		}

		if (!(_root)) {
			_root = new NameDataTree;

			_root->data = d;
			_root->left = NULL;
			_root->right = NULL;

			if (!treetop) {
				treetop = _root;
			}
			else if (root) {
				(*root) = _root;
			}
		}
		else {
			if (strlen(_root->data) > strlen(d)) {
				AddData(&(_root->left), d);
			}
			else {
				AddData(&(_root->right), d);
			}
		}
	}

	void GetData() {

		char* data = NULL;

		do {
			data = new char[256]; // Allocate memory
			cin >> data;
			AddData(NULL, data);
		} while (atoi(data) != 0);
	}

	void PrintData(struct NameDataTree* treetop) {
		if (!treetop)
			return;
		PrintData(treetop->left);
		cout << treetop->data << endl;
		PrintData(treetop->right);
	}

	bool _compare(char* string, char* startwith) {
		bool bResult = false;

		if (strlen(startwith) > strlen(string))
		{
			return false;
		}

		int str_size = strlen(startwith);

		if (str_size > 0) { // If startwith is not empty
			bResult = true;

			for (int i = 0; i < str_size; i++) {
				if (*(string + i) != *(startwith + i)) {
					bResult = false;

					break;
				}
			}
		}

		return bResult;
	}

	int compare(struct NameDataTree* treetop, char* startwith) {
		int result = 0;

		if (treetop) {
			result += compare(treetop->left, startwith);

			if (_compare(treetop->data, startwith)) {
				result++;
			}

			result += compare(treetop->right, startwith);
		}

		return result;
	}
};
