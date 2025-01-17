/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:17:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/29 18:40:03 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_stash(char *stash, char *temp, int fd)
{
	int	check_read;

	check_read = 1;
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = 0;
	}
	else
	{
		temp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!temp)
			return (NULL);
		check_read = read(fd, temp, BUFFER_SIZE);
		temp[check_read] = 0;
		if (check_read)
			stash = ft_strjoin(stash, temp);
		free(temp);
		temp = NULL;
	}
	return (stash);
}

static char	*read_fd(int fd, char *stash)
{
	char	*temp;
	int		check_read;

	check_read = 1;
	temp = NULL;
	stash = create_stash(stash, temp, fd);
	while (check_read && !ft_strchr(stash, '\n'))
	{
		temp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!temp)
			return (NULL);
		check_read = read(fd, temp, BUFFER_SIZE);
		if (check_read == -1 || (check_read == 0 && stash[0] == '\0'))
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[check_read] = 0;
		stash = ft_strjoin(stash, temp);
		free(temp);
	}
	return (stash);
}

static char	*fill_line(char	*stash)
{
	char	*list;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	list = ft_substr(stash, 0, i);
	return (list);
}

static char	*clear_stash(char *stash)
{
	char	*temp;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == ft_strlen(stash))
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_fd(fd, stash);
	line = fill_line(stash);
	stash = clear_stash(stash);
	return (line);
}
