CC=gcc
CGLAGS=-Wall -g

all:
	$(CC) ./wc.c $(CGLAGS) -o wc

clean:
	rm -f main
	rm -f wc
	rm -f map

push:
	make clean
	git add -A
	git cm -am "push from makefile"
	git push -u origin master

