.PHONY:clean
CC = gcc
RM = rm
OBJ = phone
OBJS = main.o menu.o fun.o
SRC = main.c menu.c fun.c

$(OBJ):$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ)