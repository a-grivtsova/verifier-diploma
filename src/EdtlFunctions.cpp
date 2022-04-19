#include "../headers/EdtlFunctions.h"

EdtlFunctions::EdtlFunctions(/* args */)
{}

EdtlFunctions::~EdtlFunctions()
{}

void EdtlFunctions::calculate(VerificationFSM *fsm, std::map <std::string, PortVariable*> &v, requirementId id) {
    /*bool trigger, release, final, delay, invariant, reaction;*/
    EdtlAttributes edtlAttributes;

    switch (id) {
        case REQ0: {
            edtlAttributes.trigger = v["Hand"]->prev || v["Dryer"]->prev && !v["Hand"]->cur ^ v["Dryer"]->cur;
            edtlAttributes.release = v["Hand"]->prev || v["Dryer"]->prev && !v["Hand"]->cur;
            edtlAttributes.final = v["Hand"]->prev || v["Dryer"]->prev;
            edtlAttributes.delay = v["Hand"]->prev; 
            edtlAttributes.invariant = tau(fsm->getTime(), 100);
            edtlAttributes.reaction = v["Dryer"]->post;
            break;
        }
        case REQ1: {
            //TODO
            break;
        }
        case REQ2: {
            //TODO
            break;
        }
        default: {
            break;
        }
    }
    fsm->set(edtlAttributes);
};