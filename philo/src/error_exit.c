/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:01:08 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/10/06 22:15:05 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_table(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philosophers[i].structlock);
		++i;
	}
	free(table->philosophers);
	free(table->forks);
	pthread_mutex_destroy(&table->structlock);
	pthread_mutex_destroy(&table->write_stdout);
}

void	error_exit(const int custom_errno, const char *err_message)
{
	if (custom_errno)
		errno = custom_errno;
	if (errno || err_message)
		printf("philo: %s: %s\n", strerror(errno), err_message);
	exit(errno);
}
