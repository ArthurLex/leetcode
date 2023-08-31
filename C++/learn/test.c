
//test.c
#include <stdio.h>
int fun1() __attribute__((weak));
 
int fun1() 
{
  printf("%s\n",__FUNCTION__);
  return 0;
}