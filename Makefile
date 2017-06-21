##
## Makefile for a in /home/goinau_q/rendu/cpp/cpp_nanotekspice/
##
## Made by Quentin Goinaud
## Login   <quentin.goinaud@epitech.eu>
##
## Started on  Wed Jan 25 14:44:21 2017 Quentin Goinaud
## Last update Wed Jun 21 14:50:35 2017 Quentin Goinaud
##

CC    =    gcc -g

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
			src/Team_gestion.c \
			src/commande2.c \
			src/commande3.c \
			src/server2.c \
			src/Parser2.c \
			src/checker.c \
			src/take_object2.c \
			src/action.c \
			src/waiting_line.c \
			src/command_look.c \
			src/player_list.c \
			src/player_life.c \
			src/init_world2.c \
			src/commande_look2.c \

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

quick_client:
	$(CC) client/main.c -o mouli

tests: install_bats
	@#./server&
	@echo -e "\n\n[Running tests...]"
	@./ut/bin/bats unit-tests/connect.sh
	@#pkill server
	@echo -e "\n\n[Running moulinette...]"
	@./unit-tests/style.sh

re: fclean all

.PHONY: all clean fclean re
