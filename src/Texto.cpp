#include "Texto.hpp"
#include <iostream>

Texto::Texto(std::string link):Post{link}{

}

Texto::~Texto(){
	
}

void Texto::run()const{
    
    char head[300]{"gnome-terminal --quiet --command \"sh -c \'cat ../media/texto.txt; exec bash\'\" --"};
	//char *in = strcat(head,this->getLink().c_str());
	//const char *in2 = strcat(in , " &");
	system(head);
}