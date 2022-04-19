#include "PortVariable.h"
#include "VerificationFSM.h"
#include <map>
#include <fstream>

#ifndef VARIABLES_HANDLER_H
#define VARIABLES_HANDLER_H

typedef uint8_t T;
class VariablesHandler
{
private:
    T *i_ports;
    T *o_ports;
    std::map <std::string, PortVariable*> v;

public:
    VariablesHandler();

    void read();

    /*FILE* pFile*/ 
    void logVariables(std::ofstream&);

    void setPorts(T *i_ports, T *o_ports){
        this->i_ports = i_ports;
        this->o_ports = o_ports;
    };

    std::map <std::string, PortVariable*> getVariablesMap() {
        return this->v;
    }
};

#endif