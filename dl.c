#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char line[80];
  int count;

  #ifdef PARALLEL
  printf("PARALLEL\n");
  #endif
  #ifndef PARALLEL
  printf("SERIAL\n");
  #endif

  FILE *fp = fopen("urls.txt", "rt");
  for ( count = 0; fgets(line, 80, fp); count ++ )
  {
    if ( line[strlen(line)-1] == '\n')
      line[strlen(line)-1] = 0;
    if ( !fork() )
      execlp("/usr/bin/wget", "wget", line, NULL);
    else
    { 
      #ifndef PARALLEL
      wait(NULL);
      #endif
    }
  }
  fclose(fp);

  #ifdef PARALLEL
  while ( count-- )
    wait(NULL);
  #endif
  return 0;
}
