#ifndef EDTL_FUNCTIONS_HANDLER_H
#define EDTL_FUNCTIONS_HANDLER_H

#include "PortVariable.h"
#include "VerificationFSM.h"
#include <constants.h>
#include <map>

class EdtlFunctions
{
private:
    /* data */
public:
    EdtlFunctions(/* args */);

    ~EdtlFunctions();

    void calculate(VerificationFSM*, std::map <std::string, PortVariable*>&, requirementId);

    bool tau(clock_t start, clock_t time) {
        if(clock() - start < time)
            return false;
        return true;
    };
};

#endif