#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>
#include "Usuario.hpp"
#include "Data.hpp"

//class Usuario; //foward declaration para evitar ciclo de include

class Comentario{

	friend std::ostream& operator<<(std::ostream& stream, const Comentario& comentario);

	private:
		Usuario dono_comentario;
		std::string texto; 
		Data data;
	public:
		Comentario(/* args */);
		Comentario(const Usuario dono, std::string texto);
		virtual ~Comentario();
		bool operator==(const Comentario outro) const;
};

#endif