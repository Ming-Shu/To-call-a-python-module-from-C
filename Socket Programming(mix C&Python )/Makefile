CC= gcc
CFLAGS = -std=gnu99 -I${DIR_INC} 
DIR_LIB = -L /usr/include/python2.7
DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

EXEC = start
BIN_TARGET = ${DIR_BIN}/${EXEC}

SRC = $(wildcard ${DIR_SRC}/*.c) 
DIR = $(notdir ${SRC})
OBJ = $(DIR:%.c=${DIR_OBJ}/%.o) 

#all: $(EXEC)
#$(EXEC): $(OBJ)
${BIN_TARGET}:$(OBJ)                           
	$(CC) $^ ${DIR_LIB} -lpython2.7 -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {}
