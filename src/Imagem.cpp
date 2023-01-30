#include "Imagem.hpp"
#include <iostream>
#include <string.h>

Imagem::Imagem(std::string link):Post{link}{

}

Imagem::~Imagem(){
	
}


void Imagem::run() const {
	char head[30]{"eog "};
	char *in = strcat(head,this->getLink().c_str());
	const char *in2 = strcat(in , " &");
	system(in2);
}