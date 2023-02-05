#include "Texto.hpp"
#include <iostream>

Texto::Texto(std::string link):Post{link}{

}

Texto::~Texto(){
	
}

void Texto::run()const{
    std::string in{"gnome-terminal --quiet --command \"sh -c \'cat " + this->getLink() + "; exec bash\'\" --"};
	system(in.c_str());
}