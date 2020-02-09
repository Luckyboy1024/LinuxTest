#include <stdio.h>

int main()
{
  int i=0,a=0;
  while(i<20)
  {
    for(;;)
    {
      if((i%10)==0) break;
      else i--;

    }
    i+=11; a+=i;

  }
  printf("%d\n",a);
  return 0;

}
#if 0
int main()
{
  int x = 10;
  int y = 10;
  x = y = ++y;
  printf("%d %d", x, y);
  return 0;
}
#endif
