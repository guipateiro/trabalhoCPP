#include "Interface.hpp"

void Interface::init(){
	Visitante::listageral->load("../data/listaposts.txt");
}


Usuario* Interface::login(){
	Usuario * user = new Usuario;
	inicio_criar_conta:
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
			std::cout << "Ao continuar vc esta concordando com nosso termos de uso que nao existem, mesmo por que no final vcs nao iriam ler mesmo \n";
			std::cout << "para negar os termos de usa feche esse programa da maneira q vc preferir\n";
			std::cout << "digite seu nome de usuario(palavra sem espacos): ";
			std::string nome;
			std::cin >> nome;
			user->setNome(nome);
			std::cout << "digite seu email(palavra sem espacos): ";
			std::string email;
			std::cin >> email;
			user->setEmail(email);
			std::cout << "digite seu telefone(palavra sem espacos): ";
			unsigned long tel;
			std::cin >> tel;
			user->setCelular(tel);
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
			user->setNome(senha1);
		}
		break;

		case 2:
			std::cout << "LOGIN\n";
			std::string nome;
			inicio_login:
			std::cout << "Digite seu nome: (para voltar digite '9')\n";
			std::cin >> nome;
			if (nome == "9"){
				goto inicio_criar_conta;
			}
			try{
				user->load();
			}catch (std::runtime_error &rr){
				std::cout << "erro usuario nao existe ou falha nos aquivos";
				goto inicio_login;
			}
			std::cin.ignore(1000, '\n');
			std::string senha;
			int count = 0;
			do{
				std::cout << "digite sua senha: ";
				std::getline(std::cin,senha);
				std::cin.ignore(1000, '\n');
				if (user->getSenha() != senha){
					std::cout << "senha incorreta\n";
				}
				count++;
			}while(user->getSenha() != senha && count < 3);
		break;
	}

	return user;
}

bool Interface::administraUsuario(Usuario const *pessoa){
	/* ler opcoes:
	0 ver post 	
		0 meus posts
		1 posts dos outros
			(num post) abre post
			adicionar comentario
			remover comentario
	1 adicionar post 
	2 editar post
		(num post)
	3 sair 
	*/
	return false;
}

void Interface::finalize(Usuario *pessoa){
	Visitante::listageral->save("../data/listaposts.txt");
	pessoa->save();
	Id::save();
}