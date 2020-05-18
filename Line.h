#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Line: public  Objects{
private:
    int length;
	T* Array;
public:
	Line();
	Line(int len, T _mark);
	Line(const Line& line);
	~Line();
	int GetLen();
	T GetMark();
	void SetLen(int len);
	float A() ;
	ostream& print(ostream& os);
	bool operator ==(const Line& other);
};
template<typename T>
 Line<T>::Line(){
	length = 10;
	Array = new char [length];
	for (int i = 0; i < length; i++)
		Array[i] = "*";
}
template<typename T>
 Line<T>::Line(int len, T _mark){
	length = len;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = _mark;
}
template<typename T>
 Line<T>::Line(const Line& line){
	if (Array != 0)
		delete[] Array;
	length = line.length;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = line.Array[i];
}
template<typename T>
 Line<T>::~Line(){
	if (Array != 0){
		delete[] Array;
		Array = 0;
		length = 0;
	}
}
template<typename T>
 int Line<T>::GetLen(){
	return length;
}
template<typename T>
 T Line<T>::GetMark(){
	return Array[0];
}
template<typename T>
 void Line<T>::SetLen(int len){
	T tmp = Array[0];
	if (Array != 0)
		delete[] Array;
	length = len;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = tmp;
}
template<typename T>
 float Line<T>::A(){
	return 0;
}
template<typename T>
 ostream& Line<T>::print(ostream& os){
	for (int i = 0; i < length; i++)
		os << Array[i];
	os << endl;
	return os;
}
template<typename T>
 bool Line<T>::operator==(const Line& other){
	if (length == other.length && Array[0] == other.Array[0])
		return true;
	return false;
}