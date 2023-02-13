#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Usuario.hpp"

class Interface{

	public:
		static void init();
		static Usuario *loginUsuario();
		static bool administraUsuario(Usuario *pessoa);
		static void finalize(Visitante *pessoa);
	private:

};

#endif