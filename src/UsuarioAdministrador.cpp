#include "UsuarioAdministrador.hpp"


UsuarioAdministrador::UsuarioAdministrador(){

}

UsuarioAdministrador::~UsuarioAdministrador(){

}

void UsuarioAdministrador::editaPostagem(const unsigned int idPostagem){ // vem da classe usuario e administrador
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


    database::Post *post {nullptr};

    post = this->minhasPostagens->getPost(idPostagem);

    if(post == nullptr){
        throw database::IdInvalidoException(idPostagem);
    }
    
    std::cout << "Escolha o que deseja editar: \n";
    std::cout << "0 - Titulo\n";
    std::cout << "1 - Link\n";
    std::cout << "2 - Descricao\n";
    std::cout << "3 - database::Permissao\n";
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

void UsuarioAdministrador::removePostagem(const unsigned int idPostagem){
    database::Post *post {this->listageral->getPost(idPostagem)};
    if (post != nullptr){
        Visitante::listageral->remover(*post);
        this->minhasPostagens->remover(*post);
    }
}

void UsuarioAdministrador::verPostagem(const unsigned int id) const{
	database::Post * p = Visitante::listageral->getPost(id);
	if (p == nullptr){
		throw database::IdInvalidoException(id);
	}
	std::cout << *p;
}

void UsuarioAdministrador::visualizaPostagensDeOutros(){
    UsuarioAdministrador::listageral->printList("Admin", database::Permissao::PUBLIC);
}

const database::Post *UsuarioAdministrador::getPost(const unsigned int idPostagem) const{
    return this->listageral->getPost(idPostagem);
}

void UsuarioAdministrador::save() const{
	std::ofstream arquivosaida("../adms/" + this->nome);
	if (!arquivosaida){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	arquivosaida << this->nome << "\n";
	arquivosaida << this->email << "\n";
	arquivosaida << this->senha << "\n";
	arquivosaida << this->dataDeNascimento << "\n";
	arquivosaida.close();
	this->minhasPostagens->saveCompact("../adms/" + this->nome);
}

void UsuarioAdministrador::load(){
	std::ifstream arquivoentrada("../adms/" + this->nome);
  	if (!arquivoentrada) {
    	throw std::runtime_error("Arquivo não encontrado");
  	}
	std::getline(arquivoentrada, this->nome);
	//std::cerr << this->nome << "\n";
	std::getline(arquivoentrada, this->email);
	//std::cerr << this->email << "\n";
	std::getline(arquivoentrada, this->senha);
	//std::cerr << this->senha << "\n";
	std::getline(arquivoentrada, this->dataDeNascimento);
	//std::cerr << this->dataDeNascimento << "\n";
	size_t tam = 0; 
	arquivoentrada >> tam;
	//std::cerr << tam << "\n";
	for (size_t i = 0; i < tam; ++i){
		int index;
		arquivoentrada >> index;
		//	std::cerr << index << "\n";
		this->minhasPostagens->adicionar(listageral->getPost(index));
		//std::cerr << "adicionado elemento no usuario\n";
	}
}