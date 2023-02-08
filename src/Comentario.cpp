#include "Comentario.hpp"

Comentario::Comentario():data{Data::getDataAtual()}{
}

Comentario::Comentario(const std::string dono, const std::string texto)
    :dono_comentario{dono},
    texto{texto}{
    Comentario();
}


Comentario::~Comentario(){

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
