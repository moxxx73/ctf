#include <stdio.h>
#include <stdint.h>

struct{ /* 0x601480 */
	char note[32];
	char *desc;
} s; 

void setup();

void print_menu(){
	printf("Menu: \n 1. Edit note.\n 2. Edit desc.\n 0. Exit\n> ");
	return;
}

/* Stack size: 48 bytes */
int read_int32(){
	char str[32]; /* [rbp-0x20] */

	read(0, str, 32);
	return atoi(str);
}

void edit_desc(){
	if(!s.desc) s.desc = malloc(32);
	printf("desc: ");
	read(0, s.desc, 32);
	return;
}

/* Stack size: 16 bytes */
void edit_note(){
	char *ptr; /* [rbp-0x8] */
	int size;  /* [rbp-0xc] */
	
	printf("Note len? ");
	size = read_int32();
	ptr = malloc(size);

	printf("note: ");
	read(0, ptr, size);

	strncpy(s, ptr, size);
	free(ptr);
	return;
}

/* Stack size: 16 bytes */
int main(int argc, char **argv){
	uint32_t var_4; /* [rbp-0x4] */

	setup();
	puts("Note taking 101.");

	for(;;){
		print_menu();
		var_4 = read_int32();
		if(var_4 == 1) edit_note();
		else if(var_4 == 2) edit_desc();
		else if(var_4 == 0) return 0;
		else puts("Invalid");
	}
}
