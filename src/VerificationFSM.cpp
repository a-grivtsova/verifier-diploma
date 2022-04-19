#include "../headers/VerificationFSM.h"

VerificationFSM::VerificationFSM(int id) : id(id){
    setState(CHECK_TRIGGER);
};

/*bool trigger, bool release, bool final, bool delay, bool invariant, bool reaction*/
void VerificationFSM::set(EdtlAttributes edtlAttributes){
    this->edtlAttributes.trigger = edtlAttributes.trigger;
    this->edtlAttributes.release = edtlAttributes.release;
    this->edtlAttributes.final = edtlAttributes.final;
    this->edtlAttributes.delay = edtlAttributes.delay;
    this->edtlAttributes.invariant = edtlAttributes.invariant;
    this->edtlAttributes.reaction = edtlAttributes.reaction;
};

void VerificationFSM::checkTrigger () {
    if(!edtlAttributes.trigger) return;
    setState(CHECK_FINAL);
    checkFinal();
};

void VerificationFSM::checkFinal () {
    if(edtlAttributes.release) return setState(SUCCESS); 
    if(!edtlAttributes.invariant) return setState(FAIL);
    if(!edtlAttributes.final) return;
    setState(CHECK_REACTION);
    checkReaction();
};

void VerificationFSM::checkReaction () {
    if(edtlAttributes.release) return setState(SUCCESS);
    if(!edtlAttributes.invariant) return setState(FAIL);
    if(edtlAttributes.reaction) return setState(SUCCESS);  
    if(edtlAttributes.delay) return setState(FAIL);
};

void VerificationFSM::setState(state newState){
    this->time = clock();
    this->curState = newState;
};

clock_t VerificationFSM::getTime(){
    return time;
}

void VerificationFSM::verify(){
    switch (curState) {
        case CHECK_TRIGGER:
            return checkTrigger();
        case CHECK_FINAL:
            return checkFinal();
        case CHECK_REACTION:
            return checkReaction();
        default:
            std::cout << "Checked passive State" << std::endl;
    }
};

bool VerificationFSM::isCheckTrigger(){
    return edtlAttributes.trigger == CHECK_TRIGGER;
};

bool VerificationFSM::isActive(){
    return edtlAttributes.trigger == CHECK_TRIGGER || edtlAttributes.trigger == CHECK_FINAL || edtlAttributes.trigger == CHECK_REACTION;
};

bool VerificationFSM::isPassive(){
    return edtlAttributes.trigger == FAIL || edtlAttributes.trigger == SUCCESS;
};

void VerificationFSM::logCurState(std::ofstream& fout) {
	if(!fout) return;
    switch(curState){
        case CHECK_TRIGGER: fout << "State is CHECK TRIGGER "; //fprintf( pFile, "State is %s\n", "CHECK TRIGGER");
        case CHECK_FINAL: fout << "State is CHECK FINAL "; //fprintf( pFile, "State is %s\n", "CHECK FINAL");
        case CHECK_REACTION: fout << "State is CHECK REACTION "; //fprintf( pFile, "State is %s\n", "CHECK REACTION");
        case SUCCESS: fout << "State is SUCCESS "; //fprintf( pFile, "State is %s\n", "SUCCESS");
        default: fout << "State is FAIL "; //fprintf( pFile, "State is %s\n", "FAIL");
    }
    /*fprintf( pFile, "trigger = %d\n", trigger);
	fprintf( pFile, "release = %d\n", release);
    fprintf( pFile, "final = %d\n", final);
	fprintf( pFile, "delay = %d\n", delay);
    fprintf( pFile, "invariant = %d\n", invariant);
	fprintf( pFile, "reaction = %d\n", reaction);*/
    fout << "trigger = " << edtlAttributes.trigger << " ";
    fout << "release = " << edtlAttributes.release << " ";
    fout << "final = " << edtlAttributes.final << " ";
    fout << "delay = " << edtlAttributes.delay << " ";
    fout << "invariant = " << edtlAttributes.invariant << " ";
    fout << "reaction = " << edtlAttributes.reaction << " ";
};
