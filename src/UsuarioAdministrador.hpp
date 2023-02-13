#ifndef USUARIO_ADMINISTRADOR_HPP
#define USUARIO_ADMINISTRADOR_HPP

#include "Usuario.hpp"
#include "Administrador.hpp"
#include "IdInvalidoException.hpp"


class UsuarioAdministrador : public Usuario, public Administrador {
    public:
        UsuarioAdministrador();
        virtual ~UsuarioAdministrador();

        virtual void editaPostagem(unsigned int idPostagem) override; 
        virtual void removePostagem(unsigned int idPostagem) override; 
		virtual void verPostagem(const unsigned int id) const;
		
        virtual void visualizaPostagensDeOutros() override; // vem da classe visitante (pode ver as publicas)

    protected:
        // id do usuario -> atributo -> vem da classe usuario/administrador/visitante 

};

#endif