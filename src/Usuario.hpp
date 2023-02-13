#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Visitante.hpp"
#include <string>
#include "Id.hpp"
#include "Permissao.hpp"
#include "Imagem.hpp"
#include "Texto.hpp"
#include "Video.hpp"
#include "IdInvalidoException.hpp"


class Usuario : virtual public Visitante {
    friend std::ostream& operator<<(std::ostream& stream, const Usuario& usuario);

    public:
        Usuario();
        virtual ~Usuario();

        virtual void fazPostagem(); // vem da classe usuario
        virtual void editaPostagem(const unsigned int idPostagem); // vem da classe usuario e administrador
        virtual void removePostagem(const unsigned int idPostagem); //  vem da classe usuario e administrador
		virtual void verPostagem(const unsigned int id) const;

        virtual void visualizaPropriasPostagens() const;
		virtual void visualizaPostagensDeOutros() const;


		void save() const; // obrigatoriamente Usuario deve ter um nome para ser salvo
		void load(); // obrigatoriamente Usuario deve ter um nome para ser carregado

        void setNome(const std::string &nome);
        std::string getNome() const;

        void setEmail(const std::string &email);
        std::string getEmail() const;

        void setSenha(const std::string &senha);
        std::string getSenha() const;

        void setDataDeNascimento(const std::string &dataDeNascimento);
        std::string getDataDeNascimento() const;

        virtual const Post *getPost(const unsigned int idPostagem) const;

    protected:
        Listadepostagens *minhasPostagens;
        std::string nome;
        std::string email;
        std::string senha;
        std::string dataDeNascimento;

};

#endif