#include <stdio.h>
#include <stdlib.h>

/* Stack size: 80 bytes */
int main(int argc, char **argv){
	unsigned long var_8;  /* [rsp+0x08] */
	char *var_10;         /* [rsp+0x10] */
	char var_18[48];      /* [rsp+0x18] */

	setup();
	var_10 = malloc(64);
	/* lea r12, [rsp+0x10] */
	/* lea rbx, [rsp+0x18] */
	{
		printf("> ");
		memset(var_18, 0, 48);
		read(0, var_18, 48);
		switch(atoi(var_18)){
			case 0:
				if(!var_10) exit(1);
				free(var_10);
				return 0;
			case 1:
				read(0, var_10, 32);
				break;
			case 2:
				printf("%p\n", &var_10);
				break;
			case 3:
				if(limit > 1) break;
				(__int128)var_8 = *(__int128 *)(var_10);
				break;
			default:
				puts("Invalid");
				break;
		}
	}

	return 0;
}
