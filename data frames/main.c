///*БАЗА ДАННЫХ. Работа с таблицей продуктового магазина
//*(C) D. S. Agichev, весна 2025
//*/

//Интерфейс программы

#include "processing.h"
#include "grap.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
    product *table = NULL;
    size_t len = 0;
    char buffer[max_len_string];
    product elem;

    printf("Developer: Agichev D.S.\n\nWelcome to the grocery store database.\nIn this application, you can process a table by 5 columns: name, price, quantity, brand and shelf life.\nTo start working, ");
    enter();

    int label = 10, num;
    while(label != 0){
        system("cls");
        printf("Select an action:\n");
        printf("\n1. Add product\n2. Remove product\n3. Show products\n4. Save to file\n5. Load from file\n6. Sort\n7. Show bar chart\n8. Show pie chart\n0. Exit\n");
        fgets(buffer, max_len_string, stdin);
        del_space(buffer);
        if(is_int(buffer) == 0){
            printf("Invalid input\n");
            enter();
        }
        else{
            label = atoi(buffer);
            switch(label){
            case 0:
                free(table);
                break;
            case 1:
                system("cls");
                num = create(buffer, &elem);
                if(num == -1){
                    printf("Invalid input\n");
                }
                else if(num == 0){
                    add(&table, &len, &elem);
                    printf("Product added");
                }
                enter();
                break;
            case 2:
                system("cls");
                if(len == 0){
                    printf("There are no elements in the table\n");
                    enter();
                    break;
                }
                output(table, len);
                printf("Enter line number (0 - delete all)\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                if(strlen(buffer) == 0 || is_int(buffer) == 0){
                    printf("Invalid input\n");
                }
                else{
                    num = atoi(buffer);
                    if(0 <= num && num < (int)len + 1){
                        del(&table, &len, num);
                        printf("Product deleted\n");
                    }
                    else{
                        printf("Invalid input\n");
                    }
                }
                enter();
                break;
            case 3:
                system("cls");
                output(table, len);
                enter();
                break;
            case 4:
                system("cls");
                printf("Enter file name\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                if(access(buffer, F_OK) == 0){
                    printf("There is already such a file\n");
                }
                else{
                    savefile(table, &len, buffer);
                    printf("File written\n");
                }
                enter();
                break;
            case 5:
                system("cls");
                printf("Enter file name\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                if(access(buffer, F_OK) == -1){
                    printf("File not found\n");
                }
                else{
                    loadfile(&table, &len, buffer);
                    printf("File uploaded\n");
                }
                enter();
                break;
            case 6:
                system("cls");
                printf("Enter column to sort by\n1)name 2)price 3)quantity 4)brand 5)shelf life\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num = atoi(buffer);
                if(is_int(buffer) == 0 || (1 > num || num > 5)){
                    printf("Invalid input\n");
                    enter();
                    break;
                }
                printf("Enter sort type(1 - ascending, 2 - descending)\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num += atoi(buffer) * 10;
                if(is_int(buffer) == 0 || (1 > num / 10 || num / 10 > 2)){
                    printf("Invalid input\n");
                    enter();
                    break;
                }
                switch(num){
                case 11:
                    sort(table, len, sortname, 1);
                    break;
                case 12:
                    sort(table, len, sortprice, 1);
                    break;
                case 13:
                    sort(table, len, sortquan, 1);
                    break;
                case 14:
                    sort(table, len, sortbrand, 1);
                    break;
                case 15:
                    sort(table, len, sortlife, 1);
                    break;
                case 21:
                    sort(table, len, sortname, -1);
                    break;
                case 22:
                    sort(table, len, sortprice, -1);
                    break;
                case 23:
                    sort(table, len, sortquan, -1);
                    break;
                case 24:
                    sort(table, len, sortbrand, -1);
                    break;
                case 25:
                    sort(table, len, sortlife, -1);
                    break;
                }
                printf("The table is sorted\n");
                enter();
                break;
            case 7:
                if(len == 0){
                    printf("The table is empty\n");
                    enter();
                    break;
                }
                printf("Enter table field?\n1)price 2)quantity 3)shelf life\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num = atoi(buffer);
                if(is_int(buffer) == 0 || (1 > num || num > 3)){
                    printf("Invalid input\n");
                    enter();
                    break;
                }
                printf("The diagram is displayed\n");
                switch(num){
                case 1:
                    draw_graph(table, len, arrprice);
                    break;
                case 2:
                    draw_graph(table, len, arrquan);
                    break;
                case 3:
                    draw_graph(table, len, arrlife);
                    break;
                }
                break;
            case 8:
                if(len == 0){
                    printf("The table is empty\n");
                    enter();
                    break;
                }
                printf("Enter table field?\n1)price 2)quantity 3)shelf life\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num = atoi(buffer);
                if(is_int(buffer) == 0 || (1 > num || num > 3)){
                    printf("Invalid input\n");
                    enter();
                    break;
                }
                printf("The diagram is displayed\n");
                switch(num){
                case 1:
                    draw_pie(table, len, arrprice);
                    break;
                case 2:
                    draw_pie(table, len, arrquan);
                    break;
                case 3:
                    draw_pie(table, len, arrlife);
                    break;
                }
                break;
            default:
                printf("Invalid input\n");
                enter();
                break;
            }
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
