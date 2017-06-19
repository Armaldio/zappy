##
## Makefile for a in /home/goinau_q/rendu/cpp/cpp_nanotekspice/
##
## Made by Quentin Goinaud
## Login   <quentin.goinaud@epitech.eu>
##
## Started on  Wed Jan 25 14:44:21 2017 Quentin Goinaud
## Last update Mon Jun 19 14:56:35 2017 Martin Alais
##

CC    =    gcc

RM    =    rm -rf

NAME    =    server

SRC    =    src/main.c \
			src/Player.c \
			src/Server.c \
			src/Socket.c \
			src/basic_data.c \
			src/Parser.c \
			src/World.c \
			src/commande.c \
			src/mouvement.c

FLAGS    =    -Iinclude

CFLAGS    =    -W -Wall -Wextra

LDFLAGS    =    -L./

OBJ    =    $(SRC:.c=.o)

$(NAME)    : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $(CFLAGS) $(LDFLAGS) -c $^ -o $@

install_bats:
	-git clone https://github.com/sstephenson/bats.git && cd bats && pwd && ./install.sh ../ut

tests: install_bats
	./ut/bin/bats unit-tests/dummy.sh

re: fclean all

.PHONY: all clean fclean re
