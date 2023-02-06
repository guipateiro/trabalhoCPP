#ifndef ID_HPP
#define ID_HPP
 
#include <fstream>
#include <iostream>
//essa classe deve controlar o id unico q as postagens podem ter 
// id atual deve ser carregado de um arquivo no inicio da classe 
// id deve ser salvo em arquivo no final de tod execussao
// so se pode ter 1 is na memoria e seus valores sao compartilhados entre todas as classes que o usam (acho q isso é uma classe estatica)


class Id{
private:
    static unsigned int ID;
    static unsigned int createId();
public:
    static unsigned int getnextId();
};



#endif