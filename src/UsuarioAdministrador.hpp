#ifndef USUARIO_ADMINISTRADOR_HPP
#define USUARIO_ADMINISTRADOR_HPP

#include "Usuario.hpp"
#include "Administrador.hpp"


class UsuarioAdministrador : public Usuario, public Administrador {
    public:
        UsuarioAdministrador();
        virtual ~UsuarioAdministrador();


    private:
        // id do usuario -> atributo -> vem da classe usuario/administrador/visitante 

};

#endif