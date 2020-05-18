#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Square : public  Objects{
private:
	int side;
	T** Array;
public:
	Square();
	Square(int a, T _mark);
	Square(const Square& square);
	~Square();
	int GetSide();
	T GetMark();
	void SetSide(int _side);
	float A();
	ostream& print(ostream& os);
	bool operator ==(const Square& other);
};
 Square<char>::Square(){
	side = 1;
	Array = new char * [1];
    Array [0] = new char[1];
	Array[0][0] = '*';
}
template<typename T>
 Square<T>::Square(int a, T _mark){
	side = a;
	Array = new T * [side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];
	for (int i=0; i<side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = _mark;
}
template<typename T>
 Square<T>::Square(const Square& square){
	if (Array != 0)	{
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = square.side;
	Array = new T * [side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = square.Array[i][j];
}
template<typename T>
 Square<T>::~Square(){
	if (Array != 0){
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		side = 0;
	}
}
 template<typename T>
 int Square<T>::GetSide(){
	return side;
}
template<typename T>
 T Square<T>::GetMark(){
	return Array[0][0];
}
template<typename T>
 void Square<T>::SetSide(int _side){
	T tmp = Array[0][0];
	if (Array != 0){
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = _side;
	Array = new T * [side];
	for (int i = 0; i < side; i++)
		Array[i] = new T[side];
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			Array[i][j] = tmp;
}
template<typename T>
 float Square<T>::A(){
	return side * side;
}
template<typename T>
 ostream& Square<T>::print(ostream& os){
	for (int i = 0; i < side; i++){
		for (int j = 0; j < side; j++)
			os << Array[i][j];
		os << endl;
	}
	return os;
}

template<typename T>
 bool Square<T>::operator==(const Square& other){
	if (side == other.side && Array[0][0]==other.Array[0][0])
		return true;
	return false;
}
