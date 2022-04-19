#include <stdint.h>
#include "./headers/Verifier.h"

int main() {
    uint8_t in_ps[] = {255,2,3};
    uint8_t out_ps[] = {1,0,1};

    Verifier verifier = Verifier(in_ps, out_ps);
    verifier.run();
    return 0;
}
