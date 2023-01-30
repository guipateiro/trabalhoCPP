#ifndef TEXTO_HPP
#define TEXTO_HPP

#include "Post.hpp"


class Texto : public Post{
	public:
		Texto(std::string link);
		virtual ~Texto();
		virtual void run() const;
	private:
		/* data */
};

#endif
