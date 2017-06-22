#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

void problem(char *info)
{
    int sum = 0;

    int p1,p2,p5,p10,p20,p50,p100,p200;

    for (p200 = 0; p200 <= 200; p200 += 200)
        for (p100 = 0; p100 + p200 <= 200; p100 += 100)
            for (p50 = 0; p50 + p100 + p200 <= 200; p50 += 50)
                for (p20 = 0; p20 + p50 + p100 + p200 <= 200; p20 += 20)
                    for (p10 = 0; p10 + p20 + p50 + p100 + p200 <= 200; p10 += 10)
                        for (p5 = 0; p5 + p10 + p20 + p50 + p100 + p200 <= 200; p5 += 5)
                            for (p2 = 0; p2 + p5 + p10 + p20 + p50 + p100 + p200 <= 200; p2 += 2)
                                sum ++; //p1 = 200 - (p2 + p5 + p10 + p20 + p50 + p100 + p200);
    printf("Answer: %d\n", sum);
}
