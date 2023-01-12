#include <stdio.h>
#include <stdbool.h>
#include "mylib/mylib.h"

void wmachine_onslow(){

    printf("  _________________\n");
    printf(" |                 |     Status : On\n");
    printf(" |   ___________   |     Speed  : Slow\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||         O|  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||__________|  |\n");
    printf(" |                 |\n");
    printf(" |_________________|\n");
}

void wmachine_onfast(){

    printf("  _________________\n");
    printf(" |                 |     Status : On\n");
    printf(" |   ___________   |     Speed  : Fast\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||         O|  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||__________|  |\n");
    printf(" |                 |\n");
    printf(" |_________________|\n");
}
void wmachine_off(){

    printf("  _________________\n");
    printf(" |                 |     Status : Off\n");
    printf(" |   ___________   |     Speed  : -\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||         O|  |\n");
    printf(" |  ||          |  |\n");
    printf(" |  ||__________|  |\n");
    printf(" |                 |\n");
    printf(" |_________________|\n");
}

int main(void){
    // Set initial state.
    int s0 = 0, s1 = 0, b0 = 0, b1 = 0, n0 = 0, n1 = 0, o0 = 0, o1 = 0;

    // Loop.
    while(true){
        if ((s0 == 0) && (s1 == 0)){
            //wmachine_off(); // The washing machine is off
            if ((b0 == 0) && (b1 == 0)){
                wmachine_off(); // No inputs
            } else if ((b0 == 0) && (b1 == 1)){
                wmachine_onslow(); // 01 is the ON/OFF button, so the washing machine turns on.
            } else if ((b0 == 1) && (b1 == 0)){
                wmachine_off(); // 10 is the SWING button, so the washing machine stays off.
            }
        }
        else if((s0 == 0) && (s1 == 1)){
            //wmachine_onslow(); // washing machine is on and slow speed
            if ((b0 == 0) && (b1 == 0)){
                wmachine_onslow(); // No inputs, so nothing changes.
            } else if((b0 == 0) && (b1 == 1)){
                wmachine_off(); // ON/OFF button is pressed, so the washing machien turns off.
            } else if((b0 == 1) && (b1 == 0)){
                wmachine_onfast(); // SWING button is pressed, so the washing machine is on and fast.
            }
        }
        else if((s0 == 1) && (s1 == 0)){
            //wmachine_onfast(); // speed is fast state
            if ((b0 == 0) && (b1 == 0)){
                wmachine_onfast(); // No inputs.
            } else if((b0 == 0) && (b1 == 1)){
                wmachine_off(); // ON/OFF button is pressed, so the washing machine turns off.
                
            } else if((b0 == 1) && (b1 == 0)){
                wmachine_onslow(); // speed button is press
            }
        }
        int button;
        printf("Select a button ([1] for ON/OFF | [2] for SPEED): ");
        scanf("%d", &button);

        if (button == 0){
            b0 = 0;
            b1 = 0;
        } else if (button == 1){
            b0 = 0;
            b1 = 1;
        } else if (button == 2){
            b0 = 1;
            b1 = 0;
        } 

        states( s0,  s1,  b0,  b1, &n0, &n1, &o0, &o1);
    }

    return 0;

}
