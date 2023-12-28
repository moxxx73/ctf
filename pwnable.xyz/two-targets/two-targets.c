#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setup(void);

/* Stack size: 80 bytes */
int main(int argc, char **argv){
    int var_10; /* [rbp-0x10] */
    char s[56]; /* [rbp-0x40] */
    int var_44; /* [rbp-0x44] */

    setup();
    memset(s, 0, 56);

    for(;;){
        print_menu(); 
        // => "Menu:\n  1. Change name.\n  2. Change nationality.\n  3. Change age.\n  4. Get shell.\n> "
        var_44 = read_int32();
        if(var_44 == 2){
            printf("nationality: ");
            scanf("%24s", (s+32));
        }else if(var_44 == 1){
            printf("name: ");
            scanf("%32s", s);
        }else if(var_44 == 3){
            printf("age: ");
            scanf("%d", var_10);
        }else if(var_44 == 4){
            if(auth(s)) win();
        }else puts("Invalid");
    }
    return 0;
}
