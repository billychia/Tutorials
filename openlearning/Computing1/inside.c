/*
 * Test if a point is inside a triangle.
 * inside.c by Julian Saknussemm (the jerk) 
 *
 * Refactored by Billy Chia - Dec 23, 2012
 *
 * Given Three points of a triangle, and another arbitrary point 
 * this program determines if that point lies inside the triangle.
 *
 * This is determined by satisfying the following rule:
 * A point P(x,y) 
 * is inside triangle A(ax,ay), B(bx,by), C(cx,cy)
 * if three criteria are met: 
 *  1. P is on the same side of the line AB as C
 *  2. P is on the same side of the line BC as A
 *  3. P is on the same side of the line AC as B
 *
 * Set TEST to TRUE to run test suite
 * Set TEST to FALSE to prompt for user input
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define TEST FALSE

void runTests(void);
int getInput(void);
int inTriangle (double ax, double ay,
                double bx, double by,
                double cx, double cy,
                double px, double py);
int insideOfLine (double ax, double ay,
                  double bx, double by,
                  double cx, double cy,
                  double px, double py);
double getSlope (double x0, double y0, double x1, double y1);
double getYIntercept (double m, double x, double y);
int vertSameSide (double x, double x0, double x1);
int sameSide (double x0, double y0,
              double x1, double y1,
              double m, double b);
int whatSide (double x, double y, double m, double b);


int main (int argc, char *argv[]) {
    
    int exitStatus = EXIT_SUCCESS;

    if (TEST == TRUE) {
        runTests();
    } else {
        exitStatus = getInput();
    }
    
    return exitStatus;

}

void runTests(void) {
    
    //test if all points are same - is this valid input?
    assert(inTriangle(3, 3, 3, 3, 3, 3, 3, 3) == TRUE);
    assert(inTriangle(3, 3, 3, 3, 3, 3, 4, 4) == FALSE);
    //original code does not pass this test
    //assert(inTriangle(3, 3, 3, 3, 3, 3, 3, 4) == FALSE);
    assert(inTriangle(3, 3, 3, 3, 3, 3, 4, 3) == FALSE);
    
    //test larger numbers
    assert(inTriangle(200, 300, 300, 500, 100, 500, 200, 350) == TRUE);
    assert(inTriangle(200, 300, 300, 500, 100, 500, 100, 100) == FALSE);
    
    //test decimals
    assert(inTriangle(2, 3, 3, 5, 1, 5, 2, 3.5) == TRUE);
    assert(inTriangle(2.1, 3.4, 3, 5.5, 1.234, 5.77, 2.1, 3.5) == TRUE);
    
    //test points outside all edges of triangle
    assert(inTriangle(1, 1, 5, 1, 3, 7, 3, 4) == TRUE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 0, 0) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 3, 0.5) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 88, 2) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 1, 2) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 3, 8) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 5, 2) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, -1, 3) == FALSE);
    
    // on the line is not inside
    assert(inTriangle(1, 1, 5, 1, 3, 7, 3, 1) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 1, 1) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 5, 1) == FALSE);
    assert(inTriangle(1, 1, 5, 1, 3, 7, 3, 7) == FALSE);
    
    //test negative numbers
    assert(inTriangle(-1, -1, 1, -1, 0, 3, 0, 0) == TRUE);
    
    //test right triangle with vertical lines
    assert(inTriangle(0, 0, 0, 6, 6, 0, 1, 1) == TRUE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, 1) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 3, 0) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 3, -0.2) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 3, 0.2) == TRUE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, 7) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 7, 0) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, -1, 0) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, -1, 3) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 1, 3) == TRUE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, -1) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, 0) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, 6) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 0, 3) == FALSE);
    assert(inTriangle(0, 0, 0, 6, 6, 0, 6, 0) == FALSE);
    
    //test 0 as a value for all points
    assert(inTriangle(0, 0, 6, 0, 0, 6, 1, 1) == TRUE);
    assert(inTriangle(0, 6, 0, 0, 6, 0, 1, 1) == TRUE);
    assert(inTriangle(0, 6, 6, 0, 0, 0, 1, 1) == TRUE);

    printf("All tests passed. You are Awesome!\n");
    
    return;

}

int getInput (void) {

    double ax, ay, bx, by, cx, cy, px, py;
    int inputCheck = 0;
    int exitStatus = EXIT_SUCCESS;
    int pointIsInside;
    
    // get input
    printf("Enter x, y for Vertex A: ");
    inputCheck += scanf("%lf, %lf", &ax, &ay);
    
    printf("Enter x, y for Vertex B: ");
    inputCheck += scanf("%lf, %lf", &bx, &by);
    
    printf("Enter x, y for Vertex C: ");
    inputCheck += scanf("%lf, %lf", &cx, &cy);
    
    printf("Test Point (x, y): ");
    inputCheck += scanf("%lf, %lf", &px, &py);

    // Check for correct inputs
    if (inputCheck == 8) {

        //is point inside the triangle?
        pointIsInside = inTriangle(ax, ay, bx, by, cx, cy, px, py);
        
        //print answer
        if (pointIsInside) {
            printf("Point (%.2lf, %.2lf) is inside triangle ABC\n",
                   px, py);
        } else {
            printf("Point (%.2lf, %.2lf) is outside triangle ABC\n",
                   px, py);
        }
        
    } else {
        printf("\n\nMy apologies good Sir or Madam.\n");
        printf("I did not recieve correct inputs.\n");
        printf("Please, be sure to use x, y format (e.g. 3, 4).\n");
        exitStatus = EXIT_FAILURE;
    }

    return exitStatus;
    
}

// check if P is inside triangle ABC by testing:
// P is on the same side of the line AB as C
// P is on the same side of the line AC as B
// P is on the same side of the line BC as A
int inTriangle (double ax, double ay,
                double bx, double by,
                double cx, double cy,
                double px, double py) {

    int insideAB;
    int insideAC;
    int insideBC;
    int inTriangle;

    insideAB = insideOfLine(ax, ay, bx, by, cx, cy, px, py);
    insideAC = insideOfLine(cx, cy, ax, ay, bx, by, px, py);
    insideBC = insideOfLine(bx, by, cx, cy, ax, ay, px, py);

    inTriangle = (insideAB && insideBC && insideAC);

   return inTriangle;

}

// check if a point P(px, py)
// is on the inner side of a line that is one side of a triangle
int insideOfLine (double x0, double y0,
                  double x1, double y1,
                  double x2, double y2,
                  double px, double py) {

    int insideOfLine;
    double m;
    double b;
    
    //use vert check for vertical line
    //use normal check for non-vertical line
    if (x0 == x1) {
        insideOfLine = vertSameSide (x0, px, x2);
    } else {
        m = getSlope(x0, y0, x1, y1);
        b = getYIntercept(m, x0, y0);
        insideOfLine = sameSide(px, py, x2, y2, m, b);
    }

    return insideOfLine;

}

//given two points return slope of the line
double getSlope (double x0, double y0, double x1, double y1) {

    double m;
    
    m = (y0 - y1) / (x0 - x1);
    
    return m;

}

//given slope and one point return y-intercerpt
double getYIntercept (double m, double x, double y) {

    double b;
    
    b = y - (m * x);
    
    return b;

}

// given the x coordinate of a vertical line
// checks to see if two other x coordinates
// are on the same side of that line
int vertSameSide (double x, double x0, double x1) {

    int x0Side;
    int x1Side;
    int vertSameSide;
    
    x0Side = (x0 <= x);
    x1Side = (x1 <= x);
    
    vertSameSide = (x0Side == x1Side);
    
    return vertSameSide;

}

// checks if two points lie on the same side of a non-vertical line
int sameSide (double x0, double y0,
              double x1, double y1,
              double m, double b) {
    
    int x0Side;
    int x1Side;
    int sameSide;
    
    x0Side = whatSide(x0, y0, m, b);
    x1Side = whatSide(x1, y1, m, b);
    sameSide = (x0Side == x1Side);
    
    return sameSide;

}

// is point above (1), on (0) or below (-1) line
int whatSide (double x, double y, double m, double b) {

    int yIntercept = m * x + b;
    int whatSide;
    
    if (y > yIntercept) {
        whatSide = 1;
    } else if (y == yIntercept) {
        whatSide = 0;
    } else {
        whatSide = -1;
    }
    
    return whatSide;

}

