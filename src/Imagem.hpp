#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include "Post.hpp"

class Imagem: public Post{
	public:
		Imagem();
		Imagem(std::string link);
		Imagem(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao);
		virtual ~Imagem();
		virtual void run()const;
		virtual Tipopost geTipo() const;
	private:
};

#endif


