#include "Usuario.hpp"
#include <ctype.h>
#include <filesystem>

Usuario::Usuario(){
    this->minhasPostagens = new database::Listadepostagens{};
}

Usuario::~Usuario(){
}


void Usuario::fazPostagem(){
	std::cin.ignore(1000,'\n');
    std::cout << "Titulo: ";
    std::string titulo;
    std::getline(std::cin, titulo);
    std::cout << "Link: ";
    std::string link;
    std::getline(std::cin, link);
    std::cout << "descricao: ";
    std::string descricao;
    std::getline(std::cin, descricao);
    std::cout << "Timpo de post: '1'-texto || '2'-Video || '3'-Imagem\n";
    unsigned int tipo_post;
    do {
		std::string input;
		std::cin >> input;
		try {
			tipo_post = stoi(input);
			if (tipo_post != 1 && tipo_post != 2 && tipo_post != 3) {
				std::cout << "Valor inválido. Por favor, insira um número entre 1 e 3.\n";
			}
		} catch (const std::invalid_argument &e) {
			std::cout << "Valor inválido. Por favor, insira um número inteiro.\n";
		}
	} while (tipo_post != 1 && tipo_post != 2 && tipo_post != 3);


	std::cout << "Privacidade do post: '0'-publica || '1'-Privada\n";
	unsigned int permissao = -1;
	do {
		std::string input;
		std::cin >> input;
		try {
			permissao = stoi(input);
			if (permissao != 0 && permissao != 1) {
				std::cout << "Valor inválido. Por favor, insira 0 ou 1." << std::endl;
			}
		} catch (const std::invalid_argument &e) {
			std::cout << "Valor inválido. Por favor, insira um número inteiro." << std::endl;
		}
	} while (permissao != 0 && permissao != 1);


    switch (tipo_post){
        case 1 :{
            database::Texto *t;
            if (permissao == 0){
                t = new database::Texto{link,titulo,descricao,this->nome,database::Permissao::PUBLIC};
            }else{
                t = new database::Texto{link,titulo,descricao,this->nome,database::Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(t);
            Visitante::listageral->adicionar(t);
        }
        break;

        case 2 :{
            database::Video *v;
            if (permissao == 0){
                v = new database::Video{link,titulo,descricao,this->nome,database::Permissao::PUBLIC};
            }else{
                v = new database::Video{link,titulo,descricao,this->nome,database::Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(v);
            Visitante::listageral->adicionar(v);
        }
        break;
           
        case 3 :{
            database::Imagem *i;
            if (permissao == 0){
                i = new database::Imagem{link,titulo,descricao,this->nome,database::Permissao::PUBLIC};
            }else{
                i = new database::Imagem{link,titulo,descricao,this->nome,database::Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(i);
            Visitante::listageral->adicionar(i);
        }    
        break;
		
    }   
	std::cin.ignore(1000, '\n'); 
	std::cin.clear();
}


void Usuario::editaPostagem(unsigned int idPostagem){ // vem da classe usuario e administrador
    if ( idPostagem < 0 || idPostagem > this->minhasPostagens->getTamanho() - 1){
        throw database::IdInvalidoException(idPostagem);
    }

    database::Post *meupost {this->minhasPostagens->getPost(idPostagem)};

    std::cout <<"Escolha o que deseja editar: \n";
    std::cout <<"0 - Titulo\n";
    std::cout <<"1 - Link\n";
    std::cout <<"2 - Descricao\n";
    std::cout <<"3 - database::Permissao\n";
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
			std::cin.ignore(1000,'\n');
            std::getline(std::cin, input);
            std::cin.ignore(1000, '\n');
            meupost->setTitulo(input);
        break;

        case 1 :
            std::cout << "Link: ";
			std::cin.ignore(1000,'\n');
            std::getline(std::cin, input);
            std::cin.ignore(1000, '\n');
            meupost->setLink(input);
        break;
           
        case 2 :
            std::cout << "Descricao: ";
			std::cin.ignore(1000,'\n');
            std::getline(std::cin, input);
            std::cin.ignore(1000, '\n');
            meupost->setDescricao(input);
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
                meupost->setPermissao(database::Permissao::PUBLIC);
            else
                meupost->setPermissao(database::Permissao::PRIVATE);
        break;

        case 4 :
            std::cout << "Cancelando edição" << std::endl;
        break;

        default :
            std::cout << "Opção inválida" << std::endl;
        break;
    }
}

void Usuario::removePostagem(unsigned int idPostagem){
    database::Post *meupost {this->minhasPostagens->getPost(idPostagem)};
	if(meupost == nullptr){
		throw database::IdInvalidoException(idPostagem);
	}
    else{
        this->minhasPostagens->remover(*meupost);
        Visitante::listageral->remover(*meupost);
    }
}

void Usuario::visualizaPropriasPostagens() const{ //(pode ver as publicas e privadas)
    this->minhasPostagens->printList(this->nome, database::Permissao::PRIVATE);
}

void Usuario::visualizaPostagensDeOutros() const{
	Visitante::listageral->printList(this->nome, database::Permissao::PUBLIC);
}

void Usuario::verPostagem(const unsigned int id) const{
	database::Post * p = Visitante::listageral->getPost(id);
	if (p == nullptr){
		throw database::IdInvalidoException(id);
	}
	if (p->getDono() != this->nome && p->getPermissao() == database::Permissao::PRIVATE ){
		throw database::IdInvalidoException(id);
	}	
	std::cout << *p;
}

void Usuario::save() const{
	std::ofstream arquivosaida("../users/" + this->nome);
	if (!arquivosaida){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	arquivosaida << this->nome << "\n";
	arquivosaida << this->email << "\n";
	arquivosaida << this->senha << "\n";
	arquivosaida << this->dataDeNascimento << "\n";
	arquivosaida.close();
	this->minhasPostagens->saveCompact("../users/" + this->nome);
}

void Usuario::load(){
	std::ifstream arquivoentrada("../users/" + this->nome);
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

void Usuario::setNome(const std::string &nome){
    this->nome = nome;
}

std::string Usuario::getNome() const {
    return this->nome;
}

void Usuario::setEmail(const std::string &email){
    this->email = email;
}

std::string Usuario::getEmail() const {
    return this->email;
}

void Usuario::setSenha(const std::string &senha){
    this->senha = senha;
}

std::string Usuario::getSenha() const {
    return this->senha;
}

void Usuario::setDataDeNascimento(const std::string &dataDeNascimento){
    this->dataDeNascimento = dataDeNascimento;
}

std::string Usuario::getDataDeNascimento() const {
    return this->dataDeNascimento;
}

std::ostream& operator<<(std::ostream& stream, const Usuario& usuario) {
    stream << usuario.nome;
    return stream;  // permitir cout << a << b << c;
}

const database::Post *Usuario::getPost(unsigned int idPostagem) const {
    return this->listageral->getPost(idPostagem);
}

void Usuario::fazComentario(const unsigned int idPostagem,const std::string texto){
	database::Comentario com{this->nome, texto};
	this->listageral->getPost(idPostagem)->adicionaComentario(com);
}

void Usuario::removeComentario (const unsigned int idPostagem){
	database::Comentario com{this->nome, ""};
	this->listageral->getPost(idPostagem)->removerComentario(com);
}
