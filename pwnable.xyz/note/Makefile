CFLAGS = -Wall

.PHONY: remote local

remote: exploit.c
	gcc ./exploit.c $(CFLAGS) -DEXPLOIT_REMOTE -o ./exploit -lexdev

local: ./exploit.c
	gcc ./exploit.c $(CFLAGS) -DEXPLOIT_LOCAL -o ./exploit -lexdev