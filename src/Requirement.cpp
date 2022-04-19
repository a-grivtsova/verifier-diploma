#include "../headers/Requirement.h"

    Requirement::Requirement(requirementId id):reqId(id){}

    Requirement::~Requirement(){
        for (auto fsm : fsms) {
            delete fsm;
        }
        fsms.clear();
    }

    void Requirement::checkVerificationFSMs(){  
        bool isCheckTrigger = false;
        for(auto iter = fsms.begin(); iter != fsms.end(); ++iter) {
            isCheckTrigger |= (*iter)->isCheckTrigger();
            if((*iter)->isPassive()) {
                fsms.erase(iter);
            }
        }
        if(!isCheckTrigger){
            fsms.push_back(new VerificationFSM(maxId | (reqId << 16)));
        }
    }

    void Requirement::run(){
        for(auto fsm: fsms) {
            fsm->verify();
        }
    }

    void Requirement::refreshAttributes(VariablesHandler& handler){
        for(auto fsm: fsms) {
            edtlFunctions.calculate(fsm, handler.getVariablesMap(), this->reqId);
        }
    }

    void Requirement::logRequirement(std::ofstream& fout){
        if(!fout) return;
        //fprintf( pFile, "%d", this->reqId);
        fout << this->reqId << " ";

        for(auto fsm: fsms) {
            fsm->logCurState(fout);
        }
    }
