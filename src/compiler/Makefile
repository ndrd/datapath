SRC=codegen.cpp instr.cpp parser.cpp procentry.cpp strentry.cpp token.cpp
MAIN=main.cpp
LEXER=lexer.cpp
INCLUDE=codegen.h instr.h parser.h procentry.h strentry.h token.h
LEX=scanner.flex
LIBS=-ll
BIN=sasm
TESTDIR=../test
TESTS=*.s
CFLAGS=-g

compile: lexer ${MAIN} ${SRC} ${INCLUDE}
	g++ ${CFLAGS} -o ${BIN} ${SRC} ${LEXER} ${LIBS} 

lexer: ${LEX}
	flex -o ${LEXER} ${LEX}

.PHONY : clean

clean:
	rm -rf *~ *.o ${BIN} ${LEXER}

test: compile
	${foreach dir,${TESTS}, ./${BIN} < ${TESTDIR}/${dir} ;}
