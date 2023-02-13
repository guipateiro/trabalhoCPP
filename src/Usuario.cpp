#include "Usuario.hpp"
#include <ctype.h>
#include <filesystem>

Usuario::Usuario(){
    this->minhasPostagens = new Listadepostagens{};
}

Usuario::~Usuario(){
	std::cout << "salvando usuario " << this->getNome() << std::endl ;
}


void Usuario::fazPostagem(){
    std::cout << "Titulo: ";
    std::string titulo;
    std::getline(std::cin, titulo);
    std::cout << "Link: ";
    std::string link;
    std::getline(std::cin, link);
    std::cout << "Descrissao: ";
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
            Texto *t;
            if (permissao == 0){
                t = new Texto{link,titulo,descricao,this->nome,Permissao::PUBLIC};
            }else{
                t = new Texto{link,titulo,descricao,this->nome,Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(t);
            Visitante::listageral->adicionar(t);
        }
        break;

        case 2 :{
            Video *v;
            if (permissao == 0){
                v = new Video{link,titulo,descricao,this->nome,Permissao::PUBLIC};
            }else{
                v = new Video{link,titulo,descricao,this->nome,Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(v);
            Visitante::listageral->adicionar(v);
        }
        break;
           
        case 3 :{
            Imagem *i;
            if (permissao == 0){
                i = new Imagem{link,titulo,descricao,this->nome,Permissao::PUBLIC};
            }else{
                i = new Imagem{link,titulo,descricao,this->nome,Permissao::PRIVATE};
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
        std::cout << "Postagem não encontrada" << std::endl;
        return;
    }

    Post *meupost {this->minhasPostagens->getPost(idPostagem)};

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
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, input);
            std::cin.ignore(1000, '\n');
            meupost->setTitulo(input);
        break;

        case 1 :
            std::cout << "Link: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, input);
            std::cin.ignore(1000, '\n');
            meupost->setLink(input);
        break;
           
        case 2 :
            std::cout << "Descricao: ";
            std::cin.ignore(1000, '\n');
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
                meupost->setPermissao(Permissao::PUBLIC);
            else
                meupost->setPermissao(Permissao::PRIVATE);
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
    Post *meupost {this->minhasPostagens->getPost(idPostagem)};
    if (meupost != nullptr){
        this->minhasPostagens->remover(*meupost);
        Visitante::listageral->remover(*meupost);
    }
}

void Usuario::visualizaPropriasPostagens() const{ //(pode ver as publicas e privadas)
    this->minhasPostagens->printList(this->nome, Permissao::PRIVATE);
}

void Usuario::visualizaPostagensDeOutros() const{
	Visitante::listageral->printList(this->nome, Permissao::PUBLIC);
}

void Usuario::save() const{
	std::ofstream arquivosaida("../data/" + this->nome);
	if (!arquivosaida){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	arquivosaida << this->nome << "\n";
	arquivosaida << this->email << "\n";
	arquivosaida << this->senha << "\n";
	arquivosaida << this->dataDeNascimento << "\n";
	arquivosaida.close();
	this->minhasPostagens->saveCompact("../data/" + this->nome);
}

void Usuario::load(){
	std::ifstream arquivoentrada("../data/" + this->nome);
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
		std::cerr << "adicionado elemento no usuario\n";
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

const Post *Usuario::getPost(unsigned int idPostagem) const {
    return this->listageral->getPost(idPostagem);
}