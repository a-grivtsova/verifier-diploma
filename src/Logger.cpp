#include "../headers/Logger.h"

Logger::Logger()
{    
    time_t rawtime;
    struct tm * timeinfo; 

    time(&rawtime);                              
    timeinfo = localtime(&rawtime);               
    strftime(fileName, sizeof(fileName),"log_%d_%m_%y_%H_%M_%S.txt", timeinfo); 
}

void Logger::log(Requirement* requirement, VariablesHandler *handler){
    //FILE* pFile = fopen(fileName, "a");
    std::ofstream fout(fileName, std::ios_base::app);
    if(!fout) return;
    clock_t time = clock();
    //fprintf( pFile, "%d", time);
    fout << time << " ";
    handler->logVariables(fout);

    requirement->logRequirement(fout);

    fout.close();
    //fclose (pFile);
}