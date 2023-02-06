#ifndef USUARIO_HPP
#define USUARIO_HPP

//#include "Listadepostagens.hpp" 
#include "Visitante.hpp"
#include <string>
#include "Id.hpp"

class Listadepostagens; //foward declaration

class Usuario : virtual public Visitante {
    friend std::ostream& operator<<(std::ostream& stream, const Usuario& usuario);

    public:
        Usuario();
        virtual ~Usuario();

        virtual void fazPostagem(); // vem da classe usuario
        virtual void editaPostagem(unsigned int idPostagem); // vem da classe usuario e administrador
        virtual void removePostagem(unsigned int idPostagem); //  vem da classe usuario e administrador

        virtual void visualizaPropriasPostagens();

        void setNome(const std::string &nome);
        std::string getNome() const;

        void setEmail(const std::string &email);
        std::string getEmail() const;

        void setSenha(const std::string &senha);
        std::string getSenha() const;

        void setDataDeNascimento(const std::string &dataDeNascimento);
        std::string getDataDeNascimento() const;

        void setCelular(const unsigned long &celular);
        unsigned long getCelular() const;

    private:
        
        Listadepostagens *minhasPostagens;
        std::string nome;
        std::string email;
        std::string senha;
        std::string dataDeNascimento;
        unsigned long celular;
};

#endif