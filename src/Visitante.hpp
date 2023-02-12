#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include "Listadepostagens.hpp" 
#include "Permissao.hpp"
#include <memory>

class Visitante {
    public:
        Visitante();
        virtual ~Visitante();
    

    virtual void visualizaPostagensDeOutros() const; // (pode ver as publicas)
		virtual void save();
		virtual void load();

        static Listadepostagens *listageral;
};


#endif