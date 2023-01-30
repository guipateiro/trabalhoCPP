#include "Id.hpp"

unsigned int Id::ID{0};

Id::Id(/* args */){
}

Id::~Id(){
}

unsigned int Id::getnextId(){
    Id::ID = Id::ID + 1;
    return Id::ID;
}
