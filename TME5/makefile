CC=gcc
BIN=bin
OBJ=obj
SRC=src
INC=includes


all: directories mywait mysleep sync

directories: ${OBJ} ${BIN}

${OBJ}:
	mkdir ${OBJ}

${BIN}:
	mkdir ${BIN}

${OBJ}/mywait.o: ${SRC}/mywait.c 
	${CC} -c -o $@ $<

${OBJ}/mysleep.o: ${SRC}/mysleep.c
	${CC} -c -o $@ $<

${OBJ}/sync.o: ${SRC}/sync.c
	${CC} -c -o $@ $<

${BIN}/mywait: ${OBJ}/mywait.o
	${CC} -o $@ $<

${BIN}/mysleep: ${OBJ}/mysleep.o
	${CC} -o $@ $<

${BIN}/sync: ${OBJ}/sync.o
	${CC} -o $@ $<

mywait: ${BIN}/mywait

mysleep: ${BIN}/mysleep

sync: ${BIN}/sync

clean:
	rm -f ${OBJ}/* ${BIN}/*

cleanall:
	rm -rf ${OBJ} ${BIN}
	rm -f ${INC}/*~ ${SRC}/*~ *~

