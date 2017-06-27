
#include "get_next_line.h"

int             get_next_line(int const fd, char **line)
{
	char			*u;
	char			*t;
	int				c[2];
	static char		*s[42 + 1];
	char			b[BUFF_SIZE];

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	c[1] = 0;
	while ((c[0] = read(fd, b, BUFF_SIZE)) > 0)
	{
		c[1] = 1;
		INPUT;
		OUTPUT;
	}
	if (c[0] < 0)
		return (-1);
	OUTPUT;
	if (s[fd] && (c[1] || s[fd][0]) && !(ft_strstr(s[fd], "\n")))
		SPECIAL;
	return (0);
}

/*int     main()
{
        int     fd;
        char    *line;

        fd = open("random.txt", O_RDONLY);
        while (get_next_line(fd, &line) == 1)
        {
	      	ft_putendl(line);
                free(line);
        }
        close(fd);
        return (0);
}*/

