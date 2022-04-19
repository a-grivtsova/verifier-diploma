#include "constants.h"
#include <ctime>
#include <fstream>
#include <string>
#include "VerificationFSM.h"
#include "constants.h"
#include "VariablesHandler.h"
#include "EdtlFunctions.h"
#include "PortVariable.h"
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef REQUIREMENT_H
#define REQUIREMENT_H

class Requirement {
    private:
        requirementId reqId;
        int maxId = 0;
        std::vector<VerificationFSM*> fsms;
        EdtlFunctions edtlFunctions;

    public:
        Requirement(requirementId reqId);
        ~Requirement();
        void checkVerificationFSMs();
        void run();
        void refreshAttributes(VariablesHandler&);
        void logRequirement(std::ofstream&);
};
 
#endif
