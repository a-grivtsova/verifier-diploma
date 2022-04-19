#include "../headers/PortVariable.h"

PortVariable::PortVariable(variableType type, uint8_t* port, uint8_t bit): type(type), port(port), bit(bit){};

void PortVariable::saveValue(){
    uint8_t value;
    if(!bit) value = *port;
    else value = *port & (1 << bit);
    prev = cur;
    cur = (type == inputVariable)?value:post;
    post = value;
};
