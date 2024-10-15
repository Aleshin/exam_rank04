/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:37:44 by saleshin          #+#    #+#             */
/*   Updated: 2024/10/15 23:49:57 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv, char **env)
{
	int	i;
	
	(void)env;
	i = 1;
	while (i < argc)
	{
		if (!strcmp(argv[i], "|"))
			printf("\n");
		else
			printf("%s ", argv[i]);
		i++;
	}
	return (0);
}
