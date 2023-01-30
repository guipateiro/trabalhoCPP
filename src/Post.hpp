#ifndef POST_HPP
#define POST_HPP

#include<string>

class Post{
    public:
        Post(std::string link);
        virtual ~Post();
		
		virtual void run();
		std::string getLink() const;
    private:
		std::string link; 
		std::string titulo;
        std::string descrissao;
		//ID unico q é compartilhado entre dos os posts
		//Usuario user;
		//std::list<usuarios> listaPermissoes;
		//classe enum (PRIVATE, PUBLIC) //prafacilitar o teste por outras classes e pq da nota
		//std::list<comentario> comentarios;
		//std::list<tags> listaTags;

};

#endif
