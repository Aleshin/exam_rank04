/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:37:44 by saleshin          #+#    #+#             */
/*   Updated: 2024/10/24 21:23:16 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	pipes(char **argv, char **env)
{
	pid_t	proc_id;

	proc_id = fork();
	if (proc_id == 0)
	{
		printf("execve %d\n", execve(*argv, argv, env));
		exit (0);
	}
	else if (proc_id > 0)
	{
		waitpid(proc_id, NULL, 0);
		return (0);
	}
	else
	{
		printf ("error creating process\n");
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	
	(void)argc;
	i = 1;
	argv++;
	while (argv[i])
	{
		if (!strcmp(argv[i], "|"))
		{
			argv[i] = 0;
			pipes(argv, env);
			argv += i + 1;
			i = 0;
		}
		i++;
	}
	if (i > 0)
		pipes (argv, env);
	return (0);
}
