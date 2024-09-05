
#include "../Includes/cub3d.h"

static size_t	ft_strlen_magic(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
			j = i;
		}
		i++;
	}
	return (i - j);
}

char	*ft_strdup_magic(char *s)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	dup = (char *)malloc((sizeof(char)) * (ft_strlen_magic(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
		}
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

void	ft_map_len(t_data *d, int i)
{
	int	j;

	j = 0;
	while (d->file[i])
	{
		if (d->file[i][0] != '\n')
			d->map_rows++;
		else if (d->file[i][0] == '\n')
			break ;
		while (d->file[i][j] && d->file[i][j] != '\n')
			j++;
		if (j >= d->map_lgcol)
			d->map_lgcol = j + 2;
		j = 0;
		i++;
	}
	d->map = (char **)malloc(sizeof(char *) * (d->map_rows + 1));
	if (!d->map)
		exit(exit_game(2));
}
