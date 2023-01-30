#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Post.hpp"

class Video : public Post{
	public:
		Video(std::string link);
		virtual ~Video();
		virtual void run() const;
	private: 
		/* data */
};


#endif