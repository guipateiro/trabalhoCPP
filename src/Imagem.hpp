#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include "Post.hpp"

class Imagem: public Post{
	public:
		Imagem(std::string link);
		virtual ~Imagem();

		virtual void run()const ;
	private:
		/* data */
};

#endif


