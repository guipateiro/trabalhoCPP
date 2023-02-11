#include "Video.hpp"
#include <iostream>
#include <string.h>

Video::Video(){
	
}


Video::Video(std::string link):Post{link}{
}

Video::Video(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao)
	:Post{link,titulo,descrissao,dono_post,permissao}{
}

Video::~Video(){
	
}

//FUNCIONA COM VIDEOS DA INTERNET, TEM Q COLOCAR O LINK DO VIDEO (o desempenho é  horrivel, fica travando toda hora);

void Video::run()const {
	std::string in{"celluloid --mpv-really-quiet " + this->getLink() + " 2>/dev/null &"};
	system(in.c_str());
}

Tipopost Video::geTipo() const{
	return Tipopost::VIDEO;
}