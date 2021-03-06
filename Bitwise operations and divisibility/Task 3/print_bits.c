
//Чернощёкова Алина Фёдоровна, группа 112

#include "headers.h"

// Функция вывода битового представления числа

void print_bits(int number, int *bits)
{
    for (int j = 0; j < 32; j++) 
        {
            bits[31-j] = number & 1; // Записываем (начиная с конца) в массив бит числа (начинаем с самого правого бита)
            number >>= 1; // Сдвиг числа вправо на один разряд
        }
}