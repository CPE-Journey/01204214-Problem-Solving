#include "probelib.h"
#include <cstdio>

int n;

main()
{
  int n = probe_init();

  for(int i=0; i<10; i++) {
    if(probe_check(i,i)) {
      probe_answer(i);
    }
  }
  
  probe_answer(n-1);
}
