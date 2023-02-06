#include "Video.hpp"
#include <iostream>
#include <string.h>

Video::Video(std::string link):Post{link}{
	std::cerr << "contuido video\n";
}

Video::~Video(){
	
}

//FUNCIONA COM VIDEOS DA INTERNET, TEM Q COLOCAR O LINK DO VIDEO
//(o desempenho é  horrivel, fica travando toda hora);

void Video::run()const {
	std::string in{"celluloid --mpv-really-quiet " + this->getLink() + " 2>/dev/null &"};
	system(in.c_str());
}