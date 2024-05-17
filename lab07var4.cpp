#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
using namespace std;


void sort(string name, vector <double>& vec) //Функция для сортировки массива вещественных чисел методом пузырька при помощи 3-х потоков
{
	double temp = 0;
	int a = 0;
	if (name == "tread1") a = 1; //Определяем, какую часть кода функции будет выполнять поток
	if (name == "tread2") a = 2;
	if (name == "tread3") a = 3;
	switch(a) //Используем для разделения кода функции на 3 блока, для каждого потока соответственно
	{
	case 1:
	{
		for (int j = 0; j < size(vec) / 2; ++j) //Цикл сортировки первой половины массива методом пузырька
		{
			for (int i = 0; i < (size(vec) / 2) - 1; ++i)
			{
				if (vec[i] > vec[i + 1])
				{
					temp = vec[i];
					vec[i] = vec[i + 1];
					vec[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size(vec); ++i) //Функция печати отсортированного массива
		{
			cout << "tread1" << endl;
			this_thread::sleep_for(chrono::milliseconds(10)); //Устанавливаем задержку на 10мс
			cout << vec[i] << endl;
		}
		break;
	}
	case 2:
	{
		for (int j = size(vec) / 2; j < size(vec); ++j) //Цикл сортировки второй половины массива методом пузырька
		{
			for (int i = size(vec) / 2; i < size(vec) - 1; ++i)
			{
				if (vec[i] > vec[i + 1])
				{
					temp = vec[i];
					vec[i] = vec[i + 1];
					vec[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size(vec); ++i)
		{
			cout << "tread2" << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
			cout << vec[i] << endl;
		}
		break;
	}
	case 3:
	{
		for (int j = 0; j < size(vec); ++j) //Цикл сортировки всего массива методом пузырька
		{
			for (int i = 0; i < (size(vec)) - 1; ++i)
			{
				if (vec[i] > vec[i + 1])
				{
					temp = vec[i];
					vec[i] = vec[i + 1];
					vec[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size(vec); ++i)
		{
			cout << "tread3" << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
			cout << vec[i] << endl;
		}
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 10;
	double temp = 0;
	vector <double> vec;
	for(int i = 0; i < n; ++i) //Заполняем начальный вектор vec псевдослучайными вещественными числами
	{
		temp =(double) rand() * 100 / RAND_MAX;
		vec.push_back(temp);
	}
	cout << "Начальный массив: " << endl;
	for (int i = 0; i < size(vec); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	thread tread1(sort, "tread1", ref(vec)); //Включаем первый дочерний поток
	thread tread2(sort, "tread2", ref(vec)); //Включаем второй дочерний поток
	tread1.join(); //Дожидаемся конца работы первого потока
	tread2.join(); //Дожидаемся конца работы второго потока
	thread tread3(sort, "tread3", ref(vec)); //Включаем третий дочерний поток после выполнения первых двух
	tread3.join(); //Дожидаемся конца работы третьего потока
	cout << "Работа окончена";
	return 0;
}
