#ifndef TAG_HPP
#define TAG_HPP

#include <string>
#include "Data.hpp"

class Tag{
	public:
		Tag(/* args */);
		virtual ~Tag();
	private:
		std::string nome;
		int quantidade; 	
};



#endif