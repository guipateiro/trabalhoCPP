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
			return;
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

void Listadepostagens::printList(std::string dono, Permissao permissao) const{
	std::vector<Post*>::const_iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it).getPermissao() == permissao || (**it).getDono() == dono){
			std::cout << "Post(ID = " << (**it).getId() << ")[";
			switch((*it)->geTipo()){ //Post *
				case Tipopost::TEXTO:
					std::cout << "TEXTO";
				break;
				case Tipopost::VIDEO:
					std::cout << "VIDEO";
				break;
				case Tipopost::IMAGEM:
					std::cout << "IMAGEM";
				break;	
				case Tipopost::ERRO:
					std::cout << "ERRO";
				break;
			}
			std::cout << "]: "<< (**it).getTitulo() << "\n";
		}
	}
}
