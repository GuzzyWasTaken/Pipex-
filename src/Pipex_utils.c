#include "../includes/pipex.h"

static int	wordcount(char const *str, char c);
static int	wordleng(const char *s, char c);
static char	**ft_free(int j, char **str);
static char	*ft_cpy(char const *s, size_t len);

char	**ft_split(char const *s, char c)
{
	int		wordamount;
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	wordamount = wordcount(s, c);
	str = (char **)malloc((wordamount + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	j = 0;
	while (j < wordamount)
	{
		while (*s == c && *s != '\0')
			s++;
		str[j] = ft_cpy(s, wordleng(s, c));
		if (!str[j])
			return (ft_free(j, str));
		s += wordleng(s, c);
		j++;
	}
	str[j] = (NULL);
	return (str);
}

static int	wordcount(char const *str, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != 0)
			counter++;
		while (str[i] != c && str[i] != 0)
			i++;
	}
	return (counter);
}

static int	wordleng(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_cpy(char const *s, size_t len)
{
	char			*p;
	unsigned int	count;

	count = 0;
	p = malloc((len + 1) * sizeof (char));
	if (!p)
		return (NULL);
	while (len > 0)
	{
		p[count] = s[count];
		count++;
		len--;
	}
	p[count] = '\0';
	return (p);
}

static char	**ft_free(int j, char **str)
{
	j--;
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}
