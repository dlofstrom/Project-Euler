#include "common.h"

//Prime variables
static FILE *fp;
static unsigned long long *primes;
static unsigned int psize;
static unsigned long long pgenerated;


//Load primes into array
int load_primes() {
    primes = malloc(sizeof(unsigned long long));
    *primes = 0;
    psize = 0;
    //Open prime list file
    fp = fopen("./primes", "r");
    if (fp != NULL) {
        //Load numbers from file
        char line[20];
        unsigned long long prime;
        //First line contains tested numbers
        if (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%llu", &prime) != 0) {
                pgenerated = prime;
            }
        }
        //Load rest of lines into prime array
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%llu", &prime) != 0) {
                primes = realloc(primes, (psize + 1)*sizeof(unsigned long long));
                if (primes == NULL) {
                    printf("Not enough memory (realloc returned NULL)\n");
                    return 1;
                }
                primes[psize++] = prime;
            }
        }
        fclose(fp);
    } else {
        //File does not exist, generade first prime
        generate_primes(10);
    }
    return 0;
}


//Start generating primes at end of list and write to file
int generate_primes(unsigned long long n) {
    printf("Generating primes up to %llu\n", n);

    if (psize == 0) {
        primes = realloc(primes, sizeof(unsigned long long));
        primes[psize++] = 2;
    }
    unsigned long long start = primes[psize-1] + 1;
    
    //Test prime with other known primes exhaustive
    unsigned long long p;
    unsigned long long t;
    for (p = start; p <= n; p++) {
        int ip = 1;
        for (t = 0; t < psize; t++) {
            if (p % primes[t] == 0) {
                ip = 0;
                break;
            }
        }
        if (ip == 1) {
            primes = realloc(primes, (psize + 1)*sizeof(unsigned long long));
            if (primes == NULL) {
                printf("Not enough memory (realloc returned NULL)\n");
                return 1;
            }
            primes[psize++] = p;
        }
    }
    pgenerated = n;
    
    fp = fopen("./primes", "w");
    fprintf(fp, "%llu\n", pgenerated);
    for (p = 0; p < psize; p++) {
        fprintf(fp, "%llu\n", primes[p]);
    }
    fclose(fp);
    return 0;
}


//Check if number is prime by looking for it in list
bool is_prime(unsigned long long n) {
    //If first time called
    if (primes == NULL) {
        load_primes();
    }
    //If last prime < n
    if (pgenerated < n) {
        generate_primes(n);
    }
    unsigned int i;
    //printf("Length of prime array %u\n", psize);

    for (i = 0; i < psize; i++) {
        if (n == primes[i]) return 1;
    }
    return 0;
}

//Get prime by index
unsigned long long get_prime(unsigned int i) {
    //If first time called
    if (primes == NULL) {
        load_primes();
    }
    //If last prime < n
    while (psize-1 < i) {
        generate_primes(pgenerated + 1000);
    }

    return primes[i];
}


//Get row, returns start of next row
bool get_row(char **start, char *row) {
    char *stop = *start;
    //move to end of line
    while (*stop != '\n' && *stop != '\0') stop++;
    strncpy(row, *start, stop-(*start));
    row[stop-(*start)] = '\0';
    
    if (*stop != '\0') {
        *start = stop + 1;
        return true;
    } else {
        *start = stop;
        return false;
    }
}


//Sum of divisors
unsigned int sum_of_divisors(unsigned int n) {
    unsigned int s = 0;
    unsigned int ns = (unsigned int)sqrt(n);
    unsigned int i;
    for (i = 1; i <= ns; i++) {
        if (n % i == 0) {
            if (i == n/i || i == 1) s += i;
            else s += i + n/i;
            
        }
    }
    return s;
}
