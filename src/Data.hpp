#ifndef DATA_HPP
#define DATA_HPP

#include <ctime>
#include <chrono>

class Data
{
private:
	std::time_t data;
public:
	Data();
	~Data();
	std::time_t getData() const;
	static std::time_t getDataAtual();
};


#endif