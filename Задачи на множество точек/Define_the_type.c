
// Чернощёкова Алина Фёдоровна, группа 112

#include "headers.h" // Подключаем другие функции

// Функция для определения вида многоугольника

void Define_the_type (double *x, double *y, int count_vertices)
{
    // Если многоугольник - треугольник, то он обязательно выпуклый
    if (count_vertices-2==3)
    {
        printf("The polygon is convex, it's a triangle ");
    }

    // Если многоугольник - это не треугольник
    else
    {
        int f1=0, f2=0; // Переменные-флаги
        double k; // Угловой коэффициент прямой, которую задают i-ая и i+2-ая точки
        double b; // Свободный член прямой, которую задают i-ая и i+2-ая точки

        for(int i=0; i<count_vertices-2; i++)
        {
            // Находим уравнение прямой, которую задают i-ая и i+2-ая точки многоугольника
            k = (y[i+2]-y[i])/(x[i+2]-x[i]); // Считаем угловой коэффициент 
            b = y[i]-k*x[i]; // Считаем свободный член

            // Определяем сколько точек многоугольника лежат выше данной прямой
            int count_f1=0; // Количество точек, лежащих выше прямой
            for(int j=0; j<count_vertices; j++)
            {
                if (y[j]-k*x[j]-b>0)
                {
                    f1=1;
                    count_f1++;
                } 
                
                if (y[i+1]-k*x[i+1]-b<0)
                {
                    f1=0;
                }
            }
            
            /* Если количество точек, лежащих по одну сторону от заданной прямой, 
               равно числу всех точек многоугольника, кроме тех двух, что её задают, то
               многоугольник невыпуклый */
            if (count_f1==0 || count_f1==(count_vertices-2))
            {
                f2=1; // Сигнал невыпуклости

                printf("The polygon is not convex \n");

                FILE*file; 
                char filename[120]; 
                printf("Enter file name to write the special points: "); // Вводим имя файла для записи данных
                scanf("%s", filename); 
                file = fopen(filename, "w"); 

                if (!file) // Если файл не открылся, пишем, что файл нельзя открыть, и возвращаем 1
                { 
                    printf("Unable to open %s\n", filename); 
                    break;
                }

                fprintf(file, "%lf %lf", x[i], y[i]);
                fprintf(file, "\n");
                fprintf(file, "%lf %lf", x[i+2], y[i+2]);

                break;
                fclose(file); // Закрываем файл
            }
        }
        
        // Проверяем сигнал невыпуклости
        if (f2==0)
        {
            printf("The polygon is convex");
        }
    }
}