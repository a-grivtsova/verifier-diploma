#include "Requirement.h"
#include "VariablesHandler.h"
#include <fstream>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    char fileName[100];

public:
    Logger();
    void log(Requirement*, VariablesHandler*);
};

#endif