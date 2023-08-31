
#include <stdio.h>
int fun1()
{
    printf("new %s\n",__FUNCTION__);
    return 0;
}
int main()
{
  fun1();
  return 0;
}