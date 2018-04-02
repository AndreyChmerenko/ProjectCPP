#pragma once
#include <iostream>

class Array {
	int* data;
	int size;
public:	
	Array(); //Конструктор по умолчанию, делает массив размера 0
	Array(int size); //Конструктор по размеру (элементы инициализируются 0)
	Array(int size, int n); //Конструктор по размеру и числу n (элементы инициализируются числом n)
	Array(const Array& Arr); //Конструктор копирования
	Array(Array&& Arr); //Конструктор перемещения
	~Array(); //Деструктор

	const int length(); //Возвращает длину массива
	void resize(int newSize); //Изменяет размер массива

	const int& operator[] (int index); //Доступ к элементу Array с использованием оператора []
	
	Array& operator=(const Array& secondArr); //Присваивание
	Array& operator=(Array&& secondArr); //Перемещение

	//Поэлементное сравнение, при разных длинах массивов выдаёт исключение
	friend const bool operator==(const Array& firstArr, const Array& secondArr);
	friend const bool operator!=(const Array& firstArr, const Array& secondArr);

	//Сравнение в лексикографическом порядке
	friend const bool operator<(const Array& firstArr, const Array& secondArr);
	friend const bool operator<=(const Array& firstArr, const Array& secondArr);
	friend const bool operator>(const Array& firstArr, const Array& secondArr);
	friend const bool operator>=(const Array& firstArr, const Array& secondArr);

	friend Array operator+(const Array& firstArr, const Array& secondArr); //Конкатенация массивов

	friend std::ostream& operator<<(std::ostream &firstArr, const Array& secondArr);//Вывод в поток
	friend std::istream& operator>>(std::istream &firstArr, const Array& secondArr);//Ввод из потока
};