#ifndef POST_HPP
#define POST_HPP

#include<string>

class Post{
    public:
        Post(/* args */);
        virtual ~Post();
		
		virtual void run();
    private:
		std::string link; 
		std::string titulo;
        std::string descrissao;
		//Usuario user;
		//classe enum (PRIVATE, PUBLIC) //prafacilitar o teste por outras classes e pq da nota
		//std::list<comentario> comentarios;
		//std::list<tags> listaTags;

};

#endif
