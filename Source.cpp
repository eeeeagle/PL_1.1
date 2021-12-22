#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int A[10][10];
	int n, m, a, b;
	float min[10], max[10];
	srand(time(NULL)); // для работы RNG
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // для работы смены цвета выводимого текста
	
	
	printf("Лабораторная работа №1\nВариант 7:\n");
	printf("Нахождение и выделение всех \"седловых\" точек в произовльной матрице.\n\nrelease build v1.2 (17.09.2020, 21:26)\n\n");
	
	
	
	//
	// размерность матрицы задаётся RNG
	
	printf("__________________________________\n\nСлучайное определение размерности матрицы A[n][m]...\n(n, m > 1; n, m < 10)\n\n");

	n = rand();
	n = n % 10 + 1; // max: 10
	printf("Число n = %d\n", n);

	m = rand();
	m = m % 10 + 1;
	printf("Число m = %d\n", m); // max: 10
								 
	

	//
	// ячейки матрицы также заполняются RNG
	
	printf("\nЗаполнение ячеек матрицы A[%d][%d] случайныйми числами...", n, m);
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = rand();
			A[i][j] = A[i][j] % 20000 - 10000; // [-10000;10000]
		}
	}



	//
	// задание минимумов строк и максимумов столбцов

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			if (i == 0)
				max[j] = A[i][j];
			else
				if (max[j] < A[i][j])
					max[j] = A[i][j];


			if (j == 0)
				min[i] = A[i][j];
			else
				if (min[i] > A[i][j])
					min[i] = A[i][j];
		}
	}



	//
	// вывод матрицы с выделением "седловых" точек
	
	printf("\n\n__________________________________\n\nМатрица A[%d][%d] со случайно заполненными ячейками:\n", n, m);
	printf("(\"седловые\" точки их при наличии выделены красным цветом)\n\n\n\n");

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			SetConsoleTextAttribute(handle, 2); // смена цвета матрицы на зеленый
			
			if (min[i] == max[j]) // условие седловой точки
			{
				SetConsoleTextAttribute(handle, 4); // смена цвета на красный для седловой точки 
				printf("%d\t", A[i][j]);
			}
			else
				printf("%d\t", A[i][j]);				
		}
		printf("\n\n\n");
	}

	SetConsoleTextAttribute(handle, 15); // возврат цвета последующего текста на белый
	printf("\n\n\n");

	system("pause");
	return 0;
}