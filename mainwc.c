#include <stdio.h>
#include "wc.h"

int main(int argc , char* argv[])
{
	int i ;
	if(argv[1][0]!='-')
	{
		for(i=1 ; i<argc ; i++)
		{
			nooption(argv[i]);
		}
	}
	else
	{
		for(i=2 ; i<argc ; i++)
		{
			option(argv[1],argv[i]);
		}
	}

	return (0) ;
}
