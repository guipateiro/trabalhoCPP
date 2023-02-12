#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Usuario.hpp"

class Interface{

	public:
		static void init();
		static Usuario *login();
		static bool administraUsuario(Usuario *pessoa);
		static void finalize(Usuario *pessoa);
	private:

};

#endif