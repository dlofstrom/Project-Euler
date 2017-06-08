#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "common.h"

unsigned int days(unsigned int year) {
    //Check for leap year
    if (year % 400 == 0) return 366;
    else if (year % 100 == 0) return 365;
    else if (year % 4 == 0) return 366;
    else return 365;
}

unsigned int starting_day(unsigned int month, unsigned int ynd, unsigned int ysd) {
    //+1 day if leap year
    unsigned int ly = (ynd == 366) ? 1 : 0;

    switch (month) {
    case 0: //Jan
        return ysd;
        break;
    case 1: //Feb
        return (ysd + 31) % 7;
        break;
    case 2: //Mar
        return (ysd + 59 + ly) % 7;
        break;
    case 3: //Apr
        return (ysd + 90 + ly) % 7;
        //30
        break;
    case 4: //May
        return (ysd + 120 + ly) % 7;
        break;
    case 5: //Jun
        //30
        return (ysd + 151 + ly) % 7;
        break;
    case 6: //Jul
        return (ysd + 181 + ly) % 7;
        break;
    case 7: //Aug
        return (ysd + 212 + ly) % 7;
        break;
    case 8: //Sep
        return (ysd + 243 + ly) % 7;
        //30
        break;
    case 9: //Oct
        return (ysd + 273 + ly) % 7;
        break;
    case 10: //Nov
        return (ysd + 304 + ly) % 7;
        //30
        break;
    case 11: //Dec
        return (ysd + 334 + ly) % 7;
        break;
    default:
        return 0;
        break;
    }
}

void problem(char *info)
{
    unsigned int sum = 0;

    //Starting day for 1901, 1900 is on a Monday
    unsigned int sd = (days(1900) + 1) % 7;
    printf("1901 starts on %u\n", sd);
    unsigned int y, nd, m;
    for (y = 1901; y <= 2000; y++) {
        nd = days(y);

        //Count months starting on a Sunday
        for (m = 0; m < 12; m++) {
            if (starting_day(m, nd, sd) == 0) sum++;
        }
                
        //Offset starting day
        sd = (nd + sd) % 7;
    }
    
    printf("Answer: %u\n", sum);
}
