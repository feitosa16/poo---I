#include <iostream>
using namespace std;

class Shape{
public: 
	virtual double calculateArea() const = 0; 
};
class Circle : public Shape{
private: 
	double radius;
public: 
	Circle(double r): radius(r){}

	double calculateArea() const override{
		return 3.14 * radius * radius;
}
};
class Rectangle : public Shape{
private: 
	double width;
	double height; 
public: 
	Rectangle(double w, double h) : width(w), height(h){}
	double calculateArea() const override{
	return width * height;
}
};

int main(){
	Circle c(5);
	Rectangle r(4,6);

cout << "Area do círculo: " <<c.calculateArea() << endl;
cout << "Area do retângulo: " <<r.calculateArea() <<endl;

return 0; 
}
