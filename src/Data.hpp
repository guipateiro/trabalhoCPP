#ifndef DATA_HPP
#define DATA_HPP

#include <ctime>
#include <chrono>
#include <iostream>
#include <string>

class Data{
	friend std::ostream& operator<<(std::ostream& stream, const Data& data);

	public:
		Data();
		Data(std::time_t time);
		virtual ~Data();
		std::time_t getData() const;
		void setData(time_t data);
		static std::time_t getDataAtual();

		bool operator==(const Data outro) const;
	private:
		std::time_t data;
};


#endif