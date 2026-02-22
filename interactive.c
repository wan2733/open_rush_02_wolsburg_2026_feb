#include "rush02.h"

void	interactive()
{
	char	buffer[1024];
	int		size;
	
	while ((size = read(0, buffer, sizeof(buffer))) > 0)
	{
		buffer[size] = 0; // to discard enter
		//printf("call main_next(\"numbers.dict\", buffer), where buffer = %s", buffer);
		main_next("numbers.dict", buffer);
	}
}
