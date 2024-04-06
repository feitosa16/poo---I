#include <iostream>

class meuInteiro {
private:
    int valor; // Atributo privado

public:
    // Método para ler o valor do console e definir o atributo
    void lerEsetarValor() {
        std::cout << "Digite um inteiro: ";
        std::cin >> valor; // Lê o valor diretamente para o atributo privado
    }

    // Método getter para obter o valor
    int getValor() const {
        return valor; // Retorna o valor do atributo
    }
};

int main() {
    meuInteiro objeto; 

    objeto.lerEsetarValor(); 

    std::cout << "O valor é: " << objeto.getValor() << std::endl; // Exibe o valor usando o método getter

    return 0;
}
