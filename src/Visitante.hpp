#ifndef VISITANTE_HPP
#define VISITANTE_HPP

#include "Listadepostagens.hpp" 

class Visitante {
    public:
        Visitante();
        virtual ~Visitante();
    
        virtual void visualizaPostagensDeOutros(); // (pode ver as publicas)

    private:
        static Listadepostagens *listageral;
};


#endif