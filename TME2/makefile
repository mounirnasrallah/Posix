CC=gcc
BIN=bin
OBJ=obj
SRC=src
INC=includes

all: directories exo1 single_converter decoder

directories: ${OBJ} ${BIN}

${OBJ}:
	mkdir ${OBJ}
${BIN}:
	mkdir ${BIN}

${OBJ}/exo1.o: ${SRC}/exo1.c
	${CC} -c -o ${OBJ}/exo1.o ${SRC}/exo1.c

${OBJ}/single_converter.o: ${SRC}/single_converter.c
	${CC} -c -o ${OBJ}/single_converter.o ${SRC}/single_converter.c -I${INC}

${OBJ}/converters.o: ${SRC}/converters.c
	${CC} -c -o ${OBJ}/converters.o ${SRC}/converters.c -I${INC}

${OBJ}/decoder.o: ${SRC}/decoder.c
	${CC} -c -o ${OBJ}/decoder.o ${SRC}/decoder.c -I${INC}

${BIN}/decoder: ${OBJ}/decoder.o 
	${CC} -o ${BIN}/decoder ${OBJ}/decoder.o

${BIN}/exo1: ${OBJ}/exo1.o 
	${CC} -o ${BIN}/exo1 ${OBJ}/exo1.o

${BIN}/single_converter: ${OBJ}/single_converter.o ${OBJ}/converters.o
	${CC} -o ${BIN}/single_converter ${OBJ}/single_converter.o ${OBJ}/converters.o

exo1: ${BIN}/exo1

single_converter: ${BIN}/single_converter

decoder: ${BIN}/decoder

clean:
	rm -f ${OBJ}/* ${BIN}/*

cleanall:
	rm -rf ${OBJ} ${BIN}
	rm -f ${INC}/*~ ${SRC}/*~ *~

