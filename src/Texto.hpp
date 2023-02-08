#ifndef TEXTO_HPP
#define TEXTO_HPP

#include "Post.hpp"


class Texto : public Post{
	public:
		Texto(std::string link);
		Texto(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao);
		virtual ~Texto();
		virtual void run() const;
	private:
		/* data */
};

#endif
