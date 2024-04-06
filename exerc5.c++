#include <iostream>

class MeuInteiro {
private:
    int valor; // Atributo privado

public:
    // Construtor padrão
    MeuInteiro() {
        this->valor = 0; // Inicializa o valor com 0
    }

    // Construtor parametrizado
    MeuInteiro(int valor) {
        this->valor = valor; // Inicializa o valor com o argumento fornecido
    }

    // Método setter para definir o valor
    void setValor(int valor) {
        this->valor = valor; // O uso de 'this' diferencia o atributo do parâmetro
    }

    // Método getter para obter o valor
    int getValor() const {
        return this->valor; // Retorna o valor do atributo
    }
};

int main() {
    MeuInteiro objeto1; // Cria um objeto com o construtor padrão
    MeuInteiro objeto2(10); // Cria um objeto com o construtor parametrizado

    std::cout << "Valor do objeto1: " << objeto1.getValor() << std::endl; // Deve ser 0
    std::cout << "Valor do objeto2: " << objeto2.getValor() << std::endl; // Deve ser 10

    objeto1.setValor(5); // Define o valor de objeto1 usando o setter
    std::cout << "Novo valor do objeto1: " << objeto1.getValor() << std::endl; // Deve ser 5

    return 0;
}
