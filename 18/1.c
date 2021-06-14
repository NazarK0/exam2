#include <stdio.h>

int main()
{
  char filename[255];
  FILE *fileptr;
  char line[255];
  char *eline;

  printf("Enter filename: ");
  scanf("%s", filename);

  fileptr = fopen(filename, "r");

   if (fileptr == NULL) 
    {printf ("Помилка відкриття файлу\n"); return -1;}
   else printf ("Файл успішно відкрито\n");
  
  //Чтение (побайтно) данных из файла в бесконечном цикле
   while (1)
   {
      // Чтение одного байта из файла
      eline = fgets (line, sizeof(line), fileptr);

      if (eline == NULL)
      {
         // Проверяем, что именно произошло: кончился файл
         // или это ошибка чтения
         if ( feof (fileptr) != 0)
         {  
            //Если файл закончился, выводим сообщение о завершении 
            //чтения и выходим из бесконечного цикла
            printf ("\nЧтение файла закончено\n");
            break;
         }
         else
         {
            //Если при чтении произошла ошибка, выводим сообщение 
            //об ошибке и выходим из бесконечного цикла
            printf ("\nОшибка чтения из файла\n");
            break;
         }
      }
      printf ("     %s",line);
   }

   // Закрываем файл
   printf ("Закрытие файла: ");
   if ( fclose (fileptr) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");

  

  return 0;
}