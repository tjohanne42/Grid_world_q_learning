#include "grid_world_q_learning.h"

static double	**init_q_base(void)
{
	double	**Q;
	size_t	i;
	size_t	z;

	if (!(Q = malloc(sizeof(*Q) * 9)))
		return (NULL);
	i = 0;
	while (i < 9)
	{
		if (!(Q[i] = malloc(sizeof(**Q) * 4)))
			return (NULL);
		z = 0;
		while (z < 4)
		{
			Q[i][z] = 0.00;
			z++;
		}
		i++;
	}
	return (Q);
}

int		main(void)
{
	int		reward[] = {0, 0, 1, 2, -1, 0, 0, 0, 0};
	double	**Q;
	double	eps;
	size_t	i;
	size_t	win;
	size_t	lose;
	char	*str;
	char	c;

	srand(time(NULL));
	if (!(Q = init_q_base()))
		return (0);
	eps = 0.9999;
	i = 0;
	while (i < 10000)
	{
		ft_printf("eps : %f\n", eps);
		start_game(reward, Q, eps, TRUE, FALSE);
		if (i != 0 && i % 10 == 0)
			eps = eps * 0.998;
		if (eps < 0.10)
			eps = 0.10;
		i++;
	}
	sleep(1);
	i = 0;
	while (i < 9)
	{
		ft_printf("Q[%d] = %f, %f, %f, %f\n", i, Q[i][0], Q[i][1], Q[i][2], Q[i][3]);
		i++;
	}
	sleep(1);
	win = 0;
	lose = 0;
	i = 0;
	while (i < 1000)
	{
		if (start_game(reward, Q, 0.00, FALSE, FALSE) == TRUE)
			win++;
		else
			lose++;
		i++;
	}
	_Bool	EXIT_VALUE;

	str = NULL;
	EXIT_VALUE = FALSE;
	ft_printf("blbl\n");
	while (!EXIT_VALUE)
	{
		system("cls");
		system("clear");
		ft_printf("Winrate : %f%%\n", (double)win / ((double)win + (double)lose) * 100);
		ft_printf("Enter 'x' to exit\n");
		if (start_game(reward, Q, 0.00, FALSE, TRUE) == TRUE)
			ft_printf("Success\n");
		else
			ft_printf("Derp\n");
		if (!(str = malloc(sizeof(*str) * 1001)))
			return (0);
		fgets(str, 1000, stdin);
		if (!str)
			return(0);
		c = str[0];
		free(str);
		str = NULL;
		if (c == 'x')
			EXIT_VALUE = TRUE;
	}
	i = 0;
	while (i < 9)
	{
		free(Q[i]);
		i++;
	}
	free(Q);
	return (0);
}
