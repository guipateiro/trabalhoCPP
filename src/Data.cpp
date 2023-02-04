#include "Data.hpp"

Data::Data(){
	std::chrono::time_point agora = std::chrono::system_clock::now();
	this->data = std::chrono::system_clock::to_time_t(agora);
}

Data::~Data()
{
}

std::time_t Data::getDataAtual(){
	std::chrono::time_point agora = std::chrono::system_clock::now();
	return std::chrono::system_clock::to_time_t(agora);
}


std::time_t Data::getData() const{
	return this->data;
}
