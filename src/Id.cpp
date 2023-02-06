#include "Id.hpp"

unsigned int Id::ID = Id::createId();

unsigned int Id::getnextId(){
    return ID++;
}

unsigned int Id::createId(){
    std::ifstream file("../data/id");
    unsigned int id;
    if(file){
        file >> id;
        std::cout << "lido: " << id;
    }
    file.close();
    return id;
}