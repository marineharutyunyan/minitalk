CLIENT	=	client
SERVER	=	server
CLIENT_B	=	client_bonus
SERVER_B	=	server_bonus

SRC_C	=	client.c
SRC_S	=	server.c
OBJ_S	=	server.o
OBJ_C	=	client.o

SRC_C_B	=	client_bonus.c
SRC_S_B	=	server_bonus.c
OBJ_S_B	=	server_bonus.o
OBJ_C_B	=	client_bonus.o

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

bonus: $(CLIENT_B) $(SERVER_B) 

$(SERVER_B): $(OBJ_S_B) 
	$(CC) $(CFLAGS) -o $@ $(OBJ_S_B)
	
$(CLIENT_B): $(OBJ_C_B)
	$(CC) $(CFLAGS) -o $@ $(OBJ_C_B)	

clean:	
	$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

re: fclean all bonus

.PHONY: all bouns clean fclean re