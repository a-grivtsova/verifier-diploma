#include "Logger.h"
#include "VariablesHandler.h"
#include "Requirement.h"
#include <vector>

#ifndef VERIFIER_H
#define VERIFIER_H

typedef uint8_t T;
class Verifier {
    private:

        /*typedef struct Port
        {
            int32_t dimSize;
            int8_t ports[1];
        };
        typedef Port **PortsHdl;

        PortsHdl algInputPorts;

        INT8S * aInput = reinterpret_cast<INT8S*> ((*algInputPorts)->ports);*/

        std::vector<Requirement*> requirements; 
        VariablesHandler variablesHandler;
        Logger logger;

    public:
        Verifier(T *_i_ports, T *_o_ports);
        ~Verifier();     
        void run();
};
 
#endif