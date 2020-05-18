#include <iostream>
#include "Container.h"
using namespace std;
int main(){
	Container C;
	Point<char> point;
	Line<char> line(10,'*');
	Square<int> square(3, 1);
	Rectangle<int> rectangle(3, 6, 1);
	Triangle<char> triangle(7, '*');
	Circle<char> circle(5,'*');
	Cube<char> cube(3, '*');
	C.Add(point);
	C.Add(line);
	C.Add(square);
	C.Add(rectangle);
	C.Add(triangle);
	C.Add(circle);
	C.Add(cube);
	cout << "point:" << endl;
	C.Out(point); 
	cout << endl;
	cout << "line:" << endl;
	C.Out(line);
	cout << endl;
	cout << "square:" << endl;
	C.Out(square);
	cout << endl;
	cout << "rectangle:" << endl;
	C.Out(rectangle);
	cout << endl;
	cout << "triangle:" << endl;
	C.Out(triangle);
	cout << endl;
	cout << "circle:" << endl;
	C.Out(circle);
	cout << endl;
	cout << "cube:" << endl;
	C.Out(cube);
	return 0;
}