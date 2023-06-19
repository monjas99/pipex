
#include "pipex.h"

char	*ft_cmd(t_pipex pipex)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	tmp = ft_strjoin("/", pipex.cmd[0]);
	while (pipex.envp[i])
	{
		path = ft_strjoin(pipex.envp[i], tmp);
		if (access(path, F_OK) == 0)
		{
			free(tmp);
			return (path);
		}
		free(path);
		i++;
	}
	return (0);
}

void	ft_command(t_pipex pipex, char **av, char **envp)
{
	pipex.pid_1 = fork();
	if (pipex.pid_1 == 0)
	{
		close(pipex.pipefd[0]);
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		dup2(pipex.infile, STDIN_FILENO);
		pipex.cmd = ft_split(av[2], ' ');
		pipex.path = ft_cmd(pipex);
		if (!pipex.path)
		{
			ft_str_error("command not found: ", pipex.cmd[0]);
			ft_free_child(pipex.path, pipex.cmd);
			exit (1);
		}
		execve(pipex.path, pipex.cmd, envp);
	}
}

void	ft_command2(t_pipex pipex, char **av, char **envp)
{
	pipex.pid_2 = fork();
	if (pipex.pid_2 == 0)
	{
		close(pipex.pipefd[1]);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		pipex.cmd = ft_split(av[3], ' ');
		pipex.path = ft_cmd(pipex);
		if (!pipex.path)
		{
			ft_str_error("command not found: ", pipex.cmd[0]);
			ft_free_child(pipex.path, pipex.cmd);
			exit (1);
		}
		execve(pipex.path, pipex.cmd, envp);
	}
}
