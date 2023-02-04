#ifndef POST_HPP
#define POST_HPP

#include<string>
#include<vector>
#include"Id.hpp"
#include"Comentario.hpp"
#include"Usuario.hpp"
#include"Permisao.hpp"
#include"Data.hpp"

class Post{
    public:
		Post();
        Post(std::string link);
        virtual ~Post();
		
		virtual void run() const = 0;
		std::string getLink() const;

		void setTitulo(const std::string titulo);
		std::string getTitulo() const;

		void setDescrisao(const std::string descrisao);
		std::string getDescrisao() const;

		unsigned int getId() const;

		void setPermissao(Permissao permissao);
		Permissao getPermissao() const;

    private:
		std::string link;  // nome do arquivo
		std::string titulo; //titulo do post
        std::string descrissao; // descrissao do post
		unsigned int id; //ID unico q é compartilhado entre dos os posts
		Usuario dono;	//usuario dono do post
		Data data;
		//std::list<usuarios> listaPermissoes; // lista de usuarios que podem ver o post
		Permissao permissao;  //(PUBLIC, PRIVATE) utiliza a classe enum "Permissao"
		std::vector<Comentario> comentarios;
		std::list<Tags> listaTags;

};

#endif
