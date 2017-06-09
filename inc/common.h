#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


//Prime functions
int generate_primes(unsigned long long n);
bool is_prime(unsigned long long n);
unsigned long long get_prime(unsigned int i);

//Get row
bool get_row(char **start, char *row);

//Sum of divisors
unsigned int sum_of_divisors(unsigned int n);

//Factorial
unsigned int factorial(unsigned int n);

#endif
