all: compile
	

debug:
	flex reglas.l
	g++ -ll -g -o  conjuntos main.cpp conjuntos.cpp


compile:
	flex reglas.l
	g++ -ll -o -d conjuntos main.cpp conjuntos.cpp
    
run: all
	./conjuntos
	
debugrun:debug
	./conjuntos

clean:
	$(RM) conjuntos
	$(RM) lex.yy.c