#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Listadepostagens.hpp" 
#include "Visitante.hpp"

class Usuario : public Visitante {
    public:
        Usuario();
        virtual ~Usuario();

        void fazPostagem(); // -> metodo -> vem da classe usuario
        void editaPostagem(unsigned int idPostagem); //-> metodo -> vem da classe usuario e administrador
        void removePostagem(unsigned int idPostagem); //-> metodo -> vem da classe usuario e administrador

        void visualizaPropriasPostagens(); //-> metodo -> vem da classe usuario
        void visualizaPostagensDeOutros(); //-> metodo -> vem da classe usuario (pode ver as publicas)


    private:
        Listadepostagens *minhasPostagens; // lista de postagens do usuario -> atributo -> vem da classe usuario

};

#endif