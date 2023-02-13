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
		static Usuario *login();
		static bool administraVisitante();
		static bool administraUsuario(Usuario *pessoa);
		static bool administraAdministrador(Administrador *pessoa);
		static bool administraUsuarioAdministrador(UsuarioAdministrador *pessoa);
		static void finalize(Usuario *pessoa);

	private:
};

#endif