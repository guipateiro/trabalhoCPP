#include "Video.hpp"
#include "Usuario.hpp"
#include "Imagem.hpp"
#include "Post.hpp"
#include "Texto.hpp"
#include <iostream>
#include "Listadepostagens.hpp"
#include "Data.hpp"

#include "Interface.hpp"


int main(){
	
	Interface::init(); //carrega dados de arquivos para o funcionamento do sistema
	Usuario *eu;
	do{
	eu = Interface::login(); // cria um usuario

	//std::cin.ignore(1000, '\n');
	std::cout << "teste" << std::endl;
	//eu->fazPostagem();


	}while(Interface::administraUsuario(eu));
	Interface::finalize(eu);

	return 0;
}