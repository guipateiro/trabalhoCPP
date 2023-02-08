#include "Usuario.hpp"

Usuario::Usuario(){
    this->minhasPostagens = new Listadepostagens{};
}

Usuario::~Usuario(){

}

void Usuario::fazPostagem(){ // vem da classe usuario
    std::cout << "Titulo: ";
    std::string titulo;
    std::getline(std::cin, titulo);
    std::cout << "Link: ";
    std::string link;
    std::cin >> link;
    std::cout << "Descrissao: ";
    std::string descrissao;
    std::getline(std::cin, descrissao);
    std::cout << "Timpo de post: '0'-texto || '1'-Video || '2'-Imagem\n";
    unsigned int tipo_post;
    do{
        std::cin >> tipo_post;
        if(tipo_post > 2){
            std::cout << "Valor invalido";
        }
    }while(tipo_post > 2);
    switch (tipo_post){
        case 0 :{
        std::cout << "Privacidade do post: '0'-publica || '1'-Privada\n";
            unsigned int permissao;
            do{
                std::cin >> permissao;
                if(permissao > 1){
                    std::cout << "Valor invalido";
                }
            }while(permissao > 1);
            Texto *t;
            if (permissao == 0){
                t = new Texto{link,titulo,descrissao,this->nome,Permissao::PUBLIC};
            }else{
                t = new Texto{link,titulo,descrissao,this->nome,Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(t);
            Visitante::listageral->adicionar(t);
        }
        break;

        case 1 :{
            std::cout << "Privacidade do post: '0'-publica || '1'-Privada\n";
            unsigned int permissao;
            do{
                std::cin >> permissao;
                if(permissao > 1){
                    std::cout << "Valor invalido";
                }
            }while(permissao > 1);
            Video *v;
            if (permissao == 0){
                v = new Video{link,titulo,descrissao,this->nome,Permissao::PUBLIC};
            }else{
                v = new Video{link,titulo,descrissao,this->nome,Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(v);
            Visitante::listageral->adicionar(v);
        }
        break;
           
        case 2 :{
            std::cout << "Privacidade do post: '0'-publica || '1'-Privada\n";
            unsigned int permissao;
            do{
                std::cin >> permissao;
                if(permissao > 1){
                    std::cout << "Valor invalido";
                }
            }while(permissao > 1);
            Imagem *i;
            if (permissao == 0){
                i = new Imagem{link,titulo,descrissao,this->nome,Permissao::PUBLIC};
            }else{
                i = new Imagem{link,titulo,descrissao,this->nome,Permissao::PRIVATE};
            }
            this->minhasPostagens->adicionar(i);
            Visitante::listageral->adicionar(i);
        }    
        break;
    }    
}

void Usuario::editaPostagem(unsigned int idPostagem){ // vem da classe usuario e administrador

}

void Usuario::removePostagem(unsigned int idPostagem){ // vem da classe usuario e administrador

}

void Usuario::visualizaPropriasPostagens(){ //(pode ver as publicas e privadas)

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

void Usuario::setCelular(const unsigned long &celular){
    this->celular = celular;
}

unsigned long Usuario::getCelular() const {
    return this->celular;
}

std::ostream& operator<<(std::ostream& stream, const Usuario& usuario) {
    stream << usuario.nome;
    return stream;  // permitir cout << a << b << c;
}