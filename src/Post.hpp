#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <vector>
#include <list>
#include "Id.hpp"
#include "Comentario.hpp"
#include "Permissao.hpp"
#include "Data.hpp"
#include "Tag.hpp"

class Post{
	friend std::ostream& operator<<(std::ostream& stream, const Post& post);
	friend bool operator==(const unsigned int id, const Post& rhs);



    public:
		Post();
        Post(std::string link);
		Post(std::string link, std::string titulo, std::string descrissao, std::string dono_post, Permissao permissao);
        virtual ~Post();
		
		virtual void run() const; // = 0; // por algum motivo isso da erro em algum lugar
		std::string getLink() const;
		void setLink(const std::string link);

		void setTitulo(const std::string titulo);
		std::string getTitulo() const;

		void setDescrisao(const std::string descrissao);
		std::string getDescrisao() const;

		unsigned int getId() const;

		void setPermissao(const Permissao permissao);
		Permissao getPermissao() const;

		bool operator==(const unsigned int id) const;
		bool operator==(const Post outro) const;

		void adicionaComentario(const Comentario comentario);
		void removerComentario(const Comentario comentario);
		//

    private:
		std::string link;  // nome do arquivo
		std::string titulo; //titulo do post
        std::string descrissao; // descrissao do post
		std::string dono_post;	//usuario dono do post
		Permissao permissao;  //(PUBLIC, PRIVATE) utiliza a classe enum "Permissao"
		unsigned int id; //ID unico q é compartilhado entre dos os posts
		Data data;
		//std::list<usuarios> listaPermissoes; // lista de usuarios que podem ver o post
		std::vector<Comentario> comentarios;
		std::list<Tag> listaTags;

};

#endif
