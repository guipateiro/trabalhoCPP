#include "Video.hpp"
#include "Usuario.hpp"
#include "Imagem.hpp"
#include "Post.hpp"
#include "Texto.hpp"
#include <iostream>
#include "Listadepostagens.hpp"

int main(){

	Usuario eu;
	Listadepostagens lista;
	
	Video *v1 = new Video{"../media/video.mp4"};
	lista.adicionar(v1);
	std::cerr << v1->getLink() << "\n";
	std::cerr << v1->getId() << "\n";

	Texto *t1 = new Texto{"../media/texto.txt"};
	lista.adicionar(t1);
	std::cerr << t1->getLink() << "\n";
	std::cerr << t1->getId() << "\n";

	//teste com imagem da internet (deve ser um prato de comida)
	Imagem *i1 = new Imagem{"https://www.shutterstock.com/shutterstock/photos/1265495377/display_1500/stock-photo-healthy-meal-prep-containers-with-chickpeas-chicken-tomatoes-cucumbers-avocados-and-broccoli-1265495377.jpg"};
	lista.adicionar(i1);
	std::cerr << i1->getLink() << "\n";
	std::cerr << i1->getId() << "\n";

	Post *algo = lista.getPost(0);
	algo->run();
	std::cerr << "fez algo ? \n";
	lista.getPost(1)->run();
	lista.getPost(2)->run();


}