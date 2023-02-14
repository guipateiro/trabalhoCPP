#include "Visitante.hpp"

database::Listadepostagens *Visitante::listageral {new database::Listadepostagens{}};

Visitante::Visitante(){

}

Visitante::~Visitante(){

}

void Visitante::visualizaPostagensDeOutros() const{
    Visitante::listageral->printList("Visitante", database::Permissao::PUBLIC);
}

void Visitante::save(){
}

void Visitante::load(){

}

void Visitante::verPostagem(const unsigned int id) const{
    database::Post * p = Visitante::listageral->getPost(id);
	if (p == nullptr){
		throw database::IdInvalidoException(id);
	}
	if (p->getPermissao() == database::Permissao::PRIVATE ){
		throw database::IdInvalidoException(id);
	}	
	std::cout << *p;
}