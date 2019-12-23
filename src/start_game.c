#include "grid_world_q_learning.h"

static size_t		take_action(size_t s, double **Q, double eps)
{
	size_t	i;
	double	vmax;
	size_t	vi;

	i = 0;
	vmax = 0.00;
	vi = 0;
	if (eps > rand() % 10000 / 10000.00)
		return (rand() % 4);
	while (i < 4)
	{
		if (i == 0 || Q[s][i] > vmax)
		{
			vmax = Q[s][i];
			vi = i;
		}
		else if (i != 0 && Q[s][i] == vmax)
		{
			if (rand() % 2 == 0)
				vi = i;
		}
		i++;
	}
	return (vi);
}

static size_t		step(size_t s, size_t a)
{
	if (a == 0)
	{
		if (s > 2)
			return (s - 3);
		else
			return (s);
	}
	else if (a == 1)
	{
		if (s == 0 || s == 3 || s == 6)
			return (s);
		else
			return (s - 1);
	}
	else if (a == 2)
	{
		if (s > 5)
			return (s);
		else
			return (s + 3);
	}
	if (s == 2 || s == 5 || s == 8)
		return (s);
	else
		return (s + 1);
}

static void		display(int *reward, size_t s)
{
	size_t		i;

	i = 0;
	while (i < 9)
	{
		ft_printf("\t");
		if (s != i && reward[i] != 2)
			ft_printf("%d", reward[i]);
		else if (s == i)
			ft_printf("%d", 2);
		else if (reward[i] == 2)
			ft_printf("0");
		if ((i + 1) % 3 == 0 && i != 0)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n----------------------------------------\n\n");
}

_Bool		start_game(int *reward, double **Q, double eps, _Bool train, _Bool show)
{
	_Bool	EXIT_VALUE;
	_Bool	clean;
	size_t	s;
	size_t	ns;
	size_t	a;
	size_t	na;
	int		r;

	s = 0;
	while (reward[s] != 2)
		s++;
	clean = TRUE;
	EXIT_VALUE = FALSE;
	while (!EXIT_VALUE)
	{
		if (show == TRUE)
			display(reward, s);
		a = take_action(s, Q, eps);
		ns = step(s, a);
		if (reward[ns] == 2)
			r = 0;
		else
			r = reward[ns];
		na = take_action(ns, Q, 0.00);
		if (train == TRUE && ns != s)
		{
			if (r == 1)
				Q[s][a] = Q[s][a] + 0.1 * (1.00 + 0.90 * Q[ns][na] - Q[s][a]);
			else if (r == -1)
				Q[s][a] = Q[s][a] - 0.1 * (1.00 + 0.90 * Q[ns][na] - Q[s][a]);
			else
				Q[s][a] = Q[s][a] + 0.1 * (0.90 * Q[ns][na] - Q[s][a]);
		}
		s = ns;
		if (reward[s] == 1)
			EXIT_VALUE = TRUE;
		else if (reward[s] == -1)
			clean = FALSE;
	}
	if (show == TRUE)
		display(reward, s);
	if (reward[s] == 1 && clean == TRUE)
		return (TRUE);
	return (FALSE);
}
