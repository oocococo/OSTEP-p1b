#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int pinfo()
{
	int i;
	struct pstat pstat;
	if (getpinfo(&pstat) < 0) {
		printf(2, "getpinfo err.\n");
		exit();
		return -1;
	}
	printf(1, "|pid|tickets|ticks|\n");
	for (i = 0; i < NPROC; i++) {
		if (pstat.inuse[i]) {
			printf(1, "|  %d  |  %d  |  %d  |\n", pstat.pid[i], pstat.tickets[i], pstat.ticks[i]);
		}
	}
	return 0;
}

int work()
{
	int i, x;
	for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}

	for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}

	for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}
	for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}

for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}
	for (i = 0; i < 100000000; i++)
		x += 1;

	if (pinfo() < 0) {
		printf(2, "pinfo err.\n");
		exit();
		return -1;
	}



	return 0;
}

int main(int argc, char* argv[])
{
	settickets(10);
	int ret = fork();
	if (ret < 0) {
		printf(2, "fork err.\n");
		exit();
		return -1;
	}
	if (ret == 0) // new proc
	{
		settickets(20);
		ret = fork();
		if (ret < 0) {
			printf(2, "fork err.\n");
			exit();
			return -1;
		}
		if (ret == 0) {
			settickets(30);
			work();
			exit();
		} else {
			work();
			//wait();
			exit();
		}
	}
	work();
	//wait();
	exit();
}
