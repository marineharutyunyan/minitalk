CLIENT	=	client
SERVER	=	server

SRC_C	=	client.c
SRC_S	=	server.c
OBJ_S	=	server.o
OBJ_C	=	client.o


CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) 
	$(CC) $(CFLAGS) -o $@ $(OBJ_S)
	
$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) -o $@ $(OBJ_C)
	
clean:	
	$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re