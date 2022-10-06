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
	
	//������ 1
	//	�������� �������, ������� ��������� ���	����������.������� ��������� ������������ �� ���,
	//	����� ���� ������ �������� ��������� �� �������� ������������.
	std::cout << "������ 1\n������� 3 ����� -> ";
	std::cin >> a >> b >> c;
	max_three(a, b, c);
	std::cout << a <<' ' << b<<' ' << c<<' ' << "\n\n";
	//������ 2
	//	�������� �������, ������� ��������� ������ � ��� �����.������� ���������� ������ �� ������
	//	������������� ������� �������.���� ������������� ��������� ��� � �������, �� ������� ����������
	//	������ �� ������ �������
	std::cout << "������ 2\n";
	fill_arr(arr, size1, -1, 10);
	std::cout << "��������� �����: ";
	show_arr(arr, size1);
	if (ref_arr_negativ(arr, size1) >=0)
		std::cout << "� ������� ��� ������������� ���������\n";
	else
		std::cout << "������ ������������� ������� ������� = " << ref_arr_negativ(arr, size1) << '\n';
	std::cout << '\n';
	//������ 3
	//	�������� �������, ������� ��������� ��� �������	� �� �����.������� ������ �������� ��� ��������
	//	������� �������, ������� ����������� � ������.� ����������� ���������� ������������ ���������
	//	���������� ��� �������� ��������� ��������.
	std::cout << "������ 3\n";
	const int size2 = 10;
	int arr2[size2];
	fill_arr(arr, size1,0,10);
	fill_arr(arr2, size2,5, 15);
	std::cout << "������ ������:";
	show_arr(arr, size1);
	std::cout << "������ ������:";
	show_arr(arr2, size2);
	null_arr2(arr, size1, arr2, size2);
	std::cout << "������ ������ ����� ���������:";
	show_arr(arr2, size2);
	return 0;
}
//���������� �������
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end-begin);
}
//����� �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//������ ��� ����� �� ������������ �� ���
void max_three(int& num1, int& num2, int& num3) {
	int max = num1 < num2 ? (num2 < num3 ? num3 : num2) : (num1<num3?num3:num1);
	num1 = max; num2 = max; num3 = max;
}
//���������� ������ �� ������������� �������
template <typename T>
T& ref_arr_negativ(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}
//�������� �������� ������� �������, ������ � ���������� �������
template <typename T>
void null_arr2(T arr[], const int length, T arr2[], const int length2) {
	for(int i=0;i<length;i++)
		for(int j=0;j<length2;j++)
			if(*(arr+i)==*(arr2+j))
				*(arr2+j)=0;
}