/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:57 by dboire            #+#    #+#             */
/*   Updated: 2024/05/14 15:06:41 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_prog(t_prog *prog, t_philo *philos)
{
	prog->is_dead = 0;
	prog->philos = philos;
	pthread_mutex_init(&prog->write, NULL);
	pthread_mutex_init(&prog->time, NULL);
	pthread_mutex_init(&prog->ate, NULL);
	pthread_mutex_init(&prog->dead, NULL);
	pthread_mutex_init(&prog->ate_in_time, NULL);
	pthread_mutex_init(&prog->he_dead, NULL);
	pthread_mutex_init(&prog->last_meal_check, NULL);
}

void	ft_init_struct(t_prog *prog, t_philo *philos, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].philo_nb = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philos[i].meals = ft_atoi(av[5]);
		else
			philos[i].meals = -1;
		philos[i].start_time = get_current_time();
		i++;
	}
	ft_init_struct_2(prog, philos, av);
}

void	ft_init_struct_2(t_prog *prog, t_philo *philos, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].last_meal = get_current_time() - philos[i].start_time;
		philos[i].meals_eaten = 0;
		philos[i].is_dead = &prog->is_dead;
		philos[i].ate = &prog->ate;
		philos[i].dead = &prog->dead;
		philos[i].he_dead = &prog->he_dead;
		philos[i].ate_in_time = &prog->ate_in_time;
		philos[i].time = &prog->time;
		philos[i].write = &prog->write;
		philos[i].last_meal_check = &prog->last_meal_check;
		prog->philos[i].r_fork = &prog->philos[(i + 1) % ft_atoi(av[1])].l_fork;
		i++;
	}
}
