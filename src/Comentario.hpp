#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>
#include "Data.hpp"

//class Usuario; //foward declaration para evitar ciclo de include

class Comentario{

	friend std::ostream& operator<<(std::ostream& stream, const Comentario& comentario);

	public:
		Comentario(/* args */);
		Comentario(const std::string dono, std::string texto);
		Comentario(const std::string dono, std::string texto, Data data);
		virtual ~Comentario();
		std::string getDono()const;
		std::string getTexto()const;
		Data getData()const;
		bool operator==(const Comentario outro) const;
	private:
		std::string dono_comentario;
		std::string texto; 
		Data data;
};

#endif