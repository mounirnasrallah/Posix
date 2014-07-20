CC=gcc
BIN=bin
OBJ=obj
SRC=src
INC=includes

all: directories exo1 exo3 fork-exec exo5 spy

directories: ${OBJ} ${BIN}

${OBJ}:
	mkdir ${OBJ}
${BIN}:
	mkdir ${BIN}

${OBJ}/spy.o: ${SRC}/spy.c
	${CC} -c -o ${OBJ}/spy.o ${SRC}/spy.c

${OBJ}/exo5.o: ${SRC}/exo5.c
	${CC} -c -o ${OBJ}/exo5.o ${SRC}/exo5.c

${OBJ}/exo1.o: ${SRC}/exo1.c
	${CC} -c -o ${OBJ}/exo1.o ${SRC}/exo1.c

${OBJ}/exo3.o: ${SRC}/exo3.c
	${CC} -c -o ${OBJ}/exo3.o ${SRC}/exo3.c -I${INC}

${OBJ}/fork-exec.o: ${SRC}/fork-exec.c
	${CC} -c -o ${OBJ}/fork-exec.o ${SRC}/fork-exec.c -I${INC}

${BIN}/spy: ${OBJ}/spy.o
	${CC} -o ${BIN}/spy ${OBJ}/spy.o

${BIN}/exo3: ${OBJ}/exo3.o 
	${CC} -o ${BIN}/exo3 ${OBJ}/exo3.o

${BIN}/exo1: ${OBJ}/exo1.o 
	${CC} -o ${BIN}/exo1 ${OBJ}/exo1.o

${BIN}/exo5: ${OBJ}/exo5.o
	${CC} -o ${BIN}/exo5 ${OBJ}/exo5.o

${BIN}/fork-exec: ${OBJ}/fork-exec
	${CC} -o ${BIN}/fork-exec ${OBJ}/fork-exec.o

spy: ${BIN}/spy

exo5: ${BIN}/exo5

exo1: ${BIN}/exo1

exo3: ${BIN}/exo3

fork-exec: ${BIN}/fork-exec

clean:
	rm -f ${OBJ}/* ${BIN}/*

cleanall:
	rm -rf ${OBJ} ${BIN}
	rm -f ${INC}/*~ ${SRC}/*~ *~

