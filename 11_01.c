/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:44:34 by saleshin          #+#    #+#             */
/*   Updated: 2025/01/11 20:09:48 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	err (char *str)
{
	while (*str)
	{
		write (2, str, 1);
		str++;
	}
}

int	cd (char **argv, int argc)
{
	char *pwd;
	if (argc != 3)
		return err ("bad args\n"), 1;
	if (chdir (argv[2]) == -1)
		return err ("fail chdir to "), err (argv[2]), err ("\n"), 1;
	pwd = getcwd(NULL, 0);
	err (pwd);
	return 0;
}

int	main (int argc, char** argv, char** env)
{
	(void)argc;
	(void)env;
	cd (argv, argc);
	return (0);
}

