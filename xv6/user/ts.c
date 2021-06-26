#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{
	int i, x;
	if (argc != 3) {
		exit();
		return -1;
	}
	settickets(atoi(argv[1]));
	x = 0;
	for (i = 0; i < atoi(argv[2]); i++) {
		x += 1;
	}
	exit();
	return 0;
}
