#ifndef ID_INVALIDO_EXCEPTION
#define ID_INVALIDO_EXCEPTION

#include <stdexcept>

class IdInvalidoException : public std::runtime_error{
    public:
        const unsigned long id;

        explicit IdInvalidoException(const unsigned long id);
        virtual ~IdInvalidoException() = default;
};
#endif