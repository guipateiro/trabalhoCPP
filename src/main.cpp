#include "UsuarioAdministrador.hpp"
#include "Interface.hpp"

int main(){
	
	Interface::init(); //carrega dados de arquivos para o funcionamento do sistema
	Usuario *eu;
	UsuarioAdministrador *supereu;
	Administrador *adm;
	std::cout << "Escolha o tipo de usuario:\n";
	std::cout << "'0' - visitante || '1' - usuario || '2' - usuario administrado || '3' - administrador\n";
	unsigned int tipousuario;
	do {
		std::string input;
		std::cin >> input;
		try {
			tipousuario = stoi(input);
			if (tipousuario > 3) {
				std::cout << "Valor inválido. Por favor, insira o valor '1' ou '2'\n";
			}
		} catch (const std::invalid_argument &e) {
			std::cout << "Valor inválido. Por favor, insira um número inteiro\n";
		}
	} while (tipousuario > 3)    ;
	switch(tipousuario){
		case 0: //visitante
			while(Interface::administraVisitante()){}
			Interface::finalize();
		break;

		case 1: //usuario
			do{
			eu = Interface::loginUsuario(); // cria um usuario
			}while(Interface::administraUsuario(eu));
			Interface::finalize(eu);
		break;
		
		case 2: //usuarioadministrador
			do{
			supereu = Interface::loginUsuarioAdministrador(); // cria um usuario
			}while(Interface::administraUsuarioAdministrador(supereu));
			Interface::finalize(supereu);
		break;

		case 3: //administrador
			do{
			adm= Interface::loginAdministrador(); // cria um usuario
			}while(Interface::administraAdministrador(adm));
			Interface::finalize(adm);
		break; 
	}	

	return 0;
}