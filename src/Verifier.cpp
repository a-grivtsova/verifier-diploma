#include "../headers/Verifier.h"

typedef uint8_t T;

Verifier::Verifier(T *_i_ports, T *_o_ports) {
    variablesHandler.setPorts(_i_ports, _o_ports);
    for(int i = 0; i < MAX_REQ; ++i)
        requirements.push_back(new Requirement((requirementId)i));
};

Verifier::~Verifier() {
    for (auto requirement : requirements) {
        delete requirement;
    }
    requirements.clear();
};

void Verifier::run() {
    variablesHandler.read();

    for(auto requirement : requirements) {
        requirement->checkVerificationFSMs();
        requirement->refreshAttributes(variablesHandler);
        requirement->run();
        logger.log(requirement, &variablesHandler);
    }

};
