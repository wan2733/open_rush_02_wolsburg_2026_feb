#include "rush02.h"

void	interactive()
{
	char	buffer[1024];
	int		size;
	
	while ((size = read(0, buffer, sizeof(buffer))) > 0)
	{
		buffer[size - 1] = 0;
		if (main_next("numbers.dict", buffer))
			print_error(-1);
		else
			write(1, "\n", 1);
	}
}
