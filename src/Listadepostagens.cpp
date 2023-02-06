#include "Listadepostagens.hpp" 
#include <iostream>

Listadepostagens:: Listadepostagens(){

}

Listadepostagens::~Listadepostagens(){

}

void Listadepostagens::adicionar(Post *post){
	this->listapostagens.push_back(post);
}

void Listadepostagens::remover(Post post){
	std::vector<Post*>::iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == post ){
			this->listapostagens.erase(it);
		}
	}
}

void Listadepostagens::remover(unsigned int id){
	std::vector<Post*>::iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == id ){
			this->listapostagens.erase(it);
		}
	}
}

Post *Listadepostagens::getPost(unsigned int id) const{
	std::vector<Post*>::const_iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == id ){
			//std::cerr << "retornou\n";
			return *it;
		}
	}
	std::cerr << "erro, o elemento nao esta na lista\n";
	return nullptr;
}

