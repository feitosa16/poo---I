#include <iostream>
using namespace std;
// Super classe
class Animal {
public:
    void fazerSom() {
        cout << "Animal fazendo som..." << endl;
    }
};

// Subclasse Cachorro - herda a classe animal 
class Cachorro : public Animal {
public:
    void latir() {
        cout << "Cachorro latindo..." << endl;
    }
}; 

// Subclasse -Gato  herda a classe animal  
class Gato : public Animal{
public:
	void miar(){
cout<< "Gato miando..."<< endl;
    }
};
int main() {
    Cachorro meuCachorro;

    meuCachorro.fazerSom(); // Método da Superclasse
    meuCachorro.latir();    // Método da subclasse

Gato meuGato;
	meuGato.fazerSom(); // Método da superClasse
	meuGato.miar(); //Método da subclasse
    return 0;
}
