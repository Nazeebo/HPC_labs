all: exe lib

exe: main.c vector.h lib
	gcc main.c -fPIC -L. -l-vector -o vector

lib: vector.c vector.h
	gcc -shared vector.c -fPIC -o lib-vector.so

clean: 
	rm -rf vector lib-vector.so 2>/dev/null
