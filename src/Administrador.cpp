#include "Administrador.hpp"


Administrador::Administrador(){

}

Administrador::~Administrador(){
    
}

void Administrador::editaPostagem(unsigned int idPostagem){ // vem da classe usuario e administrador
    if ( idPostagem < 0 || idPostagem > this->listageral->getTamanho() - 1){
        std::cout << "Postagem não encontrada" << std::endl;
        return;
    }

    database::Post *post {this->listageral->getPost(idPostagem)};

    std::cout <<"Escolha o que deseja editar: \n";
    std::cout <<"0 - Titulo\n";
    std::cout <<"1 - Link\n";
    std::cout <<"2 - Descricao\n";
    std::cout <<"3 - Permissao\n";
    std::cout <<"4 - Cancelar\n";

    unsigned int opcao;
    std::cin >> opcao;

    if (opcao < 0 || opcao > 4){
        std::cout << "Opção inválida" << std::endl;
        return;
    } 

    std::string input;
    int permissao {-1};

    switch (opcao){
        case 0 :
            std::cout << "Titulo: ";
            std::getline(std::cin, input);
            post->setTitulo(input);
        break;

        case 1 :
            std::cout << "Link: ";
            std::getline(std::cin, input);
            post->setLink(input);
        break;
           
        case 2 :
            std::cout << "Descricao: ";
            std::getline(std::cin, input);
            post->setDescricao(input);
        break;

        case 3 :
            std::cout << "Privacidade do post: '0'-publica || '1'-Privada\n";

            do {
                std::cin >> input;
                
                try {
                    permissao = stoi(input);
                    if (permissao != 0 && permissao != 1) {
                        std::cout << 
                            "Valor inválido. Por favor, insira 0 ou 1." 
                            << std::endl;
                    }
                } catch (const std::invalid_argument &e) {
                    std::cout << "Valor inválido. Por favor, insira um número inteiro." << std::endl;
                }
            } while (permissao != 0 && permissao != 1);
            
            if ( permissao == 0 )
                post->setPermissao(database::Permissao::PUBLIC);
            else
                post->setPermissao(database::Permissao::PRIVATE);
        break;

        case 4 :
            std::cout << "Cancelando edição" << std::endl;
        break;

        default :
            std::cout << "Opção inválida" << std::endl;
        break;
    }
}

void Administrador::removePostagem(unsigned int idPostagem){ // vem da classe usuario e administrador
    database::Post *post {this->listageral->getPost(idPostagem)};
    
    if (post != nullptr)
        Visitante::listageral->remover(*post);
}

void Administrador::verPostagem(const unsigned int id) const{
	database::Post * p = Visitante::listageral->getPost(id);
	if (p == nullptr){
		throw database::IdInvalidoException(id);
	}
	std::cout << *p;
}

void Administrador::visualizaPostagensDeOutros(){ // (pode ver as privadas e publicas)
    Administrador::listageral->printList("Visitante", database::Permissao::PUBLIC);
    Administrador::listageral->printList("Visitante", database::Permissao::PRIVATE);
}


const database::Post *Administrador::getPost(unsigned int idPostagem) const {
    return Administrador::listageral->getPost(idPostagem);
}