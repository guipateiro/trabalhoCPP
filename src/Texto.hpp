#ifndef TEXTO_HPP
#define TEXTO_HPP

#include "Post.hpp"

namespace database{

class Texto : public Post{
	public:
		Texto();
		Texto(std::string link);
		Texto(std::string link, std::string titulo, std::string descricao, std::string dono_post, Permissao permissao);
		virtual ~Texto();
		virtual void run() const;
		virtual Tipopost geTipo() const;
	private:
		/* data */
};

}

#endif
