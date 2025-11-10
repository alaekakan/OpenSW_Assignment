#include <stdio.h>
#include <string.h>
#include "basic_ops.h" // 기본 '설계도'
#include "advanced_ops.h" // 고급 '설계도'

// calculate 함수 (확장됨)
double calculate(char* op, double a, double b) {
    if (strcmp(op, "+") == 0) {
        return add(a, b);
    } else if (strcmp(op, "-") == 0) {
        return sub(a, b);
    } else if (strcmp(op, "*") == 0) {
        return mul(a, b);
    } else if (strcmp(op, "/") == 0) {
        return div(a, b);
    } 
    // [추가된 부분]
    else if (strcmp(op, "%") == 0) { 
        return mymod(a, b);
    } else if (strcmp(op, "^") == 0) {
        return mypow(a, b);
    } 
    // [끝]
    else {
        printf("Unsupported operation: %s\n", op);
        return 0;
    }
}

// main 함수 (동일함)
int main() {
    double a, b;
    char op[3]; 

    printf("Enter expression (e.g., 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b); 

    printf("Result = %.2lf\n", calculate(op, a, b));
    return 0;
}