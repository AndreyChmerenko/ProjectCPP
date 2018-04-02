#include "Array.h"

Array::Array()
{
	data = new int[0];
	this->size = 0;
}

Array::Array(int size) 
{
	data = new int[size];
	this->size = size;
}

Array::Array(int size, int n)
{
	data = new int[size];
	this->size = size;
	for (int i = 0; i < size; i++) 
	{
		data[i] = n;
	}
}

Array::Array(const Array & Arr) 
{
	data = new int[Arr.size];
	this->size = Arr.size;
	for (int i = 0; i < Arr.size; i++) 
	{
		this->data[i] = Arr.data[i];
	}
}

Array::Array(Array && Arr) : data(nullptr), size(0)
{
	data = Arr.data;
	size = Arr.size;
	
	Arr.data = nullptr;
	Arr.size = 0;
}


Array::~Array() 
{
	delete[] data;
}

const int Array::length() 
{
	return this->size;
}

void Array::resize(int newSize) 
{
	int *oldData = data;
	data = new int[newSize];

	if (newSize <= size)
	{
		for (int i = 0; i < newSize; i++) 
		{
			data[i] = oldData[i];
		}
	}
	else if (newSize > size)
	{
		for (int i = 0; i < size; i++) {
			data[i] = oldData[i];
		}

		for (int j = size; j < newSize; j++) {
			data[j] = 0;
		}
	}
	size = newSize;
}

const int & Array::operator[](int index) 
{
	return data[index];
}

Array & Array::operator=(const Array & secondArr)
{
	delete[] data;
	this->data = new int[secondArr.size];
	this->size = secondArr.size;

	for (int i = 0; i < secondArr.size; i++) 
	{
		data[i] = secondArr.data[i];
	}
	return *this;
}

Array & Array::operator=(Array && secondArr) 
{
	if (this != &secondArr) 
	{
		delete[] this->data;

		this->data = secondArr.data;
		this->size = secondArr.size;
		secondArr.data = nullptr;
		secondArr.size = 0;
	}
	return *this;
}

const bool operator==(const Array & firstArr, const Array & secondArr) 
{
	if (firstArr.size != secondArr.size) throw std::invalid_argument("Array lengths do not match");
	for (int i = 0; i < firstArr.size; i++)
	{
		if (firstArr.data[i] != secondArr.data[i]) { return false; }
	}
	return true;
}

const bool operator!=(const Array & firstArr, const Array & secondArr)
{
	if (firstArr.size != secondArr.size) throw std::invalid_argument("Array lengths do not match");
	return !(firstArr == secondArr);
}

const bool operator<(const Array & firstArr, const Array & secondArr) 
{
	int size= firstArr.size >= secondArr.size ? secondArr.size: firstArr.size;

	for (int i = 0; i < size; i++) 
	{
		if (secondArr.data[i] < firstArr.data[i]) return false;
	}

	return firstArr.size < secondArr.size;
}

const bool operator<=(const Array & firstArr, const Array & secondArr) 
{
	return !(firstArr > secondArr);
}

const bool operator>(const Array & firstArr, const Array & secondArr) 
{
	return !((firstArr < secondArr) || (firstArr == secondArr));
}

const bool operator>=(const Array & firstArr, const Array & secondArr)
{
	return !(firstArr < secondArr);
}

Array  operator+(const Array & firstArr, const Array & secondArr)
{
	int newSize = firstArr.size + secondArr.size;
	Array newArr(newSize);

	for (int i = 0; i < newSize; i++) {
		newArr.data[i] = i < firstArr.size ? firstArr.data[i] : secondArr.data[i - firstArr.size];
	}
	newArr.size = newSize;

	return newArr;
}

std::ostream & operator<<(std::ostream & os, const Array & secondArr) {
	os << secondArr.data[0];
	for (int i = 1; i < secondArr.size; i++) {
		os << ',' << secondArr.data[i];
	}
	return os;
}

std::istream & operator>>(std::istream & is, const Array & secondArr) {
	std::cout << "Enter number's: ";
	for (int i = 0; i < secondArr.size; i++)
	{
		is >> secondArr.data[i];
		std::cout << std::endl;
	}
	return is;
}