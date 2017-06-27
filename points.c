
#include <mlx.h>
#include "libft/libft.h"

int		main()
{
	char	*lines;
	char	**holder;
	//int	no_lines;
	int	fd;
	//int	width;
	int	i;
	
	fd = open("42.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error opening file");
		return (1);
	}
	i = 0;
	holder = (char **)malloc(sizeof(char *) * 1000);
	ft_bzero(holder, 1000);
	if (fd > 0)
	{
		while (get_next_line(fd, &lines) == 1)
		{
			holder[i] = ft_strdup(lines);
			//width = ft_strlen(line);
			ft_putstr(holder[i]);
			ft_putchar('\n');
			i++;
			free(lines);
		}
		ft_putnbr(i);
		ft_putchar('\n');
	}

	int a;
	int b;

	a = 0;
	b = 0;
	
	while (holder[a])
	{
		ft_putstr(holder[a]);
		ft_putchar('\n');
		a++;
	}
	return (0);
	close(fd);
	return (0);
}

