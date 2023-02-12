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
	Usuario *eu = Interface::login(); // cria um usuario

	std::cin.ignore(1000, '\n');
	std::cout << "teste" << std::endl;
	eu->fazPostagem();
	//eu.fazPostagem();


	//std::cout << *Visitante::listageral->getPost(0);

	Visitante alguem;

	alguem.visualizaPostagensDeOutros();

	Interface::finalize(eu);

/* Interface::init();
bool finalizer = 0;
conta = Interface::login();
while(finalizer == 0){
	Interface::administraUsuario(conta);
}
Interface::finalize();
*/
	return 0;
}