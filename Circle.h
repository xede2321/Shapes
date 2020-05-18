#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Circle : public Objects{
private:
	int radius;
	T** arr;
public:
	Circle();
	Circle(int r, T _mark);
	Circle(const Circle& circle);
	~Circle();
	int GetRadius();
	T GetMark();
	void SetRadius(int _radius);
	float A() ;
	ostream& print(ostream& os);
	bool operator ==(const Circle& other);
};
 Circle<char>::Circle(){
	radius = 0;
	arr = new char * [radius];
	for (int i = 0; i < radius; i++)
		arr[i] = new char[radius];
	for (int i = 0; i < radius; i++)
		for (int j = radius - i; j < radius + i + 1; j++)
			arr[i][j] = '*';
	for (int i = radius; i < 2 * radius; i++)
		for (int j = 1 + i - radius; j < 3 * radius - i; j++)
			arr[i][j] = '*';
}
template<typename T>
 Circle<T>::Circle(int r, T _mark){
	radius = r;
	arr = new T* [2 * radius - 1];
	for (int i = 0; i < 2 * radius - 1; i++)
		arr[i] = new T[2 * radius];
	for (int i = 0; i < radius; i++)
		for (int j = radius - 1 - i; j < radius + i + 1; j++)
			arr[i][j] = _mark;
	for (int i = radius; i < 2 * radius - 1; i++)
		for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
			arr[i][j] = _mark;
}
template<typename T>
 Circle<T>::Circle(const Circle& circle){
	if (arr != 0)	{
		for (int i = 0; i < 2 * radius; i++)
			delete[] arr[i];
		delete[] arr;
	}
	radius = circle.radius;
	arr = new T * [2 * radius];
	for (int i = 0; i < 2 * radius; i++)
		arr[i] = new T[2 * radius];

	for (int i = 0; i < radius; i++)
		for (int j = radius; j < radius + i + 1; j++)
			arr[i][j] = circle.arr[i][j];

	for (int i = radius; i < 2 * radius ; i++)
		for (int j = 1 + i - radius; j < 3 * radius; j++)
			arr[i][j] = circle.arr[i][j];
}
template<typename T>
 Circle<T>::~Circle(){
	if (arr != 0)	{
		for (int i = 0; i < 2 * radius ; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		radius = 0;
	}
}
template<typename T>
 int Circle<T>::GetRadius(){
	return radius;
}
template<typename T>
 T Circle<T>::GetMark(){
	return arr[radius][radius];
}
template<typename T>
 void Circle<T>::SetRadius(int _radius){
	T tmp = this->GetMark();
	if (arr != 0){
		for (int i = 0; i < 2 * radius; i++)
			delete[] arr[i];
		delete[] arr;
	}
	radius = _radius;
	arr = new T * [2 * radius];
	for (int i = 0; i < 2 * radius; i++)
		arr[i] = new T[2 * radius];
	for (int i = 0; i < radius; i++)
		for (int j = radius  - i; j < radius + i + 1; j++)
			arr[i][j] = tmp;
	for (int i = radius; i < 2 * radius ; i++)
		for (int j = 1 + i - radius; j < 3 * radius - i; j++)
			arr[i][j] = tmp;
}
template<typename T>
 float Circle<T>::A(){
	return radius*radius*3.14;
}
template<typename T>
 ostream& Circle<T>::print(ostream& os){
	for (int i = 0; i < 2 * radius; i++){
		for (int j = 0; j < 2 * radius; j++){
			if ((i < radius  && j >=(radius - 1 - i) && j < (radius + i + 1)) || (i >=  radius && i < (2 * radius - 1) && j >=(1 + i - radius) && j < (3 * radius - 1 - i)))
				os << arr[i][j];
			else os << " ";
		}
		os << endl;
	}
	return os;
}
 template<typename T>
 bool Circle<T>::operator==(const Circle& other){
	if (radius == other.radius && arr[radius][radius] == other.arr[radius][radius])
		return true;
	return false;
}