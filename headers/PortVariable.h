#include "constants.h"
#include <cstdint>

#ifndef PORT_VARIABLE_H
#define PORT_VARIABLE_H

class PortVariable
{
    friend class VariablesHandler;
    friend class EdtlFunctions;

    private:
        variableType type;
        uint8_t *port;
        uint8_t bit;

    protected:
        uint8_t prev;
        uint8_t cur;
        uint8_t post;

    public:
        PortVariable(variableType, uint8_t*, uint8_t);
        void saveValue();
};
 
#endif
