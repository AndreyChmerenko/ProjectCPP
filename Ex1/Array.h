#pragma once
#include <iostream>

class Array {
	int* data;
	int size;
public:	
	Array(); //����������� �� ���������, ������ ������ ������� 0
	Array(int size); //����������� �� ������� (�������� ���������������� 0)
	Array(int size, int n); //����������� �� ������� � ����� n (�������� ���������������� ������ n)
	Array(const Array& Arr); //����������� �����������
	Array(Array&& Arr); //����������� �����������
	~Array(); //����������

	const int length(); //���������� ����� �������
	void resize(int newSize); //�������� ������ �������

	const int& operator[] (int index); //������ � �������� Array � �������������� ��������� []
	
	Array& operator=(const Array& secondArr); //������������
	Array& operator=(Array&& secondArr); //�����������

	//������������ ���������, ��� ������ ������ �������� ����� ����������
	friend const bool operator==(const Array& firstArr, const Array& secondArr);
	friend const bool operator!=(const Array& firstArr, const Array& secondArr);

	//��������� � ������������������ �������
	friend const bool operator<(const Array& firstArr, const Array& secondArr);
	friend const bool operator<=(const Array& firstArr, const Array& secondArr);
	friend const bool operator>(const Array& firstArr, const Array& secondArr);
	friend const bool operator>=(const Array& firstArr, const Array& secondArr);

	friend Array operator+(const Array& firstArr, const Array& secondArr); //������������ ��������

	friend std::ostream& operator<<(std::ostream &firstArr, const Array& secondArr);//����� � �����
	friend std::istream& operator>>(std::istream &firstArr, const Array& secondArr);//���� �� ������
};