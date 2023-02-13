#include "UsuarioAdministrador.hpp"


UsuarioAdministrador::UsuarioAdministrador(){

}

UsuarioAdministrador::~UsuarioAdministrador(){

}

void UsuarioAdministrador::editaPostagem(unsigned int idPostagem){ // vem da classe usuario e administrador
    std::cout << "Que postagem editar?" << std::endl;
    std::cout << "0 - Minhas" << std::endl;
    std::cout << "1 - Outros" << std::endl;

    short int opcaoPostagem;

    do {
        try {
            std::cin >> opcaoPostagem;
            
            if (opcaoPostagem < 0 && opcaoPostagem > 1){
                std::cout << 
                    "Valor inválido. Por favor, insira 0 ou 1." 
                    << std::endl;
            }
        }
        catch (std::invalid_argument &e) {
            std::cout << 
                "Valor inválido. Por favor, insira um número inteiro." 
                << std::endl;
        }

    } while (opcaoPostagem < 0 && opcaoPostagem > 1);


    Post *post {nullptr};
    bool idValido {idPostagem >= 0};

    if ( opcaoPostagem == 0 ){
        idValido = idValido && idPostagem < this->minhasPostagens->getTamanho();
        
        if ( idValido )
            post = this->minhasPostagens->getPost(idPostagem);

        else {
            std::cout << "Postagem não encontrada" << std::endl;
            return;
        }
    }
    else {
        idValido = idValido && idPostagem < this->listageral->getTamanho();

        if ( idValido )
            post = this->minhasPostagens->getPost(idPostagem);

        else { 
                std::cout << "Postagem não encontrada" << std::endl;
                return;
        }
    }

    std::cout << "Escolha o que deseja editar: \n";
    std::cout << "0 - Titulo\n";
    std::cout << "1 - Link\n";
    std::cout << "2 - Descricao\n";
    std::cout << "3 - Permissao\n";
    std::cout << "4 - Cancelar\n";

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
                post->setPermissao(Permissao::PUBLIC);
            else
                post->setPermissao(Permissao::PRIVATE);
        break;

        case 4 :
            std::cout << "Cancelando edição" << std::endl;
        break;

        default :
            std::cout << "Opção inválida" << std::endl;
        break;
    }
}

void UsuarioAdministrador::removePostagem(unsigned int idPostagem){
    Post *post {this->listageral->getPost(idPostagem)};
    if (post != nullptr){
        Visitante::listageral->remover(*post);
        this->minhasPostagens->remover(*post);
    }
}

void UsuarioAdministrador::visualizaPostagensDeOutros(){
    UsuarioAdministrador::listageral->printList("UsuarioAdministrador", Permissao::PUBLIC);
    UsuarioAdministrador::listageral->printList("UsuarioAdministrador", Permissao::PRIVATE);
}

const Post *UsuarioAdministrador::getPost(unsigned int idPostagem) const{
    return this->listageral->getPost(idPostagem);
}