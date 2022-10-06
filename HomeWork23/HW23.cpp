#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
T& ref_arr_negativ(T arr[], const int length);
template <typename T>
void null_arr2(T arr[], const int length,T arr2[], const int length2);
void max_three(int& num1, int& num2, int& num3);
int main() {
	setlocale(LC_ALL, "Russian");
	int a,b,c;
	const int size1 = 10;
	int arr[size1];
	
	//Задача 1
	//	Создайте функцию, которая принимает три	переменные.Функция вычисляет максимальную из них,
	//	после чего меняет значение остальных на значение максимальной.
	std::cout << "Задача 1\nВведите 3 числа -> ";
	std::cin >> a >> b >> c;
	max_three(a, b, c);
	std::cout << a <<' ' << b<<' ' << c<<' ' << "\n\n";
	//Задача 2
	//	Создайте функцию, которая принимает массив и его длину.Функция возвращает ссылку на первый
	//	отрицательный элемент массива.Если отрицательных элементов нет в массиве, то функция возвращает
	//	ссылку на первый элемент
	std::cout << "Задача 2\n";
	fill_arr(arr, size1, -1, 10);
	std::cout << "Имеющийся масив: ";
	show_arr(arr, size1);
	if (ref_arr_negativ(arr, size1) >=0)
		std::cout << "В массиве нет отрицательных элементов\n";
	else
		std::cout << "Первый отрицательный элемент массива = " << ref_arr_negativ(arr, size1) << '\n';
	std::cout << '\n';
	//Задача 3
	//	Напишите функцию, которая принимает два массива	и их длины.Функция должна обнулить все элементы
	//	второго массива, которые встречаются в первом.В телефункции необходимо использовать синтаксис
	//	указателей для перебора элементов массивов.
	std::cout << "Задача 3\n";
	const int size2 = 10;
	int arr2[size2];
	fill_arr(arr, size1,0,10);
	fill_arr(arr2, size2,5, 15);
	std::cout << "Первый массив:";
	show_arr(arr, size1);
	std::cout << "Второй массив:";
	show_arr(arr2, size2);
	null_arr2(arr, size1, arr2, size2);
	std::cout << "Второй массив после обнуления:";
	show_arr(arr2, size2);
	return 0;
}
//заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end-begin);
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//меняет три числа на максимальное из них
void max_three(int& num1, int& num2, int& num3) {
	int max = num1 < num2 ? (num2 < num3 ? num3 : num2) : (num1<num3?num3:num1);
	num1 = max; num2 = max; num3 = max;
}
//возвращает ссылку на отрицательный элемент
template <typename T>
T& ref_arr_negativ(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}
//Обнуляет элементы второго массива, схожие с элементами первого
template <typename T>
void null_arr2(T arr[], const int length, T arr2[], const int length2) {
	for(int i=0;i<length;i++)
		for(int j=0;j<length2;j++)
			if(*(arr+i)==*(arr2+j))
				*(arr2+j)=0;
}