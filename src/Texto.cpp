#include "Texto.hpp"
#include <iostream>

namespace database{

Texto::Texto():Post{}{
	
}

Texto::Texto(std::string link):Post{link}{

}

Texto::Texto(std::string link, std::string titulo, std::string descricao, std::string dono_post, Permissao permissao)
	:Post{link,titulo,descricao,dono_post,permissao}{
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

}