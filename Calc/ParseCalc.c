/*
 * A simple recursive descent parser 
 * for evaluating mathematical formulae.
 * 
 * ________  parseSum()
 * ___ ____  parseProduct()
 * _ _ _ _   parseFactor()
 * 2+3*4+5
 * 
 * Ref: https://www.youtube.com/watch?v=N55XNj8KjC4
 * 
 */


#include <stdio.h>

double parseSum();
double parseProduct();
double parseFactor();
double parseNumber();

char *x ;

double parseSum()
{
    double pro1 = parseProduct();
    while (*x == '+'|*x == '-')
    {
        char op = *x;
        ++x;
        double pro2 = parseProduct();
        if(op == '+'){
            pro1 = pro1 + pro2;
        } else {
            pro1 = pro1 - pro2;
        }
        printf("parseSum(%c) = %.3f\n", op, pro1);
    }
    return pro1;
}

double parseProduct()
{
    double fac1 = parseFactor();
    while (*x == '*'|*x == '/')
    {
        char op = *x;
        ++x;
        double fac2 = parseFactor();
        if(op == '*'){
            fac1 = fac1 * fac2;
        } else if(fac2 != 0){
            fac1 = fac1 / fac2;
        } else {
            printf("Divide by zero error");
        }
        printf("parseProduct(%c) = %.3f\n", op, fac1);
    }
    return fac1;
}

double parseFactor()
{
    if (*x >= '0' && *x <= '9')
    {
        double digits = parseNumber();
        return digits;
    } 
    else if (*x == '(') 
    {
        ++x ; // consume (
        double sum = parseSum();
        ++x ; // consume )
        printf("parseFactor() = ()\n");
        return sum;
    } 
    else 
    {
        printf("Expected digit but found %c\n", *x);
        return 0;
    }
}

double parseNumber()
{
    double number = 0;
    while (*x >= '0' && *x <= '9')
    {
        number = number * 10;
        number = number + (*x - '0');
        ++x;
    }
    if(*x == '.')
    {
        ++x; // consumer '.'
        double weight = 1;
        while (*x >= '0' && *x <= '9')
        {
            weight = weight / 10;
            double scaled = (*x - '0') * weight;
            number = number + scaled;
            ++x;
        }
    }
    printf("parseNumber() = %.3f\n", number);
    return number;
}

int main() 
{
    x = "2*3+4*5";
    x = "2*((31+4-15)*10.0)/4+1.51255";
    printf("Expr = %s\n", x);
    double result = parseSum();
    printf("result = %.3f\n", result);
    return 0;
}
