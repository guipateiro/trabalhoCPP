#include "Visitante.hpp"

Listadepostagens *Visitante::listageral = new Listadepostagens{};

Visitante::Visitante(){

}

Visitante::~Visitante(){

}

void Visitante::visualizaPostagensDeOutros(){
    Visitante::listageral->printList("Visitante", Permissao::PUBLIC);
}
