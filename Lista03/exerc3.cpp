#include <iostream> 
using namespace std;

//classe abstrata
class FormaGeometrica{
public: 
	virtual void desenhar() = 0;
};

//subclasses
class Quadrado: public FormaGeometrica{
public: 
	void desenhar()override{
cout << "Desenhando um quadrado" << endl; 
}
};

class Triangulo: public FormaGeometrica{
public:
	void desenhar() override{
	cout << "Desenhando um triangulo" <<endl; 
}
};

int main(){
	Quadrado quad;
	Triangulo tri;
    quad.desenhar();
    tri.desenhar();

return 0;
}
