#ifndef DATA_HPP
#define DATA_HPP

#include <ctime>
#include <chrono>

class Data{

	public:
		Data();
		virtual ~Data();
		std::time_t getData() const;
		static std::time_t getDataAtual();
	private:
		std::time_t data;
};


#endif