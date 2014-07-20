CC=gcc
BIN=bin
OBJ=obj
SRC=src
INC=includes


all: directories filefusion findword list-rep redirection setfilestats

directories: ${OBJ} ${BIN}

${OBJ}:
	mkdir ${OBJ}

${BIN}:
	mkdir ${BIN}

${OBJ}/filefusion.o: ${SRC}/filefusion.c 
	${CC} -c -o $@ $<

${OBJ}/findword.o: ${SRC}/findword.c
	${CC} -c -o $@ $<

${OBJ}/list-rep.o: ${SRC}/list-rep.c
	${CC} -c -o $@ $<

${OBJ}/redirection.o: ${SRC}/redirection.c
	${CC} -c -o $@ $<

${OBJ}/setfilestats.o: ${SRC}/setfilestats.c
	${CC} -c -o $@ $<

${BIN}/setfilestats: ${OBJ}/setfilestats.o 
	${CC} -o $@ $<

${BIN}/filefusion: ${OBJ}/filefusion.o 
	${CC} -o $@ $<

${BIN}/findword: ${OBJ}/findword.o
	${CC} -o $@ $<

${BIN}/list-rep: ${OBJ}/list-rep.o
	${CC} -o $@ $<

${BIN}/redirection: ${OBJ}/redirection.o
	${CC} -o $@ $<

filefusion: ${BIN}/filefusion

findword: ${BIN}/findword

list-rep: ${BIN}/list-rep

redirection: ${BIN}/redirection

setfilestats: ${BIN}/setfilestats

clean:
	rm -f ${OBJ}/* ${BIN}/*

cleanall:
	rm -rf ${OBJ} ${BIN}
	rm -f ${INC}/*~ ${SRC}/*~ *~

