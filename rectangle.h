#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Rectangle : public  Objects{
private:
	int side1;
	int side2;
	T** arr;
public:
	Rectangle();
	Rectangle(int _side1, int _side2, T _mark);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();
	int GetSide1();
	int GetSide2();
	T GetMark();
	void SetSide(int _side1, int _side2);
	float A();
	ostream& print(ostream& os);
	bool operator ==(const Rectangle& other);
};
 Rectangle<char>::Rectangle(){
	side1 = 1;
	side2 = 1;
	arr = new char* [1];
	arr[0] = new char[1];
	arr[0][0] = '*';
}
template<typename T>
 Rectangle<T>::Rectangle(int _side1, int _side2, T _mark){
	side1 = _side1;
	side2 = _side2;
	arr = new T * [side1];
	for (int i = 0; i < side1; i++)
		arr[i] = new T[side2];

	for (int i = 0; i < side1; i++)
		for (int j = 0; j < side2; j++)
			arr[i][j] = _mark;
}
template<typename T>
 Rectangle<T>::Rectangle(const Rectangle& rectangle){
	 if (arr != 0)	 {
		 for (int i = 0; i < side1; i++)
			 delete[] arr[i];
		 delete[] arr;
	 }
	 side1 = rectangle.side1;
	 side2 = rectangle.side2;
	 arr = new T * [side1];
	 for (int i = 0; i < side1; i++)
		 arr[i] = new T[side2];
	 for (int i = 0; i < side1; i++)
		 for (int j = 0; j < side2; j++)
			 arr[i][j] = rectangle.arr[i][j];
}
template<typename T>
 Rectangle<T>::~Rectangle(){
	if (arr != 0)	{
		for (int i = 0; i < side1; i++)
			delete[] arr[i];
		delete[] arr;
		arr = 0;
		side1 = 0;
		side2 = 0;
	}
}
template<typename T>
 int Rectangle<T>::GetSide1(){
	return side1;
}
template<typename T>
 int Rectangle<T>::GetSide2(){
	return side2;
}
 template<typename T>
 T Rectangle<T>::GetMark(){
	return arr[0][0];
}
 template<typename T>
 void Rectangle<T>::SetSide(int _side1, int _side2){
	T tmp = arr[0][0];
	if (arr != 0){
		for (int i = 0; i < side1; i++)
			delete[] arr[i];
		delete[] arr;
	}
	side1 = _side1;
	side2 = _side2;
	arr = new T * [side1];
	for (int i = 0; i < side1; i++)
		arr[i] = new T[side2];
	for (int i = 0; i < side1; i++)
		for (int j = 0; j < side2; j++)
			arr[i][j] = tmp;
}
 template<typename T>
 float Rectangle<T>::A(){
	return side1*side2;
}
template<typename T>
 ostream& Rectangle<T>::print(ostream& os){
	for (int i = 0; i < side1; i++){
		for (int j = 0; j < side2; j++)
			os << arr[i][j];
		os << endl;
	}
	return os;
}
template<typename T>
 bool Rectangle<T>::operator==(const Rectangle& other){
	if (side1 == other.side1 && side2 == other.side2 && arr[0][0] == other.arr[0][0])
		return true;
	return false;
}