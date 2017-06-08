#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{   
    char sumr[55] = "0000000000000000000000000000000000000000000000000000000";
    char *start = info;
    char row[100];
    char digits[50];
    unsigned int carry = 0;
    int i;
    unsigned int temp_sum;
    //Scan info for digits and calculate sum
    while (get_row(&start, row) != 0) {
        //If the first 50 characters are numerical
        if (sscanf(row, "%50[0-9]", digits) == 1) {
            //Calculate sum of 50 digit integers
            for (i = 0; i < 50; i++) {
                temp_sum = (sumr[i] - '0') + (digits[49-i] - '0') + carry;
                sumr[i] = (temp_sum % 10) + '0';
                carry = temp_sum / 10;
            }
            //Now sumr contains the lower 50 digits of the sum in reversed order
            while (carry > 0) {
                temp_sum = (sumr[i] - '0') + carry;
                sumr[i++] = (temp_sum % 10) + '0';
                carry = temp_sum / 10;
            }
            //Now sumr contains the sum in reversed order
        }
    }

    //Get upper ten digits into sum
    i = 54;
    while (sumr[i] == '0') i--;
    char sum[11];
    int j;
    for (j = 0; j < 10; j++) {
        sum[j] = sumr[i--];
    }
    sum[10] = '\0';
    
    printf("Answer: %s\n", sum);
}
