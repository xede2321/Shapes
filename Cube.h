#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Cube : public  Objects{
private:
	int side;
	T*** arr;
public:
	Cube();
	Cube(int a, T _mark);
	Cube(const Cube& cube);
	~Cube();
	int GetSide();
	T GetMark();
	void SetSide(int _side);
	float A();
	ostream& print(ostream& os);
	bool operator ==(const Cube& other);
};
template<typename T>
 Cube<T>::Cube(){
	side = 1;
	arr = new T * *[side];
	for (int i = 0; i < side; i++)	{
		arr[i] = new T * [side];
		for (int j = 0; j < side; j++)
			arr[i][j] = new T[side];
	}
		arr[0][0][0] = '*';
}
template<typename T>
 Cube<T>::Cube(int a, T _mark){
	side = a;
	arr = new T * *[side];
	for (int i = 0; i < side; i++)	{
		arr[i] = new T * [side];
		for (int j = 0; j < side; j++)
			arr[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				arr[i][j][l] = _mark;
}
template<typename T>
 Cube<T>::Cube(const Cube& cube){
	if (arr != 0){
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] arr[i][j];
		for (int i = 0; i < side; i++)
			delete[] arr[i];
		delete[] arr;
	}
	side = cube.side;
	arr = new T * *[side];
	for (int i = 0; i < side; i++)	{
		arr[i] = new T * [side];
		for (int j = 0; j < side; j++)
			arr[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				arr[i][j][l] = cube.arr[i][j][l];
}
template<typename T>
 Cube<T>::~Cube(){
	if (arr != 0){
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] arr[i][j];
		for (int i = 0; i < side; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		side = 0;
	}
}
template<typename T>
 int Cube<T>::GetSide(){
	return side;
}
 template<typename T>
 T Cube<T>::GetMark(){
	return arr[0][0][0];
}
 template<typename T>
 void Cube<T>::SetSide(int _side){
	T tmp = arr[0][0][0];
	if (arr != 0)	{
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] arr[i][j];
		for (int i = 0; i < side; i++)
			delete[] arr[i];
		delete[] arr;
	}
	side = _side;
	arr = new T * *[side];
	for (int i = 0; i < side; i++)	{
		arr[i] = new T * [side];
		for (int j = 0; j < side; j++)
			arr[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				arr[i][j][l] = tmp;
}
template<typename T>
 float Cube<T>::A(){
	return side*side*6;
}
template<typename T>
 ostream& Cube<T>::print(ostream& os){
	Square<T> tmp(side, arr[0][0][0]);
	tmp.print(os);
	return os;
}
template<typename T>
 bool Cube<T>::operator==(const Cube& other){
	if (side == other.side && arr[0][0][0] == other.arr[0][0][0])
		return true;
	return false;
}