#include "pipex.h"

static int	full_space(char *argv)
{
	int	len;
	int check;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	check = 0;
	while (argv[i])
	{
		if (argv[i] == 32)
			check++;
		i++;
	}
	if (len == check)
		return (0);
	return (1);
}

static void	check_empty(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i <= (argc - 1))
	{
		if (!full_space(argv[i]))
		{
			ft_printf("argument vide!");
			exit(0);
		}	
		i++;
	}
}

static void	valid_fd(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("fd invalide!");
		exit(0);
	}
	close(fd);
}

void	check_arg(int argc, char **argv, char **envp)
{
	int	i;

	i = 2;
	check_empty(argc, argv);
	valid_fd(argv);
	while (i < argc - 2)
	{
		if(find_path(argv[i], envp) == NULL)
		{
			ft_printf("path non valide!");
			exit(0);
		}	
		i++;
	}
}
