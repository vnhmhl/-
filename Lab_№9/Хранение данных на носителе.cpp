#include <iostream>
#include <fstream>
#include <string>
#include "Cpp.cpp"
#include "C.cpp"
#pragma warning(disable : 4996)
using namespace std;

	//C++
int FirstStyle(string path)
{
	Handle1 handle1;
	
	
	ofstream FileCar(path); // Создаем файл

	string car1 = "Niva 2012 12000000 black\n";
	string car2 = "Lada 2013 15000 gray\n";
	string car3 = "BWM 1994 12000000 black\n\n";

	FileCar << car1 << car2 << car3;
	FileCar.close();
	cout << "C++ style:\n\n";
	handle1.PrintFile1(path);

	
	string car4 = "Mersedes 2004 550000 orange\n"; // Добавляем в файл строчку
	handle1.AddString1(path, car4); 
	cout << "--------------------\n\n";
	handle1.PrintFile1(path);

	//Удаляем элементы, у которых год выпуска меньше 2012
	handle1.DeleteLessNotes1(path, 2012);
	cout << "--------------------\n\n";
	handle1.PrintFile1(path);

	return 0;
}

	// C
int SecondStyle(string path)
{
	Handle2 handle2;

	FILE* FileCar;
	FileCar = fopen("car (C).txt", "w");

	if (FileCar == NULL) {
		printf("Ошибка открытия файла!\n");
	}

	fprintf(FileCar, "Niva n2012 n12000000 black\n");
	fprintf(FileCar, "Lada n2013 n15000 gray\n");
	fprintf(FileCar, "BWM n1994 n12000000 black\n");

	fclose(FileCar);

	printf("C style:\n\n");
	handle2.PrintFile2(3);
	printf("--------------------\n\n");

	
	FILE* out; // Добавляем в файл строчку
	out = fopen("car (C).txt", "a");

	fprintf(out, "Mersedes n1994 n12000000 norange\n");

	fclose(out);

	
	char line2[255]; 
	FILE* fin2;
	fin2 = fopen("car (C).txt", "r");

	handle2.PrintFile2(4);

	fclose(fin2);

	return 0;
}

int main()
{
	FirstStyle("car (C++).txt");
	SecondStyle("car (C).txt");

	return 0;
}