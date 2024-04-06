#include <iostream>

// Enumeração para as operações matemáticas
enum OPERACAO {
    ADICAO, SUBTRACAO, MULTIPLICACAO, DIVISAO
};

class Tabuada2 {
private:
    int numero;
    OPERACAO operacao;

    // Métodos privativos para execução de cada tabuada
    void tabuadaAdicao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " + " << i << " = " << numero + i << std::endl;
        }
    }

    void tabuadaSubtracao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " - " << i << " = " << numero - i << std::endl;
        }
    }

    void tabuadaMultiplicacao() const {
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " * " << i << " = " << numero * i << std::endl;
        }
    }

    void tabuadaDivisao() const {
        if (numero == 0) {
            std::cout << "Erro: Divisão por zero." << std::endl;
            return;
        }
        for (int i = 1; i <= 10; ++i) {
            std::cout << numero << " / " << i << " = " << numero / (double)i << std::endl;
        }
    }

public:
    // Construtor parametrizado com valores padrão
    Tabuada2(int numero = 1, OPERACAO operacao = ADICAO) {
        this->numero = numero;
        this->operacao = operacao;
    }

    // Setters e Getters
    void setNumero(int numero) {
        this->numero = numero;
    }

    void setOperacao(OPERACAO operacao) {
        this->operacao = operacao;
    }

    int getNumero() const {
        return numero;
    }

    OPERACAO getOperacao() const {
        return operacao;
    }

    // Método público para imprimir a tabuada conforme a operação definida
    void imprimirTabuada() const {
        switch (operacao) {
            case ADICAO:
                tabuadaAdicao();
                break;
            case SUBTRACAO:
                tabuadaSubtracao();
                break;
            case MULTIPLICACAO:
                tabuadaMultiplicacao();
                break;
            case DIVISAO:
                tabuadaDivisao();
                break;
        }
    }
};

int main() {
    Tabuada2 *objeto = new Tabuada2(); // Alocação dinâmica com valores padrão

    objeto->imprimirTabuada(); // Imprime a tabuada de adição (padrão)
    std::cout << std::endl;

    objeto->setNumero(10);
    objeto->setOperacao(MULTIPLICACAO);
    objeto->imprimirTabuada(); // Imprime a tabuada de multiplicação para 10
    std::cout << std::endl;

    objeto->setNumero(0);
    objeto->setOperacao(DIVISAO);
    objeto->imprimirTabuada(); // Testa a mensagem de erro para divisão por zero

    delete objeto; // Libera a memória alocada para o objeto

    return 0;
}
