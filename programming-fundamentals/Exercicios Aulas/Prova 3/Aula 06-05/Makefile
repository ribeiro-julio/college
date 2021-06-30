main: main.o
	@echo "Compilando..."
	gcc *.o -o program

main.o: main.c
	gcc -c *.c
	
clean:
	rm -f *.o

run:
	./program
