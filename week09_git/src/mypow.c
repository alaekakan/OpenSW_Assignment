#include "myops.h"

double mypow(double a, double b) {
    double goal = 1;
    for (int i = 0; i < b; i++) {
        goal = goal * a;
    }
    return goal;
}