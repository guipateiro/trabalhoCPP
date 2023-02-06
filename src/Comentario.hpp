#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>
#include "Usuario.hpp"
#include "Data.hpp"

//class Usuario; //foward declaration para evitar ciclo de include

class Comentario{

	private:
		Usuario dono_comentario;
		std::string texto; 
		Data data;
	public:
		Comentario(/* args */);
		~Comentario();
};

#endif