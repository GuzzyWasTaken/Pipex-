/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 02:01:22 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/10/26 21:03:48 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <string.h>

char	*find_command(t_pepe *pipex, char *argv)
{
	int		i;
	char	*ret_str;
	char	*tmp;

	
	i = 0;
	write(2, "in fc: ", 7);
	write(2, argv, ft_strlen(argv));
	write(2, "\n", 1);
	if (access(argv, X_OK) == 0)
		return(argv);
	while (pipex->paths && pipex->paths[i])
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		ret_str = ft_strjoin(tmp, argv);
		if (access(ret_str, X_OK) == 0)
			return (ret_str);
		free (ret_str);
		i++;
	}
	perror("invalid arguement"); //command not found
	exit (127);
	// return("/bin/cat");
}

void	first_child(t_pepe pipex, char *command, char *envp[])
{
	char	*cmd;
	char	**why;

	pipex.pid = fork ();
	if (pipex.pid == 0)
	{
		close (pipex.fd[0]);
		dup2 (pipex.fdin, STDIN);
		dup2(pipex.fd[1], STDOUT);
		why = ft_split(command, ' ');
		cmd = find_command(&pipex, why[0]);
		execve(cmd, why, envp);
	}
	else
	{
		close (pipex.fd[1]);
		dup2 (pipex.fd[0], STDIN);
		dup2 (pipex.fd[1], STDOUT);
	}
}

void	last_child(t_pepe pipex, char *command, char *envp[])
{
	char	*cmd;
	char	**why;

	dup2 (pipex.fdout, pipex.fd[1]);
	close (1);
	dup2(pipex.fd[1], STDOUT);
	why = ft_split(command, ' ');
	write(2, why[0], ft_strlen(why[0]));
	write(2, "\n", 1);
	cmd = find_command(&pipex, why[0]);
	execve(cmd, why, envp);
}

int	ft_fillstruct(char **envp, t_pepe *pipex)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i])
		pipex->paths = ft_split (envp[i] + 5, ':');
	if (pipe(pipex->pair) == -1)
		return (0);
	pipex->fd[0] = pipex->pair[0];
	pipex->fd[1] = pipex->pair[1];
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pepe	pipex;
	
	if (argc != 5)
	{
		write(2, "Invalid amount of arguments\n", 28);
		exit(1);
	}
	pipex.fdout = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.fdout < 0)
	{
		perror ("Outfile");
		exit (1);
	}
	pipex.fdin = open(argv[1], O_RDONLY);
	if (pipex.fdin < 0)
	{
		perror ("Infile");
		exit (1);
	}
	if (ft_fillstruct(envp, &pipex) == 0)
		return (0);
	first_child(pipex, argv[2], envp);
	last_child(pipex, argv[3], envp);
	return(0);
}
