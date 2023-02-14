#include "Comentario.hpp"

namespace database{

Comentario::Comentario():data{Data::getDataAtual()}{
}

Comentario::Comentario(const std::string dono, const std::string texto)
    :dono_comentario{dono},
    texto{texto}{
    Comentario();
}

Comentario::Comentario(const std::string dono, const std::string texto, Data data):dono_comentario{dono},texto{texto},data{data}{

}

Comentario::~Comentario(){

}

std::string Comentario::getDono()const{
	return this->dono_comentario;
}

std::string Comentario::getTexto()const{
	return this->texto;
}

Data Comentario::getData()const{
	return this->data;
}



std::ostream& operator<<(std::ostream& stream, const Comentario& comentario) {
	stream << "Por: " << comentario.dono_comentario << " || Em: " << comentario.data;
	stream << "\"" << comentario.texto << "\"";

    return stream;  // permitir cout << a << b << c;
}

bool Comentario::operator==(const Comentario outro) const{
	if ((this->dono_comentario == outro.dono_comentario) && (this->data == outro.data))
		return 1;
	return 0;	
}

}