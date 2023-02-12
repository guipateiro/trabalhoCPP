#include "Visitante.hpp"

Listadepostagens *Visitante::listageral = new Listadepostagens{};

Visitante::Visitante(){

}

Visitante::~Visitante(){

}

void Visitante::visualizaPostagensDeOutros() const{
    Visitante::listageral->printList("Visitante", Permissao::PUBLIC);
}

void Visitante::save(){

}

void Visitante::load(){

}