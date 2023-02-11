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

        static Listadepostagens *listageral;
    private:
};


#endif