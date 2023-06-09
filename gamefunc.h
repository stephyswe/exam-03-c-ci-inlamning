// gamefunc.h

#ifndef GAME_FUNC_H
#define GAME_FUNC_H

#include "game.h"

enum Choice parse_choice(const char *str);

enum Game_Status determine_winner(enum Choice user, enum Choice computer);

char *convertResult(int result);

void read_file(int *num_wins, int *num_games);

void print_score(int result);

void update_statistics(enum Game_Status result, int *num_wins, int *num_games,
                       double *avg_wins);

#endif