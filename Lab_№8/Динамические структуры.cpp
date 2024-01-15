#include <iostream>
#include "Odnos_sp.cpp.cpp"
#include "Dvus_sp.cpp"
#include "Bin_derevo.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	SingleList singleList;
	cout << "Односвязный список (0 - конец списка), для стека:\n\n";
	singleList.GetData(true);
	cout << "\nНаш список (стек):\n\n";
	singleList.PrintData();
	singleList.DeleteFirst();
	cout << "\nОдносвязный список (0 - конец списка), для очереди:\n\n";
	singleList.GetData();
	cout << "\nНаш список (очередь):\n\n";
	singleList.PrintData();
	singleList.InsertDataAfterNegative();
	cout << "\nДобавляем в список после каждого отрицательного элемента 0:\n\n";
	singleList.PrintData();

	DoubleList doubleList;
	cout << "\n\nДвусвязный список (0 - конец списка):\n\n";
	doubleList.GetData();
	cout << "\nНаш список:\n\n";
	doubleList.PrintData();
	doubleList.DeleteEvenNumbers();
	cout << "\nУдаляем из списка все элементы с четными номерами:\n\n";
	doubleList.PrintData();

	Tree tree;
	cout << "\n\nБинарное дерево (0 - конец дерева):\n\n";
	tree.GetData();
	cout << "\nНаше дерево:\n\n";
	tree.PrintData(tree.treetop);
	int count = tree.compare(tree.treetop, (char*)"1");
	cout << endl << count << " строк, начинающихся с цифры 1" << endl;

	return 0;

}
