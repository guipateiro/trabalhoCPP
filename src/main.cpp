#include "Video.hpp"
#include "Usuario.hpp"
#include "Imagem.hpp"
#include "Post.hpp"
#include "Texto.hpp"
#include <iostream>
#include "Listadepostagens.hpp"
#include "Data.hpp"


int main(){
	//cria um usuario e uma lista de postagens
	Usuario eu;
	eu.setNome("guilherme");
	//Listadepostagens lista;
	
	//eu.fazPostagem();

	//std::cout << *Visitante::listageral->getPost(0);

	//cria um post com um video ------------------------------
	Video *v1 = new Video{"../media/video.mp4"};
	Visitante::listageral->adicionar(v1);
	std::cerr << v1->getLink() << "\n";
	std::cerr << v1->getId() << "\n";
	if(*Visitante::listageral->getPost(0) == 0){
		std::cout << "sim\n";
	}

	if( 0 == *Visitante::listageral->getPost(0)){
		std::cout << "sim\n";
	}

	if( Visitante::listageral->getPost(0) == Visitante::listageral->getPost(0)){
		std::cout << "sim\n";
	}
	/*//cria um post com um video ------------------------------
	Video *v1 = new Video{"../media/video.mp4"};
	lista.adicionar(v1);
	std::cerr << v1->getLink() << "\n";
	std::cerr << v1->getId() << "\n";


	//cria um post com um texto ------------------------------
	Texto *t1 = new Texto{"../media/texto.txt"};
	lista.adicionar(t1);
	std::cerr << t1->getLink() << "\n";
	std::cerr << t1->getId() << "\n";

	//cria um post com uma imagem -----------------------------
	//teste com imagem da internet (deve ser um prato de comida)
	Imagem *i1 = new Imagem{"https://www.shutterstock.com/shutterstock/photos/1265495377/display_1500/stock-photo-healthy-meal-prep-containers-with-chickpeas-chicken-tomatoes-cucumbers-avocados-and-broccoli-1265495377.jpg"};
	lista.adicionar(i1);
	std::cerr << i1->getLink() << "\n";
	std::cerr << i1->getId() << "\n";


	
	//Post *algo = lista.getPost(0);
	//algo->run();
	//std::cerr << "fez algo ? \n";
	//lista.getPost(1)->run();
	//lista.getPost(2)->run();
	
	// teste de gerar hora e sobrecarga de print
	Data data = Data::getDataAtual();
	std::cout << "hora de agora: " << data; //imprimir data (nao propositalmente) coloca um \n no final dela
	
	
	//cria um comentario e coloca no post de id 0
	Comentario com(eu.getNome(), "eu achei muito bom, nota 2");
	lista.getPost(0)->adicionaComentario(com);

	//faz todo o trabalho de imprimir um post, incluindo executa-lo
	std:: cout << *lista.getPost(0); //sobrecarga do perador de impresao de um post;

	lista.getPost(0)->removerComentario(com);

	std:: cout << *lista.getPost(0); */



}