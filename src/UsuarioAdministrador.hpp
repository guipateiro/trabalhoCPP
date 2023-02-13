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
		virtual void save() const; // obrigatoriamente Usuario deve ter um nome para ser salvo
		virtual void load(); // obrigatoriamente Usuario deve ter um nome para ser carregado


        virtual const Post *getPost(unsigned int idPostagem) const override;

    protected:
        // id do usuario -> atributo -> vem da classe usuario/administrador/visitante 

};

#endif