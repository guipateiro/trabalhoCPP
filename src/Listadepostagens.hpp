#ifndef LISTADEPOSTAGENS_HPP
#define LISTADEPOSTAGENS_HPP

#include<vector>
#include "Post.hpp"
#include "Tag.hpp"

class Post; //foward declaration por causa de um ciclo 
//talvez o ciclo acabe quando os arquivos e as chamas tenham uma hierarquia

class Listadepostagens {
    public:
        Listadepostagens();
        virtual ~Listadepostagens();
		void adicionar(Post *post);
		void remover(Post post);
		void remover(unsigned int id);
		Post* getPost(unsigned int id) const;
    private:
        std::vector<Post*> listapostagens;
		std::vector<Tag> listatags;
	
};


#endif