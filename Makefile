ISRC=src/main.c src/memoria/memoria.c  \
<<<<<<< HEAD
  src/registros/registros.c src/errores/errores.c \
  src/alu/alu.c
=======
  src/registros/registros.c src/errores/errores.c
  src/operaciones/operaciones.c src/lector.c
>>>>>>> origin/master
MAIN=main.c
BIN=myvm
CFLAGS=-g
SUBDIRECTORIES= src/compiler src/vm


compile: 
	gcc  -o ${BIN} ${SRC} 

clean:
	rm -rf *~ *.o ${BIN}

