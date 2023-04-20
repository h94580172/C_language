#include <stdio.h>

typedef union {
    struct {
        unsigned int ALT : 1;
        unsigned int USB : 1;
        unsigned int PD : 1;
        unsigned int DC : 1;
        unsigned int reserved : 4;
    } st;
    unsigned char state;
} state_t;

int main() {

    state_t gv31;
    gv31.state = 0x07;
    if(gv31.state && gv31.st.ALT == 1) {
        printf("ALT: %d\n", gv31.st.ALT);
    }
    if(gv31.state && gv31.st.USB == 1) {
        printf("USB: %d\n", gv31.st.USB);
    }
    if(gv31.state && gv31.st.PD == 1) {
        printf("PD: %d\n", gv31.st.PD);
    }
    if(gv31.state && gv31.st.DC == 0) {
        printf("DC: %d\n", gv31.st.DC);
    }
    return 0;
}
