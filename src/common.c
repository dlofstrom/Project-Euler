#include "common.h"

//Prime variables
static FILE *fp;
static uint64_t *primes;
static uint32_t psize;
static uint64_t pgenerated;


//Load primes into array
uint8_t load_primes() {
    primes = malloc(sizeof(uint64_t));
    *primes = 0;
    psize = 0;
    //Open prime list file
    fp = fopen("./primes", "r");
    if (fp != NULL) {
        //Load numbers from file
        char line[20];
        uint64_t prime;
        //First line contains tested numbers
        if (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%llu", &prime) != 0) {
                pgenerated = prime;
            }
        }
        //Load rest of lines into prime array
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "%llu", &prime) != 0) {
                primes = realloc(primes, (psize + 1)*sizeof(uint64_t));
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
uint8_t generate_primes(uint64_t n) {
    printf("Generating primes up to %llu\n", n);

    if (psize == 0) {
        primes = realloc(primes, sizeof(uint64_t));
        primes[psize++] = 2;
    }
    uint64_t start = primes[psize-1] + 1;
    
    //Test prime with other known primes exhaustive
    uint64_t p;
    uint64_t t;
    for (p = start; p <= n; p++) {
        uint8_t ip = 1;
        for (t = 0; t < psize; t++) {
            if (p % primes[t] == 0) {
                ip = 0;
                break;
            }
        }
        if (ip == 1) {
            primes = realloc(primes, (psize + 1)*sizeof(uint64_t));
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
uint8_t is_prime(uint64_t n) {
    //If first time called
    if (primes == NULL) {
        load_primes();
    }
    //If last prime < n
    if (pgenerated < n) {
        generate_primes(n);
    }
    uint32_t i;
    //printf("Length of prime array %u\n", psize);

    for (i = 0; i < psize; i++) {
        if (n == primes[i]) return 1;
    }
    return 0;
}

//Get prime by index
uint64_t get_prime(uint32_t i) {
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
