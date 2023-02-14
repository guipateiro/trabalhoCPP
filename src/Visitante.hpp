#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include "Listadepostagens.hpp" 
#include "Permissao.hpp"
#include "IdInvalidoException.hpp"

class Visitante {
    public:
        Visitante();
        virtual ~Visitante();
    

        virtual void visualizaPostagensDeOutros() const; // (pode ver as publicas)
        virtual void verPostagem(const unsigned int id) const;
		virtual void save();
		virtual void load();

        static database::Listadepostagens *listageral;
};


#endif