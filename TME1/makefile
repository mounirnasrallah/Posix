CC=gcc -Wall -ansi -g
BIN=bin
INC=include
LIB=lib
OBJ=obj
SRC=src
AR=ar
RANLIB=ranlib
STACK_SIZE= "-DSTACK_SIZE=3"


all: directories runstack runfifo

directories: ${OBJ} ${BIN} ${LIB}

${OBJ}:
	mkdir ${OBJ}
${BIN}:
	mkdir ${BIN}
${LIB}:
	mkdir ${LIB}

${OBJ}/stack_test.o: ${INC}/stack.h ${SRC}/stack_test.c
	${CC} -c -o ${OBJ}/stack_test.o ${SRC}/stack_test.c -I${INC} ${STACK_SIZE}

${OBJ}/stack_array.o: ${INC}/stack.h ${SRC}/stack_array.c
	${CC} -c -o ${OBJ}/stack_array.o ${SRC}/stack_array.c -I${INC} ${STACK_SIZE}

${OBJ}/stack_list.o: ${SRC}/stack_list.c ${INC}/stack.h ${INC}/list.h
	${CC} -c -o ${OBJ}/stack_list.o ${SRC}/stack_list.c -I${INC}

${OBJ}/list_impl.o: ${SRC}/list_impl.c ${INC}/list.h
	${CC} -c -o ${OBJ}/list_impl.o ${SRC}/list_impl.c -I${INC}

${OBJ}/fifo_list.o: ${SRC}/fifo_list.c ${INC}/list.h ${INC}/fifo.h
	${CC} -c -o ${OBJ}/fifo_list.o ${SRC}/fifo_list.c -I${INC}

${OBJ}/fifo_test.o: ${INC}/fifo.h ${SRC}/fifo_test.c
	${CC} -c -o ${OBJ}/fifo_test.o ${SRC}/fifo_test.c -I${INC}

# Creation de la bibliotheque exercice 2                                                 
# ${LIB}/libstack.a: ${OBJ}/stack_array.o
#	${AR} r ${LIB}/libstack.a ${OBJ}/stack_array.o


# Creation de la bibliotheque exercice 6
${LIB}/libstack.a: ${OBJ}/stack_list.o ${OBJ}/list_impl.o
	${AR} r ${LIB}/libstack.a ${OBJ}/stack_list.o ${OBJ}/list_impl.o

# Creation de la bibliotheque exercice 7
${LIB}/libfifo.a: ${OBJ}/fifo_list.o ${OBJ}/list_impl.o
	${AR} r ${LIB}/libfifo.a ${OBJ}/fifo_list.o ${OBJ}/list_impl.o

${BIN}/stack_test: ${OBJ}/stack_test.o ${LIB}/libstack.a
	${CC} -o ${BIN}/stack_test ${OBJ}/stack_test.o ${LIB}/libstack.a

${BIN}/fifo_test: ${OBJ}/fifo_test.o ${LIB}/libfifo.a
	${CC} -o ${BIN}/fifo_test ${OBJ}/fifo_test.o ${LIB}/libfifo.a

runstack: ${BIN}/stack_test
	@echo "\n____________________  STACK  _________________________\n"
	echo "Testing Stack"
	${BIN}/stack_test

runfifo: ${BIN}/fifo_test
	@echo "\n____________________  FIFO  _________________________\n"
	echo "Test Fifo"
	${BIN}/fifo_test

clean:
	rm -f ${OBJ}/* ${BIN}/* ${LIB}/*

cleanall:
	rm -rf ${OBJ} ${BIN} ${LIB}
	rm -f ${INC}/*~ ${SRC}/*~ *~

