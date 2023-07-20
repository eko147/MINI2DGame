#include "minigame.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hst;

	i = 0;
	j = 0;
	hst = (char *)haystack;
	if (needle[i] == '\0')
		return (hst);
	if (len == 0)
		return (NULL);
	while (hst[i] != '\0' && i < len)
	{
		j = 0;
		if (hst[i] == needle[j])
		{
			while ((hst[i + j] == needle[j])
				&& (needle[j] != '\0') && (i + j < len))
				j++;
			if (needle[j] == '\0')
				return (&hst[i]);
		}
		i++;
	}
	return (NULL);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}
