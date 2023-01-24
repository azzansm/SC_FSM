#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "mylib/mylib.h"

void green()
{
    printf("\033[1;32m");
}

void red()
{
    printf("\033[1;31m");
}

void reset()
{
    printf("\033[0m");
}

void wmachine_onslow()
{

    green();
    printf("  __________________\n");
    printf(" |_ON_|_SLOW________|\n");
    reset();
    printf(" |     ________     |\n");
    printf(" |    //       \\    |\n");
    printf(" |   //    /    \\   |\n");
    printf(" |  ((   / / /  ))  |\n");
    printf(" |   \\   /     //   |\n");
    printf(" |    \\_______//    |\n");
    printf(" |__________________|\n");
}

void wmachine_onfast()
{

    green();
    printf("  __________________\n");
    printf(" |_ON_|_FAST________|\n");
    reset();
    printf(" |     ________     |\n");
    printf(" |    //   /   \\  ) |\n");
    printf(" |   //  / / /  \\   |\n");
    printf(" |  (( / / / /  ))  |\n");
    printf(" |   \\  / / /  //   |\n");
    printf(" | (  \\_______//    |\n");
    printf(" |__________________|\n");
}

void wmachine_off()
{

    red();
    printf("  __________________\n");
    printf(" |_OFF_|____________|\n");
    reset();
    printf(" |     ________     |\n");
    printf(" |    //       \\    |\n");
    printf(" |   //         \\   |\n");
    printf(" |  (            )  |\n");
    printf(" |   \\         //   |\n");
    printf(" |    \\_______//    |\n");
    printf(" |__________________|\n");
}


int main(void){
    // initial state
    int s0 = 0, s1 = 0, b0 = 0, b1 = 0, n0 = 0, n1 = 0, o0 = 0, o1 = 0;

    while (true) {
        printf("\033[2J"); // clear screen
        printf("\033[1;1H"); // cursor to upper left

        if ((s0 == 0) && (s1 == 0)) {
          wmachine_off(); // the washing machine is off
          printf("Current state: %d %d", s0, s1);
          printf("\nInput: %d %d", b0, b1);
          printf("\nOutput: %d %d\n", o0, o1);

        } else if ((s0 == 0) && (s1 == 1)) {
          wmachine_onslow(); // washing machine is on at a low speed
          printf("Current state: %d %d", s0, s1);
          printf("\nInput: %d %d", b0, b1);
          printf("\nOutput: %d %d\n", o0, o1);

        } else if ((s0 == 1) && (s1 == 0)) {
          wmachine_onfast(); // washing machine is on at a high speed
          printf("Current state: %d %d", s0, s1);
          printf("\nInput: %d %d", b0, b1);
          printf("\nOutput: %d %d\n", o0, o1);
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
