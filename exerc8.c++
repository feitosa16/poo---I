#include <iostream>
#include <string>

class Forno {
private:
    float temperatura;

public:
    Forno(float temperatura = 0.0f) {
        setTemperatura(temperatura);
    }

    void setTemperatura(float temperatura) {
        if (temperatura < 0.0f) {
            this->temperatura = 0.0f;
        } else if (temperatura > 280.0f) {
            this->temperatura = 280.0f;
        } else {
            this->temperatura = temperatura;
        }
    }

    float getTemperatura() const {
        return temperatura;
    }

    virtual void getStatus() const {
        std::cout << "Forno cozinhando a " << temperatura << " graus" << std::endl;
    }
};

class FornoEletrico : public Forno {
private:
    int potenciaWatts;

public:
    FornoEletrico(float temperatura, int potenciaWatts) : Forno(temperatura), potenciaWatts(potenciaWatts) {}

    void getStatus() const override {
        Forno::getStatus();
        std::cout << "Tipo: Elétrico, Potência: " << potenciaWatts << " Watts" << std::endl;
    }
};

class FornoAGas : public Forno {
private:
    std::string tipoGas;

public:
    FornoAGas(float temperatura, std::string tipoGas) : Forno(temperatura), tipoGas(tipoGas) {}

    void getStatus() const override {
        Forno::getStatus();
        std::cout << "Tipo: A gás, Gás: " << tipoGas << std::endl;
    }
};

class FornoALenha : public Forno {
private:
    std::string madeiraUsada;

public:
    FornoALenha(float temperatura, std::string madeiraUsada) : Forno(temperatura), madeiraUsada(madeiraUsada) {}

    void getStatus() const override {
        Forno::getStatus();
        std::cout << "Tipo: À lenha, Madeira: " << madeiraUsada << std::endl;
    }
};

// Derivações adicionais como exemplo
class FornoInducao : public FornoEletrico {
private:
    int nivelInducao;

public:
    FornoInducao(float temperatura, int potenciaWatts, int nivelInducao) : FornoEletrico(temperatura, potenciaWatts), nivelInducao(nivelInducao) {}

    void getStatus() const override {
        FornoEletrico::getStatus();
        std::cout << "Indução Nível: " << nivelInducao << std::endl;
    }
};

class FornoGasPetroleo : public FornoAGas {
private:
    bool temSensor;

public:
    FornoGasPetroleo(float temperatura, std::string tipoGas, bool temSensor) : FornoAGas(temperatura, tipoGas), temSensor(temSensor) {}

    void getStatus() const override {
        FornoAGas::getStatus();
        std::cout << "Sensor de Segurança: " << (temSensor ? "Sim" : "Não") << std::endl;
    }
};

int main() {
    Forno* forno = new Forno(100);
    FornoEletrico* fornoEletrico = new FornoEletrico(180, 1500);
    FornoAGas* fornoAGas = new FornoAGas(200, "Natural");
    FornoALenha* fornoALenha = new FornoALenha(250, "Carvalho");
    FornoInducao* fornoInducao = new FornoInducao(220, 2000, 5);
    FornoGasPetroleo* fornoGasPetroleo = new FornoGasPetroleo(210, "Propano", true);

    forno->getStatus();
    fornoEletrico->getStatus();
    fornoAGas->getStatus();
    fornoALenha->getStatus();
    fornoInducao->getStatus();
    fornoGasPetroleo->getStatus();

    delete forno;
    delete fornoEletrico;
    delete fornoAGas;
    delete forno;
}