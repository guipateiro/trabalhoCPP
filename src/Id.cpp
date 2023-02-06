#include "Id.hpp"

unsigned int Id::ID{0};

unsigned int Id::getnextId(){
    return ID++;
}
