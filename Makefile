NAME	= philo
# CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./src
SRC		=	$(SRCDIR)/main.c \
			$(SRCDIR)/init.c \
			$(SRCDIR)/parse.c \
			$(SRCDIR)/utils.c \

OBJS	= ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
