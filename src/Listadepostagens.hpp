#ifndef LISTADEPOSTAGENS_HPP
#define LISTADEPOSTAGENS_HPP

#include<vector>
#include "Post.hpp"
#include "Texto.hpp"
#include "Video.hpp"
#include "Imagem.hpp"
#include <iostream>
#include <fstream>

namespace database{

class Listadepostagens {
    public:
        Listadepostagens();
        virtual ~Listadepostagens();
		void save(const std::string diretorio);
		void saveCompact(const std::string diretorio);
		void load(const std::string diretorio);
		void adicionar(Post *post);
		void remover(Post post);
		void remover(unsigned int id);
		Post* getPost(unsigned int id) const;
		Post* getPost(unsigned int id, std::string dono) const;
    void printList(std::string dono, Permissao permissao) const;
		long int getTamanho() const;
		void printList();
    private:
        std::vector<Post*> listapostagens;
	
};

}
#endif