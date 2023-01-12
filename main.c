#include <stdio.h>
#include <stdbool.h>
#include "mylib/mylib.h"

void wmachine_onslow(){

    printf("  _________________\n");
    printf(" |                 |     Status : On\n");
    printf(" |   ___________   |     Speed  : Low\n");
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
    printf(" |   ___________   |     Speed  : High\n");
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
    // initial state
    int s0 = 0, s1 = 0, b0 = 0, b1 = 0, n0 = 0, n1 = 0, o0 = 0, o1 = 0;

    while(true){
        if ((s0 == 0) && (s1 == 0)){
            wmachine_off(); // the washing machine is off
            if ((b0 == 0) && (b1 == 0)){
                wmachine_off(); // no change
            } else if ((b0 == 0) && (b1 == 1)){
                wmachine_onslow(); // 01 is the on/off button, so the washing machine turns on
            } else if ((b0 == 1) && (b1 == 0)){
                wmachine_off(); // 10 is the speed button (not on/off button), so nothing changes
            }
        }
        else if((s0 == 0) && (s1 == 1)){
            wmachine_onslow(); // washing machine is on at a low speed
            if ((b0 == 0) && (b1 == 0)){
                wmachine_onslow(); // no change
            } else if((b0 == 0) && (b1 == 1)){
                wmachine_off(); // 01 is the on/off button, so the washing machine turns off
            } else if((b0 == 1) && (b1 == 0)){
                wmachine_onfast(); // speed button is pressed, so the washing machine is on at a high speed
            }
        }
        else if((s0 == 1) && (s1== 0)){
            wmachine_onfast(); // washing machine is on at a high speed
            if ((b0 == 0) && (b1 == 0)){
                wmachine_onfast(); // no change
            } else if((b0 == 0) && (b1 == 1)){
                wmachine_off(); // 01 is the on/off button, so the washing machine turns off
            } else if((b0 == 1) && (b1 == 0)){
                wmachine_onslow(); // speed button is pressed, so the washing machine is on at a low speed
            }
        }

        b0 = 0;
        b1 = 1;
        int input;
        printf("Type an input (1 for on/off // 2 for speed): ");
        scanf("%d", &input);

        if (input == 0){
            b0 = 0;
            b1 = 0;
        } else if (input == 1){
            b0 = 0;
            b1 = 1;
        } else if (input == 2){
            b0 = 1;
            b1 = 0;
        }

        calcNextState(s0, s1, b0, b1, &n0, &n1);
        s0 = n0;
        s1 = n1;
        calcOutput(s0, s1, &o0, &o1);
    }

    return 0;

}

    