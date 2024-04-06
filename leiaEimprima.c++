#include <iostream> // Inclui a biblioteca que permite a entrada/saída de dados

int main() { // Função principal que é o ponto de entrada do programa
    float numFloat;
    int numInt;
    std::string frase;

    std::cout << "Digite um número float: ";
    std::cin >> numFloat; // Lê um float

    std::cout << "Digite um número inteiro: ";
    std::cin >> numInt; // Lê um inteiro

    std::cin.ignore(); // Ignora o '\n' do buffer de entrada após a leitura do inteiro

    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase); // Lê uma linha de texto, incluindo espaços

    std::cout << "Você digitou o decimal: " << numFloat << ", o inteiro: " << numInt << " e a frase: " << frase << std::endl;
    
    return 0; // Encerra o programa com sucesso
}