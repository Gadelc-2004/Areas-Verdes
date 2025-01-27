#include <stdio.h>
#include <stdlib.h>
#include <libexif/exif-data.h>
#include <libexif/exif-tag.h>
#include <string.h>
#include <dirent.h>

struct imagem {
  char nome[40], lati[32], longi[32];
  int latint[2], longiint[2];
  float flat, flongi;
};

void print_informations(struct imagem *x);
void convertion(struct imagem *a);
void print(struct imagem x);
void ordenacao(struct imagem *list);

int main(int argc, char *argv[]) 
{
  DIR *dir;
  struct dirent *entry;

  dir = opendir("./");
  if(dir == NULL)
  {
    printf("Erro ao abrir o diretório\n");
    return 1;
  }

  struct imagem a[10];
  int i = 0;

  printf("CARREGANDO ARQUIVOS JPG\n");
  while((entry = readdir(dir)) != NULL) 
  {
    if(strstr(entry->d_name, ".JPG") != NULL)
    {
      strcpy(a[i].nome, entry->d_name);
      printf("Arquivo: %s\n", a[i].nome);
      print_informations(&a[i]);
      convertion(&a[i]);
      i++;
    }
  }

  int max = i;

  printf("\n");

  for(int i = 0; i < max; i++)
  {
    print(a[i]);
    printf("\n");
  }

  closedir(dir);

  return 0;
}

void print_informations(struct imagem *x)
{
  ExifData *data_file = exif_data_new_from_file(x->nome);
  if(!data_file)
  {
    printf("Não foi possível carregar os metadados EXIF do arquivo: %s\n", x->nome);
    return;
  }

  ExifEntry *lat_entry = exif_data_get_entry(data_file, EXIF_TAG_GPS_LATITUDE);
  ExifEntry *lon_entry = exif_data_get_entry(data_file, EXIF_TAG_GPS_LONGITUDE);

  if(lat_entry)
  {
    char latitude[32];
    exif_entry_get_value(lat_entry, latitude, sizeof(latitude));
    strcpy(x->lati, latitude);
  }else
  {
    printf("Erro ao carregar a Latitude\n");
  }

  if(lon_entry)
  {
      char longitude[32];
      exif_entry_get_value(lon_entry, longitude, sizeof(longitude));
      strcpy(x->longi, longitude);
  }else
  {
    printf("Erro ao carregar a Longitude\n");
  }

  exif_data_unref(data_file);
}

void convertion(struct imagem *a)
{
  struct imagem *x = a;
  char *comma1, *comma2;

  comma1 = strchr(x->lati, ',');
  comma2 = comma1 ? strchr(comma1 + 1, ',') : NULL;

  x->latint[0] = strtol(x->lati, NULL, 10);
  x->latint[1] = comma1 ? strtol(comma1 + 1, NULL, 10) : 0;
  x->flat = comma2 ? strtof(comma2 + 1, NULL) : 0.0;

  comma1 = strchr(x->longi, ',');
  comma2 = comma1 ? strchr(comma1 + 1, ',') : NULL;

  x->longiint[0] = strtol(x->longi, NULL, 10);
  x->longiint[1] = comma1 ? strtol(comma1 + 1, NULL, 10) : 0;
  x->flongi = comma2 ? strtof(comma2 + 1, NULL) : 0.0;
}

void print(struct imagem x)
{
  printf("Nome: %s\n", x.nome);
  printf("Latitude: %s\n", x.lati);
  printf("Longitude: %s\n", x.longi);
  /*printf("Latitude (int): %d | %d\n", x.latint[0], x.latint[1]);
  printf("Latitude (float): %f\n", x.flat);
  printf("Longitude (int): %d | %d\n", x.longiint[0], x.longiint[1]);
  printf("Longitude (float): %f\n", x.flongi);*/
  return;
}

void ordenacao(struct imagem *list)
{
  float lower, high;

  for(int i = 0; i < quant; i++)
  {
    if(list[i].)
  }

  return;
}
