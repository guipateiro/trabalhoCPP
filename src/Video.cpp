#include "Video.hpp"
#include <iostream>
#include <string.h>

Video::Video(std::string link):Post{link}{
	std::cerr << "contuido video\n";
}

Video::~Video(){
	
}

void Video::run()const {
	char head[30]{"celluloid  "};
	char *in = strcat(head,this->getLink().c_str());
	const char *in2 = strcat(in , " 2> lixo.txt &");
	system(in2);
}