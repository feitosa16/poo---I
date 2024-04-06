#include <iostream>

class Tabuada1 {
private:
    int numero;

public:
    // Construtor parametrizado
    Tabuada1(int numero) {
        this->numero = numero;
    }

    // Setter
    void setNumero(int numero) {
        this->numero = numero;
    }

    // Getter
    int getNumero() const {
        return numero;
    }

    // Método para imprimir a tabuada de adição
    void adicao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " + " << i << " = " << numero + i << std::endl;
        }
    }

    // Método para imprimir a tabuada de subtração
    void subtracao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " - " << i << " = " << numero - i << std::endl;
        }
    }

    // Método para imprimir a tabuada de multiplicação
    void multiplicacao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " * " << i << " = " << numero * i << std::endl;
        }
    }

    // Método para imprimir a tabuada de divisão
    void divisao() const {
        if (numero == 0) {
            std::cout << "Erro: Divisão por zero." << std::endl;
            return;
        }
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " / " << i << " = " << numero / (double)i << std::endl;
        }
    }
};

int main() {
    Tabuada1 *objeto = new Tabuada1(5); // Alocação dinâmica do objeto

    objeto->adicao(); // Exibe a tabuada de adição
    std::cout << std::endl;
    
    objeto->subtracao(); // Exibe a tabuada de subtração
    std::cout << std::endl;

    objeto->multiplicacao(); // Exibe a tabuada de multiplicação
    std::cout << std::endl;

    objeto->divisao(); // Exibe a tabuada de divisão
    std::cout << std::endl;

    objeto->setNumero(0); // Testa a mensagem de erro para divisão por zero
    objeto->divisao(); // Tentativa de exibir a tabuada de divisão

    delete objeto; // Libera a memória alocada para o objeto

    return 0;
}
