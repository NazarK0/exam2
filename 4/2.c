#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *findAndInsert(char *str, char *sub_str, char *sub_str_rep);

int main()
{
  char filename[255];
  FILE *fileptr;
  FILE *fwriteptr;
  char line[255];
  char *eline;
  char *edited_line[255];

  printf("Ведіть назву файлу: ");
  scanf("%s", filename);

  fileptr = fopen(filename, "r");

  if (fileptr == NULL)
  {
    printf("Помилка відкриття файлу\n");
    return -1;
  }
  else
    printf("Файл успішно відкрито\n");

  while (1)
  {
    // Читання одного рядка з файлу
    eline = fgets(line, sizeof(line), fileptr);
    printf("ELINE %s", eline);

    if (eline == NULL)
    {
      // Перевіряємо, що сталось: закінчився файл
      // чи це помилка читання
      if (feof(fileptr) != 0)
      {
        printf("\nЧитання завершено.\n");
        break;
      }
      else
      {
        printf("\nПомилка читання файлу.\n");
        break;
      }
    }

    char *find;

    //Видалення ім'я
    find = strstr(line, " ");

    if (find != NULL)
    {
      strncpy(edited_line, line, strlen(find - line));
    }

    //Видалення прізвища
    find = strstr(edited_line, " ");

    if (find != NULL)
    {
      strncpy(edited_line, edited_line, strlen(find - line));
    }

    // запись в файл
    char* write_filename = strcat(filename, ".sht");
    if((fwriteptr= fopen(write_filename, "w"))==NULL)
    {
        perror("Помилка при відкритті файлу");
        return 1;
    }
    // записуємо змінений рядок в файл
    fputs(edited_line, fwriteptr);
 
    fclose(fwriteptr);
  }

  // Закриваємо файл
  printf("Закриття файлу: ");
  if (fclose(fileptr) == EOF)
    printf("помилка\n");
  else
    printf("виконано\n");

  return 0;
}

char *findAndInsert(char *str, char *sub_str, char *sub_str_rep)
{
  const int BUFFER_SIZE = 256;
  char *buffer = NULL;
  int buffer_len = 0;
  //  якщо вхідних даних немає, нічого не робимо
  if (str && sub_str && sub_str_rep)
  {
    // робимо припущеннящо під рядок str виділено достатньо пам'яті.
    // в іншому випадку нічого не робимо

    // якщо довжина рядка str достатня для зберігання нового рядка, продовжуємо
    if (strlen(str) < strlen(str) - strlen(sub_str) + strlen(sub_str_rep))
    {
      // тимчасовий массив
      buffer = (char *)malloc(BUFFER_SIZE);
      // чистимо масив від сміття
      memset(buffer, 0, strlen(str));

      strncpy(buffer, str, strlen(str) - strlen(strstr(str, sub_str)));
      strcat(buffer, sub_str_rep);
      strcat(buffer, strstr(str, sub_str) + strlen(sub_str));
      strcpy(str, buffer);

      // звільняємо пам'ять
      free(buffer);
    }
  }
  return str;
}