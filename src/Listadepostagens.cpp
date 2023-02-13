#include "Listadepostagens.hpp" 
#include <iostream>

Listadepostagens:: Listadepostagens(){

}

Listadepostagens::~Listadepostagens(){

}


void Listadepostagens::save(const std::string diretorio){
	std::ofstream arquivosaida(diretorio);
	if (!arquivosaida){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	arquivosaida << this->listapostagens.size() << "\n";
	std::vector<Post*>::iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		(**it).save(arquivosaida);
	}
	arquivosaida.close();
}

void Listadepostagens::load(const std::string diretorio){
	std::ifstream arquivoentrada(diretorio);
	if (!arquivoentrada){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	size_t tam = 0;
	arquivoentrada >> tam;
	std::cerr << tam << "\n";
	for(size_t i = 0; i < tam; ++i){
		int tipo = -1;
		arquivoentrada >> tipo;
		arquivoentrada.ignore();
		std::cerr << "tipo: " << tipo << "\n"; 
		switch (tipo)
		{
			case 1: //case texto
			{
				Texto *t = new Texto;
				t->load(arquivoentrada);
				this->listapostagens.push_back(t);
				std::cerr << "adicionado elemento de arquivo \n";
			}	
			break;

			case 2: //case video
			{
				Video *v = new Video;
				v->load(arquivoentrada);
				this->listapostagens.push_back(v);
				std::cerr << "adicionado elemento de arquivo \n";
			}
			break;

			case 3: //case imagem
			{
				Imagem *i = new Imagem;
				i->load(arquivoentrada);
				this->listapostagens.push_back(i);
				std::cerr << "adicionado elemento de arquivo \n";
			}
			break;
		}
	}
}



void Listadepostagens::adicionar(Post *post){
	this->listapostagens.push_back(post);
}

void Listadepostagens::remover(Post post){
	std::vector<Post*>::iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == post ){
			this->listapostagens.erase(it);
		}
	}
}

void Listadepostagens::remover(unsigned int id){
	std::vector<Post*>::iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == id ){
			this->listapostagens.erase(it);
			return;
		}
	}
}

Post *Listadepostagens::getPost(unsigned int id) const{
	std::vector<Post*>::const_iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((**it) == id ){
			return *it;
		}
	}
	std::cerr << "erro, o elemento nao esta na lista\n";
	return nullptr;
}

void Listadepostagens::printList(std::string dono, Permissao permissao) const{
	std::vector<Post*>::const_iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		if((*it)->getPermissao() == permissao || ((*it)->getDono() == dono) || dono == "Admin"){
			std::cout << "Post(ID = " << (*it)->getId() << ")[";
			switch((*it)->geTipo()){ //Post *
				case Tipopost::TEXTO:
					std::cout << "TEXTO";
				break;
				case Tipopost::VIDEO:
					std::cout << "VIDEO";
				break;
				case Tipopost::IMAGEM:
					std::cout << "IMAGEM";
				break;	
				case Tipopost::ERRO:
					std::cout << "ERRO";
				break;
			}
			std::cout << "]: "<< (*it)->getTitulo() << "\n";
		}
	}

	
}


long int Listadepostagens::getTamanho() const {
	return this->listapostagens.size();
}

void Listadepostagens::saveCompact(const std::string diretorio){
	std::ofstream arquivosaida;
	arquivosaida.open(diretorio, std::ios::app);
	if (!arquivosaida){
		throw std::runtime_error("arquivo não pode ser aberto");
	}
	arquivosaida << this->listapostagens.size() << "\n";
	std::cerr << "imprimindo tamanho: " << this->listapostagens.size() << "\n";
	std::vector<Post*>::const_iterator it;
	for(it = this->listapostagens.begin(); it < this->listapostagens.end(); ++it){
		arquivosaida << (*it)->getId() << "\n";
	}	
	arquivosaida.close();
}