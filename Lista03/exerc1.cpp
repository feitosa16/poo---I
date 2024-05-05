#include <iostream>
using namespace std;
//Superclasse
class Automovel{
public: 
	void ligar(){
cout << "Automóvel ligado." << endl;
}
void desligar(){
cout << "Automóvel desligado." << endl;
}
};
class Carro: public Automovel{
public: 
void dirigir(){
cout << "Carro em movimento."<< endl;
} 
};

int main(){
	Carro automovelCarro;
	automovelCarro.ligar();
	automovelCarro.desligar();
    automovelCarro.dirigir();
	
return 0;
}
