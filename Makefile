# SRC=codegen.cpp instr.cpp parser.cpp procentry.cpp strentry.cpp token.cpp
# MAIN=main.cpp
# LEXER=lexer.cpp
INCLUDE=src/vm/archivos/archivos.h 
# LEX=scanner.flex
# LIBS=-ll
# TESTDIR=../test
# TESTS=*.s

# compile: lexer ${MAIN} ${SRC} ${INCLUDE}
# 	g++ ${CFLAGS} -o ${BIN} ${SRC} ${LEXER} ${LIBS} 

# lexer: ${LEX}
# 	flex -o ${LEXER} ${LEX}

# .PHONY : clean

# clean:
# 	rm -rf *~ *.o ${BIN} ${LEXER}

# test: compile
# 	${foreach dir,${TESTS}, ./${BIN} < ${TESTDIR}/${dir} ;}
SRC=src/main.c
MAIN=main.c
BIN=myvm
CFLAGS=-g
SUBDIRECTORIES= src/compiler src/vm


compile: 
	gcc  -o ${BIN} ${SRC} 

clean:
	rm -rf *~ *.o ${BIN}

