// Модуль, отвечающий за основную функциональность программы
// Независимый модуль

#ifndef PROCESSING_H_INCLUDED
#define PROCESSING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#define max_len_string 100
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

//структура элемента таблицы
typedef struct{
    char name[max_len_string];
    double price;
    int quantity;
    char brand[max_len_string];
    int shelf_life;
} product;

//функциональный указатель функцию сортировки
typedef int (*func)(const product, const product);

//ожидание ввода ENTER
void enter();

//обработка строки(удаление "\t", "  " и замена символа "|" на "\")
//ВАЖНО!!! "|" - спецсимвол, разграничивающий элементы в таблице при чтении из файла
//вход: указатель на первый элемент строки
void del_space(char *a);

//вывод таблицы
//вход: таблица и ее длина
void output(const product *table, size_t len);

//проверка: является ли строка вещественным числом
//вход: указатель на первый элемент строки
//выход: если да - 1, иначе 0
int is_double(const char *str);

//проверка: является ли строка целым числом
//вход: указатель на первый элемент строки
//выход: если да - 1, иначе 0
int is_int(const char *str);

//создание элемента для функции add
//вход: указатель на первый элемент строки и элемент структуры product
//выход: при удачном заполнении 0, иначе -1. Если передавать NULL - возврат 1
int create(char *buffer, product *elem);

//добавление элемента в таблицу
//вход: указатель на таблицу, длину и добавляемый элемент
void add(product **table, size_t *len, const product *elem);

//удаление элемента из таблицы
//вход: указатель на таблицу, длину и номер удаляемого столбца
//ВАЖНО!!! если p == 0: удаление всех элементов
void del(product **table, size_t *len, int p);

//сохранение таблицы в файл.txt
//вход: таблица, указатель на ее длину и название файла
void savefile(const product *table, const size_t *len, const char *filename);

//загрузка таблицы из файла.txt
//вход: указатель на таблицу, ее длину и название файла
void loadfile(product **table, size_t *len, const char *filename);

//сортировка по столбцу quantity
//вход: два элемента product
//выход: разность двух слов
int sortquan(const product token1, const product token2);

//сортировка по столбцу shelf_life
//вход: два элемента product
//выход: разность двух слов
int sortlife(const product token1, const product token2);

//сортировка по столбцу price
//вход: два элемента product
//выход: знак разности двух слов
int sortprice(const product token1, const product token2);

//сортировка по столбцу name
//вход: два элемента product
//выход: результат применения strcmp к словам
int sortname(const product token1, const product token2);

//сортировка по столбцу brand
//вход: два элемента product
//выход: результат применения strcmp к словам
int sortbrand(const product token1, const product token2);

//полиморфная функция сортировки
//вход: таблица, ее длина, функциональный указатель на функцию сортировки, метка
//ВАЖНО!!! если метка == 1: сортировка по возрастанию, если == -1 - по убыванию
void sort(product *table, size_t len, func f, int label);

#endif // PROCESSING_H_INCLUDED
