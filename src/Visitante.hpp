#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include "Listadepostagens.hpp" 
#include "Permissao.hpp"
#include <memory>

class Visitante {
    public:
        Visitante();
        virtual ~Visitante();
    
        virtual void visualizaPostagensDeOutros();

        static Listadepostagens *listageral;
};


#endif