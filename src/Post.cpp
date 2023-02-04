#include "Post.hpp"



Post::Post(){
	id = Id::getnextId();
}

Post::Post(std::string link):Post{}{
	this->link = link;
	
}

Post::~Post(){
	
}

std::string Post::getLink() const{
	return this->link;
}
