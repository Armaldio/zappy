##
## Makefile for a in /home/goinau_q/rendu/cpp/cpp_nanotekspice/
##
## Made by Quentin Goinaud
## Login   <quentin.goinaud@epitech.eu>
##
## Started on  Wed Jan 25 14:44:21 2017 Quentin Goinaud
## Last update Thu Jun 22 14:01:24 2017 Quentin Goinaud
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
			src/take_object.c \
			src/incantation.c \
			src/Team_gestion.c \
			src/commande2.c \
			src/commande3.c \
			src/server2.c \
			src/Parser2.c \
			src/take_object2.c \
			src/action.c \
			src/waiting_line.c \
			src/command_look.c \
			src/player_list.c \
			src/player_life.c \
			src/init_world2.c \
			src/commande_look2.c \
			src/update_function.c \
			src/incantation2.c \
			src/incantation3.c \
			src/incantation4.c \
			src/incantation5.c \
			src/command_end_gestion.c \
			src/set_object.c \
			src/set_object2.c \
			src/parser_commande.c \
			src/command_broadcast.c \

FLAGS    =    -Iinclude

CFLAGS    =    -W -Wall -Wextra

LDFLAGS    =    -L./

OBJ    =    $(SRC:.c=.o)

$(NAME)    : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

all: $(NAME) hooks

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

hooks:
	cp unit-tests/pre-push.sh .git/hooks/pre-push
	chmod +x .git/hooks/pre-push

tests: install_bats
	-./unit-tests/run-server.sh
	@echo -e "\n\n[Running tests...]"
	-@./ut/bin/bats unit-tests/connect.sh
	@pkill server
	@$(RM) log
	@echo -e "\n\n[Running moulinette...]"
	@./unit-tests/style.sh

re: fclean all

.PHONY: all clean fclean re
