#include "Data.hpp"
#include <ctime>

Data::Data(){
	this->data = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

Data::~Data()
{
}

Data::Data(std::time_t time){
	this->data = time;
}

std::time_t Data::getDataAtual(){
	return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}


std::time_t Data::getData() const{
	return this->data;
}


std::ostream& operator<<(std::ostream& stream, const Data& data) {
    std::time_t agora = data.getData();
	stream << ctime(&agora); 
    return stream;  // permitir cout << a << b << c;
}

bool Data::operator==(const Data outro) const{
	if(this->data == outro.data)
		return 1;
	return 0;
}