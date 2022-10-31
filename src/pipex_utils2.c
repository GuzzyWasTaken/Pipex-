/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 16:54:04 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/10/31 16:58:00 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while ((*st1 != '\0' || *st2 != '\0') && (n > 0))
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		n--;
		st1++;
		st2++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (*s1 == '\0' && *s2 == '\0')
	{
		free (s1);
		return (ft_strdup(""));
	}
	str = ft_calloc((ft_strlen(s1) + (ft_strlen(s2) + 1)), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (*s2 != ' ' && *s2)
	{
		str[i] = *s2++;
		i++;
	}
	free (s1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!p)
		return (NULL);
	while (s[i] != 0)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
