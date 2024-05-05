#include <iostream>
using namespace std;
// Super classe
class Animal {
public:
    void fazerSom() {
        cout << "Animal fazendo som..." << endl;
    }
};

// Subclasse - herda a classe animal 
class Cachorro : public Animal {
public:
    void latir() {
        cout << "Cachorro latindo..." << endl;
    }
};

int main() {
    Cachorro meuCachorro;
    meuCachorro.fazerSom(); // Método da Superclasse
    meuCachorro.latir();    // Método da subclasse
    return 0;
}
