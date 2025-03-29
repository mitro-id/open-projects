// ������, ���������� �� �������� ���������������� ���������
// ����������� ������

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

//��������� �������� �������
typedef struct{
    char name[max_len_string];
    double price;
    int quantity;
    char brand[max_len_string];
    int shelf_life;
} product;

//�������������� ��������� ������� ����������
typedef int (*func)(const product, const product);

//�������� ����� ENTER
void enter();

//��������� ������(�������� "\t", "  " � ������ ������� "|" �� "\")
//�����!!! "|" - ����������, ���������������� �������� � ������� ��� ������ �� �����
//����: ��������� �� ������ ������� ������
void del_space(char *a);

//����� �������
//����: ������� � �� �����
void output(const product *table, size_t len);

//��������: �������� �� ������ ������������ ������
//����: ��������� �� ������ ������� ������
//�����: ���� �� - 1, ����� 0
int is_double(const char *str);

//��������: �������� �� ������ ����� ������
//����: ��������� �� ������ ������� ������
//�����: ���� �� - 1, ����� 0
int is_int(const char *str);

//�������� �������� ��� ������� add
//����: ��������� �� ������ ������� ������ � ������� ��������� product
//�����: ��� ������� ���������� 0, ����� -1. ���� ���������� NULL - ������� 1
int create(char *buffer, product *elem);

//���������� �������� � �������
//����: ��������� �� �������, ����� � ����������� �������
void add(product **table, size_t *len, const product *elem);

//�������� �������� �� �������
//����: ��������� �� �������, ����� � ����� ���������� �������
//�����!!! ���� p == 0: �������� ���� ���������
void del(product **table, size_t *len, int p);

//���������� ������� � ����.txt
//����: �������, ��������� �� �� ����� � �������� �����
void savefile(const product *table, const size_t *len, const char *filename);

//�������� ������� �� �����.txt
//����: ��������� �� �������, �� ����� � �������� �����
void loadfile(product **table, size_t *len, const char *filename);

//���������� �� ������� quantity
//����: ��� �������� product
//�����: �������� ���� ����
int sortquan(const product token1, const product token2);

//���������� �� ������� shelf_life
//����: ��� �������� product
//�����: �������� ���� ����
int sortlife(const product token1, const product token2);

//���������� �� ������� price
//����: ��� �������� product
//�����: ���� �������� ���� ����
int sortprice(const product token1, const product token2);

//���������� �� ������� name
//����: ��� �������� product
//�����: ��������� ���������� strcmp � ������
int sortname(const product token1, const product token2);

//���������� �� ������� brand
//����: ��� �������� product
//�����: ��������� ���������� strcmp � ������
int sortbrand(const product token1, const product token2);

//����������� ������� ����������
//����: �������, �� �����, �������������� ��������� �� ������� ����������, �����
//�����!!! ���� ����� == 1: ���������� �� �����������, ���� == -1 - �� ��������
void sort(product *table, size_t len, func f, int label);

#endif // PROCESSING_H_INCLUDED
