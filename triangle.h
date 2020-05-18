#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Triangle : public  Objects{
private:
	int height;
	T** arr;
public:
	Triangle();
	Triangle(int _height, T _mark);
	Triangle(const Triangle& triangle);
	~Triangle();
	int GetHeight();
	T GetMark();
	void SetHeight(int _height);
	float A();
	ostream& print(ostream& os);
	bool operator ==(const Triangle& other);
};
 Triangle<char>::Triangle(){
	height = 3;
	arr = new char * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new char[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = '*';
}
template<typename T>
 Triangle<T>::Triangle(int _height, T _mark){
	height = _height+1;
	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = _mark;
}
template<typename T>
 Triangle<T>::Triangle(const Triangle& triangle){
	if (arr != 0){
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
	}
	height = triangle.height;
	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = triangle.arr[i][j];
}
template<typename T>
 Triangle<T>::~Triangle(){
	if (arr != 0){
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		height = 0;
	}
}
template<typename T>
 int Triangle<T>::GetHeight(){
	return height-1;
}
template<typename T>
 T Triangle<T>::GetMark(){
	return T();
}
template<typename T>
 void Triangle<T>::SetHeight(int _height){
	T tmp = this->GetMark();
	if (arr != 0)	{
		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
	}
	height = _height+1;
	arr = new T * [height];
	for (int i = 0; i < height; i++)
		arr[i] = new T[height];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < i; j++)
			arr[i][j] = tmp;
}
 template<typename T>
 float Triangle<T>::A(){
	return ((height-1) * (height-1)) / 2;
}
template<typename T>
 ostream& Triangle<T>::print(ostream& os){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < i; j++)
			os << arr[i][j];
		os << endl;
	}
	return os;
}
template<typename T>
 bool Triangle<T>::operator==(const Triangle& other){
	if (height == other.height && arr[0][0] == other.arr[0][0])
		return true;
	return false;
}