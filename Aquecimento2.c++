#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Classe base abstrata para Forno
class Forno {
public:
    virtual ~Forno() {
        std::cout << "Destrutor do Forno chamado." << std::endl;
    }

    virtual void ajustarTemperatura(int novaTemperatura) = 0;
    virtual void consultarStatus() const = 0;
};

// Classe derivada para um Forno Elétrico
class FornoEletrico : public Forno {
private:
    int temperatura;
public:
    FornoEletrico() : temperatura(0) {}

    void ajustarTemperatura(int novaTemperatura) override {
        temperatura = novaTemperatura;
        std::cout << "Temperatura do Forno Elétrico ajustada para " << temperatura << " graus." << std::endl;
    }

    void consultarStatus() const override {
        std::cout << "Forno Elétrico está a " << temperatura << " graus." << std::endl;
    }
};

// Classe derivada para um Forno a Gás
class FornoGas : public Forno {
private:
    int temperatura;
public:
    FornoGas() : temperatura(0) {}

    void ajustarTemperatura(int novaTemperatura) override {
        temperatura = novaTemperatura;
        std::cout << "Temperatura do Forno a Gás ajustada para " << temperatura << " graus." << std::endl;
    }

    void consultarStatus() const override {
        std::cout << "Forno a Gás está a " << temperatura << " graus." << std::endl;
    }
};

// Método Factory para criar instâncias de Forno
std::unique_ptr<Forno> criarForno(int escolha) {
    if (escolha == 1) {
        return std::make_unique<FornoEletrico>();
    } else if (escolha == 2) {
        return std::make_unique<FornoGas>();
    }
    return nullptr;
}

int main() {
    std::unique_ptr<Forno> forno;
    int escolha = 0;

    // Menu para criar o forno
    std::cout << "Selecione o tipo de forno para criar:" << std::endl;
    std::cout << "1. Forno Elétrico" << std::endl;
    std::cout << "2. Forno a Gás" << std::endl;
    std::cin >> escolha;

    forno = criarForno(escolha);

    if (!forno) {
        std::cout << "Escolha inválida!" << std::endl;
        return 1;
    }

    // Menu para interação com o forno
    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Ajustar Temperatura" << std::endl;
        std::cout << "2. Consultar Status" << std::endl;
        std::cout << "3. Terminar Programa" << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                int temp;
                std::cout << "Informe a nova temperatura: ";
                std::cin >> temp;
                forno->ajustarTemperatura(temp);
                break;
            }
            case 2:
                forno->consultarStatus();
                break;
            case 3:
                std::cout << "Terminando programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (escolha != 3);

    return 0;
}
