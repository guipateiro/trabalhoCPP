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
#include "Tipopost.hpp"

class Post{
	friend std::ostream& operator<<(std::ostream& stream, const Post& post); //sobrecarga de escrita para facilitar a interface
	friend bool operator==(const unsigned int id, const Post& rhs); // cobrecarga do perador do unsigned int para manter a comutatividade

    public:
		Post(); // esse construtor nao gera id, somente utilizar com a funcao load()
        Post(std::string link); //melhor ussar esse para testes 
		Post(std::string link, std::string titulo, std::string descricao, std::string dono_post, Permissao permissao); // construtor completo usar esse em condições normais;
        virtual ~Post(); 
		
		virtual void run() const; // = 0 ;//essa funcao nao seve ser chamada, ela deve ser usava pela subclasses
		virtual Tipopost geTipo() const; // pega o tipo da classe, como post eh uma classe template essa funcao nao deve ser chamada em condicoes normais

		virtual void save(std::ofstream &arquivosaida) const; //salva os dados em um arquivo
		virtual void load(std::ifstream &arquivoentrada); // carrega os dados nos arquivos

		std::string getLink() const; 
		void setLink(const std::string link);

		void setTitulo(const std::string titulo);
		std::string getTitulo() const;

		void setDescricao(const std::string descricao);
		std::string getDescricao() const;

		unsigned int getId() const; // nao deve ter um setId pois um id nunca pode ser mudado

		void setPermissao(const Permissao permissao);
		Permissao getPermissao() const;

		std::string getDono() const; // o dono de um post nao pode ser mudado, por escolha de projeto

		bool operator==(const unsigned int id) const; // sobrecarga para comparar um post baseado no seu id
		bool operator==(const Post outro) const;

		void adicionaComentario(const Comentario comentario);
		void removerComentario(const Comentario comentario);

    private:
		std::string link;  // nome do arquivo
		std::string titulo; //titulo do post
        std::string descricao; // descricao do post
		std::string dono_post;	//usuario dono do post
		Permissao permissao;  //(PUBLIC, PRIVATE) utiliza a classe enum "Permissao"
		unsigned int id; //ID unico q é compartilhado entre dos os posts, gerenciado pelos contrutores e pela classe ID
		Data data; // data que o post fo criado
		std::vector<Comentario> comentarios; // lista de comentarios
		std::list<Tag> listaTags; // em desuso ate agora

};

#endif
