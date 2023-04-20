#include <stdio.h>

typedef unsigned char u8;

enum {
    ProjCtrlLS_USB,
    ProjCtrlLS_AltPortGetDev,
    ProjCtrlLS_AltPd_DCJack,
    ProjCtrlLS_AltPd_DCEmpty,
    ProjCtrlLS_AltDischage,
    ProjCtrlLS_Init
};

typedef struct customization_projector_s {
    void (*fpProjectorCtrlLS)(u8 Status);
} custom;

custom c;

void ProjectorCtrlLS(u8 Status) {
    switch (Status) {
        case ProjCtrlLS_USB:
            printf("USB");
            break;

        case ProjCtrlLS_AltPortGetDev:
            printf("AltPortGetDev");
            break;

        case ProjCtrlLS_AltPd_DCJack:
            printf("AltPd_DCJack");
            break;

        case ProjCtrlLS_AltPd_DCEmpty:
            printf("AltPd_DCEmpty");
            break;
            
        case ProjCtrlLS_AltDischage:
            printf("AltDischage");
            break;
            
        case ProjCtrlLS_Init:
            printf("Init");
            break;
            
        default:
            printf("default");
            break;
    }
}

void initializeCustomization() {
    c.fpProjectorCtrlLS = ProjectorCtrlLS;
}

int main() {
    initializeCustomization();
    c.fpProjectorCtrlLS(ProjCtrlLS_USB);
    return 0;
}
