#include "Post.hpp"
#include <iostream>

Post::Post(){
	this->id = Id::getnextId();
}

Post::Post(std::string link):link{link}{
	Post();
	
}

Post::Post(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao)
	:link{link},
	titulo{titulo},
	descrissao{descrissao},
	dono_post{dono_post},
	permissao{permissao}{
	Post();
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

bool operator==(const unsigned int id, const Post& rhs){
	if (id == rhs.id)
		return 1;
	return 0;		
}

void Post::adicionaComentario(const Comentario comentario){
	this->comentarios.push_back(comentario);
}

void Post::removerComentario(const Comentario comentario){
	std::vector<Comentario>::iterator it;
	for(it = this->comentarios.begin(); it < this->comentarios.end(); ++it){
		if (comentario == *it){
			this->comentarios.erase(it);
			return;
		}	
	}
}



std::ostream& operator<<(std::ostream& stream, const Post& post) {
    stream << "Titulo: " << post.titulo << "\n";
	stream << "Por: " << post.dono_post << " || Em: " << post.data << "\n";
	stream << "\"" << post.descrissao << "\"\n\n";
	stream << "Comentarios: \n";
	std::vector<Comentario>::const_iterator it;
	for(it = post.comentarios.begin(); it < post.comentarios.end(); ++it){
		stream << *it << "\n";
	}
	post.run();

    return stream;  // permitir cout << a << b << c;
}
