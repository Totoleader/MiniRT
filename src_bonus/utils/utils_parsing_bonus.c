
#include "../../include/minirt_bonus.h"

bool	is_file_empty(int fd)
{
	char	*line;
	int		nb_char;
	int		i;

	nb_char = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (ft_isprint(*line) == 1)
				nb_char += 1;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	if (nb_char > 0)
		return (false);
	return (true);
}

void	check_file_extension(char *check_file)
{
	if (!check_file)
	{
		ft_putstr_fd("File is invalid\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(check_file, ".rt") != 0)
	{
		ft_putstr_fd("File has an invalid extension\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/*
Checks :
	- if the <file.rt> is valid / exist,
	- if the extension is .rt,
	- if .rt is a file and not a directory,
	- if the file can be opened.
*/
void	check_file_validity(char *file)
{
	int		fd;
	char	*check_file;

	check_file = ft_strrchr(file, '.');
	check_file_extension(check_file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File can't be opened\n", STDERR_FILENO);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (is_file_empty(fd) == true)
	{
		ft_putstr_fd("File is empty OR Map doesn't exist\n", STDERR_FILENO);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

//Helper in main.c/main() to check if the input to 
//the program is valid
void	check_args_validity(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Invalid args.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
