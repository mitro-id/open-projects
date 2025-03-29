/* Модуль, отвечающий за построение графиков по столбцам.
   ВАЖНО!!! Требует подключения модуля "processing.h"*/

#ifndef GRAP_H_INCLUDED
#define GRAP_H_INCLUDED
#include "processing.h" // импорт структуры product и необходимых для работы библиотек

//функциональный указатель на функцию, создающую массив по столбцу
typedef void (*cnst)(const product*, size_t, double*);

//ожидание ввода ENTER с клавиатуры
void enter();

//вычисление максимума массива
//вход: массив и длина
//выход: максимальное значение массива
double double_max(const double *array, size_t len);

//создание массива по столбцу price
//вход: таблица, длина талицы, заполняемый массив
void arrprice(const product *table, size_t len, double *array);

//создание массива по столбцу shelf life
//вход: таблица, длина талицы, заполняемый массив
void arrlife(const product *table, size_t len, double *array);

//создание массива по столбцу quantity
//вход: таблица, длина талицы, заполняемый массив
void arrquan(const product *table, size_t len, double *array);

//вывод столбчатой диаграммы
//вход: таблица, длина талицы, функция типа cnst
void draw_graph(const product *table, size_t len, cnst f);

//вычисление суммы элементов
//вход: массив и длина
//выход: сумма элементов
double sum(const double *array, size_t len);

//вывод круговой диаграммы
//вход: таблица, длина талицы, функция типа cnst

void draw_pie(const product *table, size_t len, cnst f);

#endif // GRAP_H_INCLUDED
