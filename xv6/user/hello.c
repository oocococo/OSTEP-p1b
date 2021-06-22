//#include "types.h"
//#include "user.h"
//
//int main(int argc,char *argv[]){
//	printf(1,"hello my name is '%s'\nread counter is '%d'",argv[0],getreadcount());
//	exit();
//}
//
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
  int x1 = getreadcount();
  int x2 = getreadcount();
  char buf[100];
  (void) read(4, buf, 1);
  int x3 = getreadcount();
  int i;
  for (i = 0; i < 1000; i++) {
    (void) read(4, buf, 1);
  }
  int x4 = getreadcount();
  printf(1, "XV6_TEST_OUTPUT %d %d %d\n", x2-x1, x3-x2, x4-x3);
  exit();
}
