void	ft_quicksort(int *tab, int start, int end)
{
	int	piv;
	int	buf;

	while (start < end)
	{
		piv = (start + end) / 2;
		while (tab[start] < tab[piv])
			start++;
		while (tab[end] > tab[piv])
			end--;
		if (tab[start] <= tab[end])
		{
			buf = tab[start];
			tab[start] = tab[end];
			tab[end] = buf;
		}
		start++;
		end--;
	}
}

int main() {

  int *tab;
  tab = (int *)malloc(sizeof(int) * 12);
  tab[0] = 8;
  tab[1] = 12;
  tab[2] = 0;
  tab[3] = -4;
  tab[4] = 5;
  tab[5] = 1;
  tab[6] = 18;
  tab[7] = 45;
  tab[8] = 125775;
  tab[9] = 0;
  tab[10] = -42;
  tab[11] = 19;
  
  ft_quicksort(tab, 0, 11);

  return 0;
}

