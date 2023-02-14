#include "Imagem.hpp"
#include <iostream>
#include <string.h>

namespace database{

Imagem::Imagem(){
	
}


Imagem::Imagem(std::string link):Post{link}{

}


Imagem::Imagem(std::string link, std::string titulo, std::string descricao, std::string dono_post, Permissao permissao)
	:Post{link,titulo,descricao,dono_post,permissao}{
}

Imagem::~Imagem(){
	
}

//FUNCIONA COM IMAGENS DA INTERNET , COLOCAR URL DA IMAGEM COMO LINK
void Imagem::run() const {
	std::string in{"eog " + this->getLink() + " &"};
	system(in.c_str());
}

Tipopost Imagem::geTipo() const{
	return Tipopost::IMAGEM;
}

}