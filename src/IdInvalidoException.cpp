#include "IdInvalidoException.hpp"

IdInvalidoException::IdInvalidoException(const unsigned long id)
    :std::runtime_error{"CPF Invalido."}, id{id}{
}