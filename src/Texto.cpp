#include "Texto.hpp"
#include <iostream>

Texto::Texto(std::string link):Post{link}{

}

Texto::Texto(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao)
	:Post{link,titulo,descrissao,dono_post,permissao}{
}

Texto::~Texto(){
	
}

void Texto::run()const{
    std::string in{"gnome-terminal --quiet --command \"sh -c \'cat " + this->getLink() + "; exec bash\'\" --"};
	system(in.c_str());
}

Tipopost Texto::geTipo() const {
	return Tipopost::TEXTO;
}