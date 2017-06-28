##
## Makefile for a in /home/goinau_q/rendu/cpp/cpp_nanotekspice/
##
## Made by Quentin Goinaud
## Login   <quentin.goinaud@epitech.eu>
##
## Started on  Wed Jan 25 14:44:21 2017 Quentin Goinaud
## Last update Wed Jun 28 21:35:35 2017 Martin Alais
##

CC    =    gcc -g

RM    =    rm -rf

NAME    =    server

SRC    =	src/commande/broadcast.c \
			src/commande/eject.c \
			src/commande/exit.c \
			src/commande/fork.c \
			src/commande/forward.c \
			src/commande/generic_level.c \
			src/commande/incantation.c \
			src/commande/inventory.c \
			src/commande/level1.c \
			src/commande/level2.c \
			src/commande/level2_end.c \
			src/commande/level3.c \
			src/commande/level3_end.c \
			src/commande/level4.c \
			src/commande/level4_end.c \
			src/commande/level4_end2.c \
			src/commande/level5.c \
			src/commande/level5_end.c \
			src/commande/level6.c \
			src/commande/level6_end.c \
			src/commande/level6_end2.c \
			src/commande/level7.c \
			src/commande/level7_end.c \
			src/commande/look.c \
			src/commande/look2.c \
			src/commande/right_left.c \
			src/commande/set.c \
			src/commande/set2.c \
			src/commande/take.c \
			src/commande/take2.c \
			src/commande/update_player_status.c \
			src/event/eggs.c \
			src/event/event2.c \
			src/event/event3.c \
			src/event/end_incantation.c \
			src/event/player_connection.c \
			src/game/action.c \
			src/game/basic_data.c \
			src/game/egg2.c \
			src/game/Eggs.c \
			src/game/end_game.c \
			src/game/graphic.c \
			src/game/init_world2.c \
			src/game/main.c \
			src/game/manage_answer.c \
			src/game/parser_commande.c \
			src/game/Parser.c \
			src/game/Parser2.c \
			src/game/player_life.c \
			src/game/player_list.c \
			src/game/Player.c \
			src/game/poll.c \
			src/game/poll2.c \
			src/game/send_message.c \
			src/game/Server.c \
			src/game/server2.c \
			src/game/Socket.c \
			src/game/undefine.c \
			src/game/update_function.c \
			src/game/waiting_line.c \
			src/game/World.c \
			src/graphic/bct_pnw.c \
			src/graphic/commande_graphic.c \
			src/graphic/msz_sgt.c \
			src/graphic/parser.c \
			src/graphic/ppo_plv_pin.c \
			src/graphic/smg.c \
			src/graphic/sst_update_time.c \
			src/graphic/tna.c \
			src/team/Team_gestion.c \
			src/team/team_status.c \

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
	-@cp unit-tests/pre-push.sh .git/hooks/pre-push
	-@chmod +x .git/hooks/pre-push

tests: install_bats
	#-./unit-tests/run-server.sh
	@echo -e "\n\n[Running tests...]"
	-@./ut/bin/bats unit-tests/connect.sh
	#@pkill server
	@$(RM) log
	@echo -e "\n\n[Running moulinette...]"
	@./unit-tests/style.sh

re: fclean all

.PHONY: all clean fclean re
