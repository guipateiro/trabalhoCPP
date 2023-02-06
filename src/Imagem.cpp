#include "Imagem.hpp"
#include <iostream>
#include <string.h>

Imagem::Imagem(std::string link):Post{link}{

}

Imagem::~Imagem(){
	
}

//FUNCIONA COM IMAGENS DA INTERNET , COLOCAR URL DA IMAGEM COMO LINK
void Imagem::run() const {
	std::string in{"eog " + this->getLink() + " &"};
	system(in.c_str());
}