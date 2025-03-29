/* ������, ���������� �� ���������� �������� �� ��������.
   �����!!! ������� ����������� ������ "processing.h"*/

#ifndef GRAP_H_INCLUDED
#define GRAP_H_INCLUDED
#include "processing.h" // ������ ��������� product � ����������� ��� ������ ���������

//�������������� ��������� �� �������, ��������� ������ �� �������
typedef void (*cnst)(const product*, size_t, double*);

//�������� ����� ENTER � ����������
void enter();

//���������� ��������� �������
//����: ������ � �����
//�����: ������������ �������� �������
double double_max(const double *array, size_t len);

//�������� ������� �� ������� price
//����: �������, ����� ������, ����������� ������
void arrprice(const product *table, size_t len, double *array);

//�������� ������� �� ������� shelf life
//����: �������, ����� ������, ����������� ������
void arrlife(const product *table, size_t len, double *array);

//�������� ������� �� ������� quantity
//����: �������, ����� ������, ����������� ������
void arrquan(const product *table, size_t len, double *array);

//����� ���������� ���������
//����: �������, ����� ������, ������� ���� cnst
void draw_graph(const product *table, size_t len, cnst f);

//���������� ����� ���������
//����: ������ � �����
//�����: ����� ���������
double sum(const double *array, size_t len);

//����� �������� ���������
//����: �������, ����� ������, ������� ���� cnst

void draw_pie(const product *table, size_t len, cnst f);

#endif // GRAP_H_INCLUDED
