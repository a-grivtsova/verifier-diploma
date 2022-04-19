#include "constants.h"
#include <iostream>
#include <ctime>
#include <fstream>

#ifndef VERIFICATION_FSM_H
#define VERIFICATION_FSM_H

class VerificationFSM {
    private:
        int id;
        state curState;
        clock_t time;
        EdtlAttributes edtlAttributes;
        //bool trigger, release, final, delay, invariant, reaction;

        void checkTrigger ();
        void checkFinal ();
        void checkReaction ();
        void setState(state);

    public:
        VerificationFSM(int id);
        void verify();
        bool isCheckTrigger();
        bool isActive();
        bool isPassive();
        void logCurState(std::ofstream&);
        /*bool trigger, bool release, bool final, bool delay, bool invariant, bool reaction*/ 
        void set(EdtlAttributes);
        clock_t getTime();
};
 
#endif
