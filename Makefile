##
## Makefile for a in /home/goinau_q/rendu/cpp/cpp_nanotekspice/
##
## Made by Quentin Goinaud
## Login   <quentin.goinaud@epitech.eu>
##
## Started on  Wed Jan 25 14:44:21 2017 Quentin Goinaud
## Last update Mon Jun 19 18:51:18 2017 Martin Alais
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
			src/mouvement.c \
			src/mouvement2.c \
			src/take_object.c \
			src/incantation.c \
			src/Team_gestion.c

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
	@echo "[Installing testing tool...]"
	-@git clone https://github.com/sstephenson/bats.git && cd bats && pwd && ./install.sh ../ut

tests: install_bats
	@echo -e "\n\n[Running tests...]"
	@./ut/bin/bats unit-tests/dummy.sh
	@echo -e "\n\n[Running moulinette...]"
	@./unit-tests/style.sh

re: fclean all

.PHONY: all clean fclean re
