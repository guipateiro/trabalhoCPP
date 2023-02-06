#include "Usuario.hpp"

Usuario::Usuario(){

}

Usuario::~Usuario(){

}

void Usuario::fazPostagem(){; // vem da classe usuario

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