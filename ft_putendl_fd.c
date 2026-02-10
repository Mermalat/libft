/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:17 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 02:54:06 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    while (*s)
    {
        write(fd, s, 1);
        s++;
    }
    write(fd, "\n", 1);
}

#include <fcntl.h>

int main()
{
	int fd = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	ft_putendl_fd("Hello, World!", fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(12345, fd);
	ft_putstr_fd("\nThis is a test.\n", fd);
	close(fd);
	return 0;
}