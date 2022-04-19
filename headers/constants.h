#ifndef CONSTANTS_H
#define CONSTANTS_H

enum requirementId { 
    REQ0, 
    REQ1, 
    REQ2, 
    REQ3, 
    REQ4, 
    REQ5,
    MAX_REQ
};

enum state { 
    CHECK_TRIGGER,
    CHECK_FINAL,
    CHECK_REACTION, 
    SUCCESS,
    FAIL,
};

enum variableType{
    inputVariable,
    outputVariable,
};

struct EdtlAttributes{
    bool trigger, release, final, delay, invariant, reaction;
};

#endif
