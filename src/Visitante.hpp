#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include "Listadepostagens.hpp" 
#include <memory>

class Visitante {
    public:
        Visitante();
        virtual ~Visitante();
    
        virtual void visualizaPostagensDeOutros(); // (pode ver as publicas)

        static Listadepostagens *listageral;
    private:
};


#endif