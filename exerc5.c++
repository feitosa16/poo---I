#include <iostream>
#include <string>

class MinhaClasse {
private:
    std::string texto;

public:
    // Construtor padrão com parâmetro default
    MinhaClasse(std::string texto = "Unicamp") : texto(texto) {}

    // Getter para o texto
    std::string getTexto() const {
        return this->texto;
    }

    // Setter para o texto
    void setTexto(const std::string& texto) {
        this->texto = texto;
    }
};

int main() {
    // Criação dinâmica de um objeto com o valor default
    MinhaClasse* obj1 = new MinhaClasse();
    std::cout << "Texto em obj1: " << obj1->getTexto() << std::endl;

    // Criação dinâmica de um objeto com valor definido
    MinhaClasse* obj2 = new MinhaClasse("Outro texto");
    std::cout << "Texto em obj2: " << obj2->getTexto() << std::endl;

    // Modificação do texto em obj1
    obj1->setTexto("Novo texto");
    std::cout << "Texto modificado em obj1: " << obj1->getTexto() << std::endl;

    // Liberação da memória alocada para os objetos
    delete obj1;
    delete obj2;

    return 0;
}
