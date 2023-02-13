#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Listadepostagens.hpp" 
#include "Visitante.hpp"
#include "Permissao.hpp"

class Administrador : virtual public Visitante {
    public:
        Administrador();
        virtual ~Administrador();

        virtual void editaPostagem(unsigned int idPostagem); // vem da classe usuario e administrador
        virtual void removePostagem(unsigned int idPostagem); // vem da classe usuario e administrador

        virtual void visualizaPostagensDeOutros(); // (pode ver as privadas e publicas)

        virtual const Post *Administrador::getPost(unsigned int idPostagem) const;

};

#endif