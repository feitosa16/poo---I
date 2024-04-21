#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <istream>



class Menu{
private:
    std::vector<std::string>opcoes;
    std::string titulo; 
    bool temTitulo; //verifivacao de titulo 

    public:
    Menu(std::string titulo = ""){
        if (titulo != ""){
            this -> titulo = titulo; 
            this -> temTitulo = true; 
        } else{
            this -> temTitulo = false; 
        }
    }
    void adicionaOpcao(const std::string & opcao){
        opcoes.push_back(opcao);
    }


void display() const{
    if (temTitulo){
        std::cout<<"==== "<< titulo << " ====" << std::endl; 
    }
    for (int i = 0; i < opcoes.size(); i++){
        std::cout <<(i+1)<< ". " << opcoes[i]<< std::endl;
    }
    if(opcoes.empty()) {
        std::cout << "Sem opções disponíveis";
    }
    std:: cout<< std::endl; 
}
    int getEscolha() const{
        int escolha = 0;
        std::cout << "Digite sua escolha: "; 
        while(!(std::cin>>escolha) || escolha < 1 || escolha > opcoes.size()){
            std::cout << "Escolha inválida. Por favor, tente novamente"; 
            std:: cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return escolha;     
        
    }

};

int main(){
    Menu menu("Menu Principal");
    menu.adicionaOpcao("OpçÃO 1: Faça algo"); 
    menu.adicionaOpcao("Opção 2: Faça outra coisa ");
    menu.adicionaOpcao("Opção 3: Saída");



    while (true) {
        menu.display();
        int escolha = menu.getEscolha();
        switch (escolha) {
            case 1:
                std::cout << "Fazendo algo..." << std::endl;
                break;
            case 2:
                std::cout << "Fazendo outra coisa..." << std::endl;
                break;
            case 3:
                std::cout << "Saindo..." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida, tente novamente" << std::endl;
        }
    }

    return 0; 
}