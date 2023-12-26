#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#include <stdint.h>

int64_t result[10];
void setup(void);

int main(int argc, char **argv){
    int64_t var_10; /* [rbp-0x10] */
    int64_t var_18; /* [rbp-0x18] */
    int64_t var_20; /* [rbp-0x20] */
    int var_24;     /* [rbp-0x24] */

    puts("The Poopolator");
    setup();

    for(;;){
        var_10 = 0;
        printf("> \U0001f4a9   ");
        var_24 = scanf("%ld %ld %ld", &var_20, &var_18, &var_10);
        if(!var_20 || !var_18 || !var_10 || var_10 > 9 || var_24 != 3) exit(1);
        result[var_10] = var_20^var_18;
        printf("Result: %ld\n", result[var_10]);
    }

    return 0;
}