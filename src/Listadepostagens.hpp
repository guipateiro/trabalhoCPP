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
		void remover(const unsigned int id);
		Post* getPost(const unsigned int id) const;
    void printList(std::string dono, Permissao permissao) const;
		long int getTamanho() const;
		void printList();
    private:
        std::vector<Post*> listapostagens;
	
};

}
#endif