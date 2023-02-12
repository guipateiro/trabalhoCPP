#include "Post.hpp"
#include <iostream>
#include <ctime>

Post::Post(){
	//this->id = Id::getnextId();
}

Post::Post(std::string link):link{link}{
	this->id = Id::getnextId();
	
}

Post::Post(std::string link, std::string titulo, std::string descricao, std::string dono_post, Permissao permissao)
	:link{link},
	titulo{titulo},
	descricao{descricao},
	dono_post{dono_post},
	permissao{permissao}{
	this->id = Id::getnextId();
}

Post::~Post(){
}

void Post::run() const{
	std::cerr << "NAO ERA PRA VC ESTAR LENDO ISSO, ESSA É UMA FUNCAO QUE NAO DEVERIA SER USADA, ESSA MENSAGEM PROVAVELMENTE É UM ERRO DE PONTEIROS\n";

}

void Post::save(std::ofstream &arquivosaida) const{
	arquivosaida << int(this->geTipo()) << "\n";
	arquivosaida << this->link << "\n";
	arquivosaida << this->titulo << "\n";
	arquivosaida << this->descricao << "\n";
	arquivosaida << this->dono_post << "\n";
	arquivosaida << int(this->permissao) << "\n";
	arquivosaida << this->id << "\n";
	arquivosaida << this->data.getData() << "\n";
	arquivosaida << this->comentarios.size() << "\n";
	std::vector<Comentario>::const_iterator it;
	for(it = this->comentarios.begin(); it < this->comentarios.end(); ++it){
		arquivosaida << it->getDono() << "\n";
		arquivosaida << it->getTexto() << "\n";
		arquivosaida << it->getData().getData() << "\n";
	}
}

void Post::load(std::ifstream &arquivoentrada){
	//arquivoentrada.ignore('\n');
	std::getline(arquivoentrada, this->link);
	//std::cerr << "Link:" << this->link << "\n";
	std::getline(arquivoentrada, this->titulo);
	//std::cerr << "Titulo :" << this->titulo << "\n";
	std::getline(arquivoentrada, this->descricao);
	//std::cerr << "Descrissao: "<< this->descricao << "\n";
	std::getline(arquivoentrada, this->dono_post);
	//std::cerr << "Dono: "<< this->dono_post << "\n";
	int perm;
	arquivoentrada >> perm; 
	//std::cerr << "perm: "<< perm << "\n";
	if (perm == 0){
		this->permissao = Permissao::PUBLIC;
	}else{
		this->permissao = Permissao::PRIVATE;
	}
	arquivoentrada >> this->id;
	//std::cerr << "id: " << this->id << "\n";
	time_t data;
	arquivoentrada >> data; 
	this->data.setData(data);
	//std::cerr << "data:" << this->data << "\n";
	int tam;
	arquivoentrada >> tam;
	for(int i = 0; i < tam ; ++i){
		std::string dono;
		arquivoentrada >> dono;
		std::string texto;
		std::getline(arquivoentrada,texto);
		time_t data;
		arquivoentrada >> data;
		Comentario com(dono,texto,data);
		this->comentarios.push_back(com);
	}
}


Tipopost Post::geTipo() const{
	return Tipopost::ERRO;
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


void Post::setDescricao(const std::string descricao){
	this->descricao = descricao;
}

std::string Post::getDescricao() const{
	return this->descricao;
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
	stream << "\"" << post.descricao << "\"\n\n";
	stream << "Comentarios: \n";
	std::vector<Comentario>::const_iterator it;
	for(it = post.comentarios.begin(); it < post.comentarios.end(); ++it){
		stream << *it << "\n";
	}
	post.run();

    return stream;  // permitir cout << a << b << c;
}

std::string Post::getDono() const{
	return this->dono_post;
}