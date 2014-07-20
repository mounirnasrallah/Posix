CC=gcc
BIN=bin
OBJ=obj
SRC=src
INC=includes


all: directories accountant voodoo pending-signals pending-signals-2 pending-signals-3 spy

directories: ${OBJ} ${BIN}

${OBJ}:
	mkdir ${OBJ}
	mkdir ${OBJ}/init-sigs
${BIN}:
	mkdir ${BIN}

${OBJ}/spy.o: ${SRC}/spy.c
	${CC} -c -o $@ $<

${OBJ}/accountant.o: ${SRC}/accountant.c 
	${CC} -c -o ${OBJ}/accountant.o ${SRC}/accountant.c

${OBJ}/init-sigs/init-sig.2.o: ${SRC}/init-sigs/init-sig.2.c
	${CC} -c -o ${OBJ}/init-sigs/init-sig.2.o ${SRC}/init-sigs/init-sig.2.c

${OBJ}/init-sigs/init-sig.3.o: ${SRC}/init-sigs/init-sig.3.c
	${CC} -c -o ${OBJ}/init-sigs/init-sig.3.o ${SRC}/init-sigs/init-sig.3.c

${OBJ}/init-sigs/init-sig.4.o: ${SRC}/init-sigs/init-sig.4.c
	${CC} -c -o ${OBJ}/init-sigs/init-sig.4.o ${SRC}/init-sigs/init-sig.4.c

${OBJ}/init-sigs/init-sig.5.o: ${SRC}/init-sigs/init-sig.5.c
	${CC} -c -o ${OBJ}/init-sigs/init-sig.5.o ${SRC}/init-sigs/init-sig.5.c

${OBJ}/voodoo.o: ${SRC}/voodoo.c
	${CC} -c -o ${OBJ}/voodoo.o ${SRC}/voodoo.c

${OBJ}/pending-signals.o: ${SRC}/pending-signals.c
	${CC} -c -o ${OBJ}/pending-signals.o ${SRC}/pending-signals.c

${OBJ}/pending-signals-3.o: ${SRC}/pending-signals-3.c
	${CC} -c -o ${OBJ}/pending-signals-3.o ${SRC}/pending-signals-3.c

${OBJ}/pending-signals-2.o: ${SRC}/pending-signals-2.c
	${CC} -c -o ${OBJ}/pending-signals-2.o ${SRC}/pending-signals-2.c

${BIN}/accountant: ${OBJ}/accountant.o 
	${CC} -o $@ $<

${BIN}/spy: ${OBJ}/spy.o
	${CC} -o $@ $<

${BIN}/init-sig2: ${OBJ}/init-sigs/init-sig.2.o 
	${CC} -o $@ $<

${BIN}/init-sig3: ${OBJ}/init-sigs/init-sig.3.o 
	${CC} -o $@ $<

${BIN}/init-sig4: ${OBJ}/init-sigs/init-sig.4.o 
	${CC} -o $@ $<

${BIN}/init-sig5: ${OBJ}/init-sigs/init-sig.5.o 
	${CC} -o $@ $<

${BIN}/pending-signals: ${OBJ}/pending-signals.o 
	${CC} -o ${BIN}/pending-signals ${OBJ}/pending-signals.o

${BIN}/pending-signals-2: ${OBJ}/pending-signals-2.o
	${CC} -o ${BIN}/pending-signals-2 ${OBJ}/pending-signals-2.o

${BIN}/pending-signals-3: ${OBJ}/pending-signals-3.o
	${CC} -o ${BIN}/pending-signals-3 ${OBJ}/pending-signals-3.o

${BIN}/voodoo: ${OBJ}/voodoo.o
	${CC} -o ${BIN}/voodoo ${OBJ}/voodoo.o

accountant: ${BIN}/accountant

init-sig2: ${BIN}/init-sig2

init-sig3: ${BIN}/init-sig3

init-sig4: ${BIN}/init-sig4

init-sig5: ${BIN}/init-sig5

voodoo: ${BIN}/voodoo

spy: ${BIN}/spy

pending-signals: ${BIN}/pending-signals

pending-signals-2: ${BIN}/pending-signals-2

pending-signals-3: ${BIN}/pending-signals-3

fork-exec: ${BIN}/fork-exec

clean:
	rm -f ${OBJ}/* ${BIN}/*

cleanall:
	rm -rf ${OBJ} ${BIN}
	rm -f ${INC}/*~ ${SRC}/*~ *~

