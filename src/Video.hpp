#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Post.hpp"

class Video : public Post{
	public:
		Video(std::string link);
		~Video();
		virtual void run();
	private: 
		/* data */
};


#endif