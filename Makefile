NAME_S = server
NAME_C = client

CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c


OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	gcc $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	gcc $(CFLAGS) $(OBJS_C) -o ${NAME_C}


clean:
	rm -rf  $(OBJS_S) $(OBJS_C) 

fclean: clean
	rm -rf $(NAME_S) $(NAME_C)

re: fclean all


.PHONY: all clean fclean re