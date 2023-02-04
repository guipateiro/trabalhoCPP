#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Listadepostagens.hpp" 
#include "Visitante.hpp"

class Administrador : public Visitante {
    public:
        Administrador();
        virtual ~Administrador();

        void editaPostagem(unsigned int idPostagem); //-> metodo -> vem da classe usuario e administrador
        void removePostagem(unsigned int idPostagem); //-> metodo -> vem da classe usuario e administrador

        void visualizaPostagensDeOutros(); //-> metodo -> vem da classe usuario (pode ver as privadas e publicas)

    private:
        Listadepostagens *todasAsPostagens; //-> atributo -> vem da classe administrador

};

#endif