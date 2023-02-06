#ifndef USUARIO_ADMINISTRADOR_HPP
#define USUARIO_ADMINISTRADOR_HPP

#include "Usuario.hpp"
#include "Administrador.hpp"


class UsuarioAdministrador : public Usuario, public Administrador {
    public:
        UsuarioAdministrador();
        virtual ~UsuarioAdministrador();

        virtual void editaPostagem(unsigned int idPostagem) override; // vem da classe usuario e administrador
        virtual void removePostagem(unsigned int idPostagem) override; // vem da classe usuario e administrador

        virtual void visualizaPostagensDeOutros() override; // vem da classe visitante (pode ver as publicas)

    private:
        // id do usuario -> atributo -> vem da classe usuario/administrador/visitante 

};

#endif