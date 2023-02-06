#include "Post.hpp"
#include <iostream>

Post::Post(){
	this->id = Id::getnextId();
}

Post::Post(std::string link):Post{}{
	this->link = link;
	
}

Post::~Post(){
}

void Post::run() const{
	std::cerr << "NAO ERA PRA V ESTAR LENDO ISSO ESSA É UMA FUNCOA QUE NAO É UTILIZADA\n";

}

std::string Post::getLink() const{
	return this->link;
}

void Post::setLink(const std::string link){
	this->link = link;
}

void Post::setTitulo(const std::string titulo){
	this->titulo = titulo;
}

std::string Post::getTitulo() const{
	return this->titulo;
}


void Post::setDescrisao(const std::string descrissao){
	this->descrissao = descrissao;
}

std::string Post::getDescrisao() const{
	return this->descrissao;
}


unsigned int Post::getId() const{
	return this->id;
}


void Post::setPermissao(const Permissao permissao){
	this->permissao = permissao;
}

Permissao Post::getPermissao() const{
	return this->permissao;
}


bool Post::operator==(const unsigned int id) const{
	if (this->id == id)
		return 1;
	return 0;	
}

bool Post::operator==(const Post outro) const{
	if (this->id == outro.id)
		return 1;
	return 0;	
}
