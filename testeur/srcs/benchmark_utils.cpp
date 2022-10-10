/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:14:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/10/10 20:23:36 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <stddef.h>
# include <iostream>
# include <string>

long long int	give_utime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((size_t)time.tv_sec * 1000 + (size_t)time.tv_usec / 1000);
}

void	print_time(std::string cont, long long int start)
{
	std::cerr << cont << " time : " << give_utime() - start << std::endl;
}
