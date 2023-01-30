#include "Post.hpp"


Post::Post(std::string link){
	this->link = link;
}

Post::~Post(){
	
}

void Post::run(){}


std::string Post::getLink() const{
	return this->link;
}
