# include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (s - 1);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*slicer(char *start, char *end)
{
	size_t	size;
	char	*s;

	size = end - start + 1;
	s = malloc(size + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, start, size + 1);
	return (s);
}

char	*joiner(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len1 + 1);
	ft_strlcpy(s + len1, s2, len2 + 1);
	return (s);
}
