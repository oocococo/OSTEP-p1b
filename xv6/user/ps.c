#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(int argc,char *argv[])
{
	int i;
	struct pstat pstat;
	if(getpinfo(&pstat)<0)
	{
		printf(1,"getinfo error.\n");
		exit();
		return -1;
	}
	printf(1,"|pid|inuse|tickets|ticks|\n");
	for(i=0;i<NPROC;i++)
	{
		if(pstat.inuse[i])
			printf(1,"|  %d  |  %d  |  %d  |  %d  |\n",pstat.pid[i],pstat.inuse[i],pstat.tickets[i],pstat.ticks[i]);
	}
	exit();
	return 0;
	
}
