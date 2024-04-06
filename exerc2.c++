#include <iostream> 
int main() { 
    float numFloat;
    int numInt;
    std::string frase;

    std::cout << "Digite um número float: ";
    std::cin >> numFloat; 

    std::cout << "Digite um número inteiro: ";
    std::cin >> numInt; 

    std::cin.ignore(); 

    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase); 

    std::cout << "Você digitou o decimal: " << numFloat << ", o inteiro: " << numInt << " e a frase: " << frase << std::endl;
    
    return 0;
}