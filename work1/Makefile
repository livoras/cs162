CGLAGS=-Wall -g

all: wc

clean:
	rm -f main
	rm -f wc
	rm -f map

push:
	make clean
	git add -A
	git cm -am "push from makefile"
	git push -u origin master

