#include "Visitante.hpp"

Listadepostagens *Visitante::listageral {new Listadepostagens{}};

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

void Visitante::verPostagem(const unsigned int id) const{
    Post * p = Visitante::listageral->getPost(id);
	if (p == nullptr){
		throw IdInvalidoException(id);
	}
	if (p->getPermissao() == Permissao::PRIVATE ){
		throw IdInvalidoException(id);
	}	
	std::cout << *p;
}