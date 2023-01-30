#ifndef POST_HPP
#define POST_HPP

#include<string>
#include"Id.hpp"

class Post{
    public:
		Post();
        Post(std::string link);
        virtual ~Post();
		
		virtual void run() const = 0;
		std::string getLink() const;
    private:
		std::string link; 
		std::string titulo;
        std::string descrissao;
		unsigned int id; //ID unico q é compartilhado entre dos os posts
		//Usuario user;
		//std::list<usuarios> listaPermissoes;
		//classe enum (PRIVATE, PUBLIC) //prafacilitar o teste por outras classes e pq da nota
		//std::list<comentario> comentarios;
		//std::list<tags> listaTags;

};

#endif
