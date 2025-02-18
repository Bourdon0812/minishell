/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:42 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/24 13:07:16 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

////////////////////////////////////////////////////////////////////////////////
// merge temp and buffer, clean old data and return result of merge
char	*ft_fusion(char *temp, char *buffer)
{
	char	*result;

	result = ft_strjoin(temp, buffer);
	if (!result)
		return (free(temp), NULL);
	return (free(temp), result);
}

////////////////////////////////////////////////////////////////////////////////
// read from fd with BUFFER_SIZE length and return concatenation of 
// previous buffer and actual read
char	*ft_read(int fd, char *temp)
{
	int		count;
	char	*buffer;

	if (!temp)
		temp = ft_strdup("");
	if (!temp)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(temp), free(buffer), NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(buffer), free(temp), NULL);
		buffer[count] = '\0';
		temp = ft_fusion(temp, buffer);
		if (!temp)
			return (free(buffer), free(temp), NULL);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(buffer);
	return (temp);
}

////////////////////////////////////////////////////////////////////////////////
// take the result of ft_read and return a line if there is, the last if no
// line detected or NULL if end / error
void	ft_filter(char **temp, char **line)
{
	char	*newline;

	if (!(*temp)[0])
		return (*line = NULL, free(*temp), *temp = NULL, (void)0);
	newline = ft_strchr(*temp, '\n');
	if (newline)
	{
		*line = ft_substr(*temp, 0, newline - *temp + 1);
		if (!*line)
			return (free(*temp), *temp = NULL, (void)0);
		newline = ft_strdup(newline + 1);
		if (!newline)
			return (free(*line), free(*temp), *temp = NULL, (void)0);
	}
	else
	{
		*line = ft_strdup(*temp);
		newline = NULL;
	}
	free(*temp);
	*temp = newline;
}

////////////////////////////////////////////////////////////////////////////////
// print a line from a file and the next line if recall while there are
// something in the file
char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read(fd, temp);
	if (!temp)
		return (NULL);
	ft_filter(&temp, &line);
	return (line);
}
