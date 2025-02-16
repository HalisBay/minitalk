/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:56:28 by hbay              #+#    #+#             */
/*   Updated: 2023/09/08 10:32:49 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_argument(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= 0 && argv[i] <= 126))
		{
			write(1, "Please enter printable characters", 33);
			return (0); 
		}
		i++;
	}
	return (1);
}

int	check_pid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[0] == '+')
		{
			i++;
		}
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			write(1, "pid has non-numeric characters.", 31);
			return (0); 
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *num)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			sum = sum * 10 + (num[i] - 48);
		i++;
	}
	return (sum);
}

void	worker(int pid, char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (s[i])
	{
		j = 8;
		c = s[i];
		while (--j >= 0)
		{
			if ((c >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3 && check_pid(argv[1]) && check_argument(argv[2]))
	{
		worker(ft_atoi(argv[1]), argv[2]);
		worker(ft_atoi(argv[1]), "\n");
	}
	return (0);
}
