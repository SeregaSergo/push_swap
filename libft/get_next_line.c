/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:52:34 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 20:47:30 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Parsing the list with fd reminders, and returning a pointer on element
** with the same fd. If function doesn't find element it will be created.
*/

static t_fd_data	*find_fd(int fd, t_lstg **fd_list)
{
	t_fd_data	*ptr_fd;
	t_lstg		*ptr_lst;

	ptr_lst = *fd_list;
	while (ptr_lst)
	{
		if (fd == (ptr_lst->content->fd))
			return (ptr_lst->content);
		ptr_lst = ptr_lst->next;
	}
	ptr_fd = (t_fd_data *)malloc(sizeof(t_fd_data));
	if (!ptr_fd)
		return (NULL);
	ptr_lst = (t_lstg *)malloc(sizeof(t_lstg));
	if (!ptr_lst)
	{
		free(ptr_fd);
		return (NULL);
	}
	ptr_fd->fd = fd;
	ptr_fd->rem = NULL;
	ptr_lst->content = ptr_fd;
	ptr_lst->next = *fd_list;
	*fd_list = ptr_lst;
	return ((*fd_list)->content);
}

static int	ft_read(t_fd_data *fd_data, char *buf)
{
	int		chars;
	char	*tmp_str;

	chars = read(fd_data->fd, buf, BUFFER_SIZE);
	if (chars < 0)
		return (chars);
	buf[chars] = '\0';
	tmp_str = gnl_strjoin(fd_data->rem, buf);
	if (!tmp_str)
		return (-1);
	free(fd_data->rem);
	fd_data->rem = tmp_str;
	return (chars);
}

/*
** Looking for structure in list of fd with parametr
** fd and delete it in a safe way.
*/

static void	ft_del_fd(int fd, t_lstg **fd_list)
{
	t_lstg	**ptr;
	t_lstg	*tmp_adr;

	ptr = fd_list;
	while ((*ptr)->content->fd != fd)
		ptr = &((*ptr)->next);
	free((*ptr)->content);
	tmp_adr = (*ptr)->next;
	free(*ptr);
	*ptr = tmp_adr;
}

static int	init(char **buf, t_fd_data **data, t_lstg **fd_list, int fd)
{
	*buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	*data = find_fd(fd, fd_list);
	if (!(*data) || !(*buf))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_lstg	*fd_list;
	t_fd_data		*data;
	int				pos_char;
	char			*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || init(&buf, &data, &fd_list, fd))
		return (-1);
	while (gnl_strchr(data->rem, '\n') < 0)
	{
		pos_char = ft_read(data, buf);
		if (pos_char < 1)
		{
			if (pos_char == 0)
				*line = data->rem;
			free(buf);
			ft_del_fd(data->fd, &fd_list);
			return (pos_char);
		}
	}
	pos_char = gnl_strchr(data->rem, '\n');
	free(buf);
	*line = gnl_substr(data->rem, 0, pos_char);
	gnl_strlcpy(data->rem, &(data->rem[pos_char + 1]), ft_strlen(data->rem));
	return (1);
}
