#include <iostream>

class tabuada1 {
private:
    int numero;

public:
    // Construtor parametrizado
    tabuada1(int numero) {
        this->numero = numero;
    }

    // Setter para o número
    void setNumero(int numero) {
        this->numero = numero;
    }

    // Getter para o número
    int getNumero() const {
        return this->numero;
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
            std::cout << "Erro: Divisão por zero não é possível." << std::endl;
            return;
        }
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " / " << i << " = " << numero / static_cast<double>(i) << std::endl;
        }
    }
};

int main() {
    tabuada1 *tabuada = new tabuada1(6); // Aloca dinamicamente um objeto com o número 5

    std::cout << "Tabuada de adição:" << std::endl;
    tabuada->adicao(); // Imprime a tabuada de adição

    std::cout << "Tabuada de subtração:" << std::endl;
    tabuada->subtracao(); // Imprime a tabuada de subtração

    std::cout << "Tabuada de multiplicação:" << std::endl;
    tabuada->multiplicacao(); // Imprime a tabuada de multiplicação

    std::cout << "Tabuada de divisão:" << std::endl;
    tabuada->divisao(); // Imprime a tabuada de divisão

    delete tabuada; // Libera a memória alocada para o objeto

    return 0;
}
