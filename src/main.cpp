#include "UsuarioAdministrador.hpp"
#include "Interface.hpp"

int main(){
	
	Interface::init(); //carrega dados de arquivos para o funcionamento do sistema
	Usuario *eu;
	UsuarioAdministrador *supereu;
	Administrador *adm;
	int tipousuario = 1;
	switch(tipousuario){
		case 1:
			do{
			eu = Interface::loginUsuario(); // cria um usuario
			}while(Interface::administraUsuario(eu));
			Interface::finalize(eu);
		break;
		
		case 2:
			Interface::finalize(supereu);
		break;

		case 3:
			Interface::finalize(adm);
		break; 
	}	

	return 0;
}