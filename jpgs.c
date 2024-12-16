#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main()
{
  DIR *dir;
  struct dirent *entry;

  dir = opendir("./");
  if (dir == NULL) 
  {
    perror("Erro ao abrir o diretório");
    return 1;
  }

  while((entry = readdir(dir)) != NULL) 
  {
    if(strstr(entry->d_name, ".jpg") != NULL) 
    {
      printf("Arquivo: %s\n", entry->d_name);
    }
  }

  closedir(dir);
  return 0;
}

