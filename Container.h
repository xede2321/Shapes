#pragma once
#include"Circle.h"
#include"triangle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Line.h"
#include"Point.h"
#include"Cube.h"
#include"Objects.h"
class Container{
private:
	Objects** arr;
	int size;
public:
	Container();
	~Container();
	template <typename T>
	void Add(T& elem);
	template <typename T>
	void Delete(T& elem);
	template <typename T>
	void Out(T& elem);
	Objects* operator[](const int i);
	friend ostream& operator<<(ostream& out, Container& other);
};
Container::Container(){
	size = 0;
	arr = 0;
}
Container::~Container(){
	delete[] arr;
}
Objects* Container::operator[](const int i){
	return arr[i];
}
template<typename T>
void Container::Add(T& elem){
	Objects** tmp = new Objects *[size];
	for (int i = 0; i < size; i++)	{
		tmp[i] = arr[i];
	}
	delete[]arr;
	size++;
	arr = new Objects *[size];
	for (int i = 0; i < size - 1; i++)	{
		arr[i] = tmp[i];
	}
	arr[size - 1] = &elem;
	delete[]tmp;
}
template<typename T> 
void Container::Delete(T& elem){
	Objects** tmp = new Objects *[size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)	{
		if (arr[i] == &elem){
			k = 1;
		}
		else{
			tmp[j] = arr[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] arr;
	arr = new Objects *[size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		arr[i] = tmp[i];
	delete tmp;
}
template<typename T>
void Container::Out(T& elem){
	cout << elem;
}
ostream& operator<<(ostream& out, Container& other){
	for (int i = 0; i < other.size; i++){
		out << *(other[i]) << endl;
	}
	return out;
}