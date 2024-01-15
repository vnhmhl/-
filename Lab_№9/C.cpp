#include <stdio.h>
#pragma warning(disable : 4996)

struct Handle2 {
	void PrintFile2(int n) {
		char line[255];
		FILE* file;
		file = fopen("car (C).txt", "r");

		for (int i = 0; i < n; ++i) {
			fgets(line, 255, file);
			printf("%s", line);
		}

		printf("\n");

		fclose(file);
	}
};