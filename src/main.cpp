#include "Video.hpp"
#include "Imagem.hpp"
#include "Post.hpp"
#include "Texto.hpp"
#include <iostream>

int main(){
	Video v1{"../media/video.mp4"};
	std::cerr << v1.getLink() << "\n";

	Imagem i1{"../media/imagem.jpg"};
	std::cerr << i1.getLink() << "\n";

	Texto t1{"../media/texto.txt"};
	std::cerr << t1.getLink() << "\n";

	Post **post = new Post*[4];

	post[0] = &v1;
	post[1] = &i1;
	post[2] = &t1;

	post[0]->run();
	post[1]->run();
	post[2]->run();


}