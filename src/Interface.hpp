#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Visitante.hpp"
#include "Usuario.hpp"
#include "Administrador.hpp"
#include "UsuarioAdministrador.hpp"

class Interface{

	public:
		Interface() = delete;
		static void init();
		static bool administraVisitante();
		static Usuario *loginUsuario();
		static bool administraUsuario(Usuario *pessoa);
		static bool administraAdministrador(Administrador *pessoa);
		static bool administraUsuarioAdministrador(UsuarioAdministrador *pessoa);
		static void finalize(Visitante *pessoa);
	private:
};

#endif