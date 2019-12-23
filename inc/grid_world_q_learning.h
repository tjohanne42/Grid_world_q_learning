#ifndef GRID_WORLD_Q_LEARNING_H
 #define GRID_WORLD_Q_LEARNING_H

#include "ft_printf.h"
#include <time.h>

#define TRUE 1
#define FALSE 0

_Bool		start_game(int *reward, double **Q, double eps, _Bool train, _Bool show);

#endif