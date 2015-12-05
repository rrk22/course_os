#include <thread.h>
#include <assert.h>
#include <stdio.h>

void* f(void* arg)
{
   printf("in thread\n");

   return arg;
}

void main(void)
{
   thread_t thread;
   thread_create(&thread, f, (void*) 1);

   int res=0;

   printf("before join\n");

   thread_join(thread, (void**) &res);

   printf("after join\n");  

   assert(res==1);
}
