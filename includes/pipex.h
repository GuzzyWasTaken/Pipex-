#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_pepe
{
	int		fdin;
	int		fdout;
	char	**paths;
	int		pair[2];
	int		fd[2];
	pid_t	pid;

}		t_pepe;

# define STDOUT 1
# define STDIN 0

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int	ft_fillstruct(char **envp, t_pepe *powa);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_calloc(size_t count, size_t size);



#endif