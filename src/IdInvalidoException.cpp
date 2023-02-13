#include "IdInvalidoException.hpp"

IdInvalidoException::IdInvalidoException(const unsigned long id)
    :std::runtime_error{"Id não existe ou o usuario nao tem permissao para acessa-lo"}, id{id}{
}