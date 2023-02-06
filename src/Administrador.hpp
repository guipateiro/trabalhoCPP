#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Listadepostagens.hpp" 
#include "Visitante.hpp"

class Administrador : virtual public Visitante {
    public:
        Administrador();
        virtual ~Administrador();

        virtual void editaPostagem(unsigned int idPostagem); // vem da classe usuario e administrador
        virtual void removePostagem(unsigned int idPostagem); // vem da classe usuario e administrador

        virtual void visualizaPostagensDeOutros(); // (pode ver as privadas e publicas)

    private:
        Listadepostagens *todasAsPostagens;

};

#endif