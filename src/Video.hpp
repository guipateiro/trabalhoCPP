#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Post.hpp"

class Video : public Post{
	public:
		Video();
		Video(std::string link);
		Video(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao);
		virtual ~Video();
		virtual void run() const;
		virtual Tipopost geTipo() const;
	private: 
		/* data */
};


#endif