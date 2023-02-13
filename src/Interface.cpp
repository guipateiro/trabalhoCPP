#include "Interface.hpp"

void Interface::init(){
	Visitante::listageral->load("../data/listaposts.txt");
}


Usuario* Interface::loginUsuario(){
	Usuario * user = new Usuario;
	inicio_criar_conta:
	system("clear");
	std::cout << "ENTRE NA SUA CONTA: \n";
	std::cout << "Novo usuario: '1' || Ja possui conta: '2'\n";
	unsigned int novo;
	do {
		std::string input;
		std::cin >> input;
		try {
			novo = stoi(input);
			if (novo != 1 && novo != 2) {
				std::cout << "Valor inválido. Por favor, insira o valor '1' ou '2'\n";
			}
		} catch (const std::invalid_argument &e) {
			std::cout << "Valor inválido. Por favor, insira um número inteiro\n";
		}
	} while (novo != 1 && novo != 2);
	switch(novo){
		case 1:
		{
			std::cout << "NOVO USUARIO\n";
			std::cout << "====================================================\n";
			std::cout << "Ao continuar vc esta concordando com nosso termos de uso que nao existem, mesmo por que no final vcs nao iriam ler mesmo \n";
			std::cout << "para negar os termos de usa feche esse programa da maneira q vc preferir\n";
			std::cout << "====================================================\n";
			std::cout << "digite seu nome de usuario(palavra sem espacos): ";
			std::string nome;
			std::cin >> nome;
			user->setNome(nome);
			std::cout << "digite seu email(palavra sem espacos): ";
			std::string email;
			std::cin >> email;
			user->setEmail(email);
			std::cout << "digite saua data de nascimento: ";
			std::string data;
			std::cin.ignore(1000,'\n');
			std::getline(std::cin,data);
			user->setDataDeNascimento(data);
			std::cin.ignore(1000, '\n');
			std::string senha1;
			std::string senha2;
			do{
				std::cout << "digite sua senha: ";
				std::cin >> senha1;
				std::cout << "repita sua senha: ";
				std::cin >> senha2;
				if (senha1 != senha2){
					std::cout << "ERRO: as senhas nao batem\n";
				}
			}while(senha1 != senha2);
			user->setSenha(senha1);
		}
		break;

		case 2:
			std::cout << "LOGIN\n";
			std::string nome;
			inicio_login:
			std::cout << "Digite seu nome: (para voltar digite '9')\n";
			std::cin >> nome;
			user->setNome(nome);
			//std::cout << nome << std::endl;
			if (nome == "9"){
				goto inicio_criar_conta;
			}
			try {
				user->load();
			} catch (const std::runtime_error& rr) {
				std::cout << "Erro: usuário não existe ou houve uma falha nos arquivos." << std::endl;
				goto inicio_login;
			}
			std::string senha;
			int count = 0;
			std::cin.ignore(1000,'\n');
			do{
				std::cout << "digite sua senha: ";
				std::getline(std::cin,senha);
				if (user->getSenha() != senha){
					std::cout << "senha incorreta\n";
					std::cin.clear();
					std::cin.sync();
				}
				count++;
			}while(user->getSenha() != senha && count < 4);
			if(count == 3){
				goto inicio_login;
			}
		break;
	}

	return user;
}

bool Interface::administraUsuario(Usuario *pessoa){
	//ler opcoes:
	system("clear");
	while(1){
		std::cout << "==============================================\n";
		std::cout << "Opcoes: \n'0' - ver posts || '1' - adicionar post || '2' - editar post || '3' - logout || '4' - finalizar programa\n";
		std::cout << "==============================================\n";
		unsigned int opcao1;
		do {
			std::string input;
			std::cin >> input;
			try {
				opcao1 = stoi(input);
				if (opcao1 > 4) {
					std::cout << "Valor inválido. Por favor, insira o valor entre '0' e '3'\n";
				}
			} catch (const std::invalid_argument &e) {
				std::cout << "Valor inválido. Por favor, insira um número inteiro\n";
			}
		}while(opcao1 > 4);
		switch (opcao1){
			case 0:{
				std::cout << "'1' - Visualizar seus posts || '0' - visualizar post publicos\n";
				unsigned int opcao2;
				do {
					std::string input;
					std::cin >> input;
					try {
						opcao2 = stoi(input);
						if (opcao2 > 1) {
							std::cout << "Valor inválido. Por favor, insira o valor '0' ou '1'\n";
						}
					} catch (const std::invalid_argument &e) {
						std::cout << "Valor inválido. Por favor, insira um número inteiro\n";
					}
				}while(opcao2 > 1);
				//0 meus posts
				//1 posts dos outros
				if (opcao2 == 0){
					pessoa->visualizaPostagensDeOutros();
				}else{
					pessoa->visualizaPropriasPostagens();
				}

				//	(num post) abre post
				std::cout << "digite o id do post a ser visto: \n";
				unsigned int id;
				std::cin >> id;
				try{
					pessoa->verPostagem(id);
				} catch(IdInvalidoException& err){
					std::cout << "Id invalido: " << err.id << " " << err.what() << "\n"; 
				}

				//	adicionar comentario
				//	remover comentario
				}
			break;

			case 1:{
				//1 adicionar post 
				std::cout << "tem certeza que deseja criar um post\n '1' - sim || '0' - nao\n";
				unsigned int opcao2;
				do {
					std::string input;
					std::cin >> input;
					try {
						opcao2 = stoi(input);
						if (opcao2 > 1) {
							std::cout << "Valor inválido. Por favor, insira o valor entre '0' e '3'\n";
						}
					}catch (const std::invalid_argument &e) {
						std::cout << "Valor inválido. Por favor, insira um número inteiro\n";
					}
				}while(opcao2 > 1);
				if(opcao2 == 1){
					pessoa->fazPostagem();
				}
			}
			break;

			case 2:{
				//2 editar post
				//		(num post)
				pessoa->visualizaPropriasPostagens();
				std::cout << "digite o id do post a ser editado: \n";
				unsigned int id;
				std::cin >> id;
				try{
					pessoa->editaPostagem(id);
				} catch(IdInvalidoException& err){
					std::cout << "Id invalido: " << err.id << " " << err.what() << "\n"; 
				}
			}
			break;

			case 3:{
				//3 logout 
				pessoa->save();
				return true;
				}
			break;

			case 4:{
				//4 sair do programa
				return false;
				}
			break;
		}		
	}
}

void Interface::finalize(Visitante *pessoa){
	Visitante::listageral->save("../data/listaposts.txt");
	pessoa->save();
	Id::save();
	delete pessoa;
}