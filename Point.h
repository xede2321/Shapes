#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <typename T>
class Point : public  Objects{
private:
	T mark;
public:
	Point();
	Point(T _mark);
	Point(const Point& point);
	T Get();
	float A() ;
	ostream& print(ostream& os) ;
	bool operator ==(const Point& other);
};
template<typename T>
 Point<T>::Point(){
	mark = '.';
}
template<typename T>
 Point<T>::Point(T _mark){
	mark = _mark;
}
template<typename T>
 Point<T>::Point(const Point& point){
	mark = point.mark;
}
template<typename T>
 T Point<T>::Get(){
	return mark;
}
template<typename T>
 float Point<T>::A(){
	return 0;
}
template<typename T>
 ostream& Point<T>::print(ostream& os){
	os << this->Get();
	os << endl;
	return os;
}
template<typename T>
 bool Point<T>::operator==(const Point& other){
	if (mark==other.mark)
		return true;
	return false;
}