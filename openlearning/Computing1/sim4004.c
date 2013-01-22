/* Graeme Ball
 * 18/12/12
 *
 * Program to simulate a "4004 series microprocessor" used in
 * the OpenLearning Computing 1 course (UNSW).
 *
 * Simple implementation using commands from weeks 0-8.
 * NB. could not think of a reasonable solution without using
 *     while and an array (could've instead used for/goto & pointers)
 *
 * to compile: gcc -O -Wall -Werror -o sim4004 sim4004.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define TRUE 1
#define FALSE 0
#define NUM_CELLS 16
#define MAX_CYCLES 10000
#define TEST 0
 
 
/* function prototypes */
int run_processor(int cell_values[]);
int check_range(int value);
 
 
/* Run the simulator using program entered by user and print results */
int main(int argc, char *argv[])
{
 
    int program[NUM_CELLS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int instruction;
    int outlen;
    int i;
 
    /* get program */
    //printf("\n\ntype 16 instructions (0-15), each followed by enter\n");
    i = 0;
    while (i < NUM_CELLS) {
        //printf(" instruction %d: ", i);
        scanf("%d", &instruction);
        assert(instruction >= 0);
        assert(instruction < NUM_CELLS);
        program[i] = instruction;
        i++;
    }
 
    /* run program */
    //printf("\n\nrunning: \n");
    i = 0;
    while (i < NUM_CELLS) {
        //printf(" %d", program[i]);
        i++;
    }
    //printf("\n  output: ");
    outlen = run_processor(program);
    //printf("output length: %d characters\n\n", outlen);
    printf("%d\n", outlen);
 
 
    /* tests for check_range() function */
    if (TEST) {
        printf("\ntest check_range() ...\n======================\n");
        printf("  16->%d\n", check_range(16));
        printf("  18->%d\n", check_range(18));
        printf("  0->%d\n", check_range(0));
        printf("  15->%d\n", check_range(15));
        printf("  -2->%d\n", check_range(-2));
    }
 
    /* test programs and expected output */
    if (TEST) {
        printf("\ntest run_processor() ...\n========================");
        /* test 1, 3 character busy beaver */
        printf("\nTest 1: 7 1 8 0 0 0 0 0 0 0 0 0 0 0 0 0\n  expect 0-15\n  ");
        int test1[NUM_CELLS] = { 7, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int outlen1 = run_processor(test1);
        printf(" %d output characters\n", outlen1);
 
        /* test 2, 4004-IF (cell 15 not 2, output 1) */
        printf("\nTest 2: 11 2 14 15 6 8 11 10 0 7 0 10 1 7 0 0\n  expect 1\n  ");
        int test2[NUM_CELLS] = { 11, 2, 14, 15, 6, 8, 11, 10, 0, 7, 0, 10, 1, 7, 0, 0 };
        int outlen2 = run_processor(test2);
        printf(" %d output characters\n", outlen2);
 
        /* test 3, 4004-IF (cell 15 is 2, output 0) */
        printf("\nTest 3: 11 2 14 15 6 8 11 10 0 7 0 10 1 7 0 2\n  expect 0\n  ");
        int test3[NUM_CELLS] = { 11, 2, 14, 15, 6, 8, 11, 10, 0, 7, 0, 10, 1, 7, 0, 2 };
        int outlen3 = run_processor(test3);
        printf(" %d output characters\n", outlen3);
 
        /* test 4, remaining instructions, 3 4 5 9 12 13 (if no & instr 12) */
        printf("\nTest 4: 3 3 3 4 5 7 9 0 12 12 2 7 0 0 0 0\n  expect 2 1\n  ");
        int test4[NUM_CELLS] = {3, 3, 3, 4, 5, 7, 9, 0, 12, 12, 2, 7, 0, 0, 0, 0};
        int outlen4 = run_processor(test4);
        printf(" %d output characters\n", outlen4);
 
        /* test 5, remaining instructions, 3 4 5 9 12 13 (if yes & instr 13) */
        printf("\nTest 5: 3 4 5 7 9 7 0 4 13 11 10 0 7 0 0 0\n  expect 0 15\n  ");
        int test5[NUM_CELLS] = {3, 4, 5, 7, 9, 7, 0, 4, 13, 11, 10, 0, 7, 0, 0, 0};
        int outlen5 = run_processor(test5);
        printf(" %d output characters\n\n", outlen5);
    }
 
    return EXIT_SUCCESS;
}
 
 
/* Execute a program on the 4004 series microprocessor
 * return number of output characters
 * NB. function prints output (side-effect) for simplicity
 */

int run_processor(int cell[])
{
 
    /* Behavior to reproduce:-
     * 1. has 16 memory cells numbered 0-15
     * 2. has two registers R0 and R1, and a swap register
     * 3. cycles until halt instruction 0
     * 4. "wrapping": 15+1=0, 0-1=15 etc. (cells, registers & pointer)
     * 5. cycle count and instruction pointer increment at cycle end
     * 6. for instruction descriptions, see "if" test comments below
     */
 
    /* set up processor cycle */
    int run = TRUE;
    int cycle = 0;
 
    /* set up processor register storage */
    int r0 = 0;
    int r1 = 0;
    int swp = 0;
 
    /* "instruction pointer" for the current cell (0-15) */
    int ip = 0;
 
    /* output length */
    int outlen = 0;
 
 
    /* processor cycle loop - breaks on instruction 0 or MAX_CYCLES */
    while (run) {
 
        /* execte instruction according to cell value */
        if (cell[ip] == 0) {
            /* 0: Halt */
            run = FALSE;
        } else if (cell[ip] == 1) {
            /* 1: Increment R0 (R0 = R0 + 1) */
            r0++;
            r0 = check_range(r0);
        } else if (cell[ip] == 2) {
            /* 2: Decrement R0 (R0 = R0 - 1) */
            r0--;
            r0 = check_range(r0);
        } else if (cell[ip] == 3) {
            /* 3: Increment R1 (R1 = R1 + 1) */
            r1++;
            r1 = check_range(r1);
        } else if (cell[ip] == 4) {
            /* 4: Decrement R1 (R1 = R1 - 1) */
            r1--;
            r1 = check_range(r1);
        } else if (cell[ip] == 5) {
            /* 5: Add (R0 = R0 + R1) */
            r0 += r1;
            r0 = check_range(r0);
        } else if (cell[ip] == 6) {
            /* 6: Subtract (R0 = R0 - R1) */
            r0 -= r1;
            r0 = check_range(r0);
        } else if (cell[ip] == 7) {
            /* 7: Print R0; Ring Bell */
            outlen++;
            if (r0 > 9)
                outlen++;
            //printf("%d ", r0);
        } else if (cell[ip] == 8) {
            /* 8: Jump to address <data> if R0 != 0 */
            ip++;
            ip = check_range(ip);
            if (r0 != 0) {
                ip = cell[ip];
                ip--;  /* want to execute ip, but ip++ below */
            }
        } else if (cell[ip] == 9) {
            /* 9: Jump to address <data> if R0 == 0 */
            ip++;
            ip = check_range(ip);
            if (r0 == 0) {
                ip = cell[ip];
                ip--;  /* want to execute ip, but ip++ below */
            }
        } else if (cell[ip] == 10) {
            /* 10: Load <data> in to R0 */
            ip++;
            ip = check_range(ip);
            r0 = cell[ip];
        } else if (cell[ip] == 11) {
            /* 11: Load <data> in to R1 */
            ip++;
            ip = check_range(ip);
            r1 = cell[ip];
        } else if (cell[ip] == 12) {
            /* 12: Store R0 into address <data> */
            ip++;
            ip = check_range(ip);
            cell[cell[ip]] = r0;
        } else if (cell[ip] == 13) {
            /* 13: Store R1 into address <data> */
            ip++;
            ip = check_range(ip);
            cell[cell[ip]] = r1;
        } else if (cell[ip] == 14) {
            /* 14: Swap R0 and address <data> */
            ip++;
            ip = check_range(ip);
            swp = r0;
            r0 = cell[cell[ip]];
            cell[cell[ip]] = swp;
        } else if (cell[ip] == 15) {
            /* 15: Swap R1 and address <data> */
            ip++;
            ip = check_range(ip);
            swp = r1;
            r1 = cell[cell[ip]];
            cell[ip] = swp;
        } else {
            /* PROGRAM ERROR */
            printf("Program error - bad instruction, %d\n", cell[ip]);
            run = FALSE;
        }
 
        /* stop when we reach MAX_CYCLES */
        if (cycle >= MAX_CYCLES) {
            run = FALSE;
        }
 
        /* increment cycle number and ip, make sure ip is 0-15 */
        cycle++;
        ip++;
        ip = check_range(ip);
    }

    if (cycle >= MAX_CYCLES) {
        //printf("max reached");
        outlen = 0;
    } else {
        //printf("(%d cycles)\n", cycle);
    }
 
    return outlen;
}
 
 
/* Check a cell index is within range
 * return a cell index within range
 */
int check_range(int value)
{
    if (value > (NUM_CELLS-1))
        value = value - NUM_CELLS;
 
    if (value < 0)
        value = NUM_CELLS + value;
 
    return value;
}
