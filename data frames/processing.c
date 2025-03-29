#include "processing.h"

void output(const product *table, size_t len){
    printf("%-5s|%-28s|%-28s|%-28s|%-28s|%-28s|\n", "num", "1) name", "2) price", "3) quantity", "4) brand", "5) shelf_life");
    int num = 1;
    char strname[28], strbrand[28];
    for(const product *i = table, *e = table + len; i < e; i++){
        for(int j = 0; j < 28; j++){
            strname[j] = ((*i).name)[j];
            strbrand[j] = ((*i).brand)[j];
        }
        printf("%-5d|%-28s|%-28.2lf|%-28d|%-28s|%-28d|\n", num++, strname, (*i).price, (*i).quantity, strbrand, (*i).shelf_life);
    }
}

void del_space(char *a){
    int label = 1;
    char *i = a, *j = a;

    while(*i != '\0'){

        if(*i == '|'){
            *j++ = '\\';
        }
        else if(*i != ' ' && *i != '\t' && *i != '\n'){
            label = 0;
            *j++ = *i;
        }
        else if(*i == ' ' && label == 0){
            label = 1;
            *j++ = *i;
        }
        i++;
    }
    if(a){
        if(*a == ' '){
            a[0] = '\0';
        }

        else if(i[-1] == ' '){
            j[-1] = '\0';
        }
        else if(i[-1] != ' '){
            *j = '\0';
        }
    }
}

int is_int(const char *str){
    if (*str == '-' || *str == '+') str++;
    if (!*str) return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

int is_double(const char *str){
    char *end;
    double p = strtod(str, &end);
    p++;
    if(*end == 0){
        return 1;
    }
    return 0;
}

int create(char *buffer, product *elem){

    if(buffer == NULL || elem == NULL){
        return 1;
    }

    printf("Enter name\n");
    fgets(buffer, max_len_string, stdin);
    del_space(buffer);
    if(strlen(buffer) == 0){
        return -1;
    }
    else{
        strcpy((*elem).name, buffer);
    }

    printf("Enter price\n");
    fgets(buffer, max_len_string, stdin);
    del_space(buffer);
    if(strlen(buffer) == 0 || is_double(buffer) == 0){
        return -1;
    }
    else{
        (*elem).price = atof(buffer);
    }

    printf("Enter quantity\n");
    fgets(buffer, max_len_string, stdin);
    del_space(buffer);
    if(strlen(buffer) == 0 || is_int(buffer) == 0){
        return -1;
    }
    else{
        (*elem).quantity = atoi(buffer);
    }

    printf("Enter brand\n");
    fgets(buffer, max_len_string, stdin);
    del_space(buffer);
    if(strlen(buffer) == 0){
        return -1;
    }
    else{
        strcpy((*elem).brand, buffer);
    }

    printf("Enter shelf life\n");
    fgets(buffer, max_len_string, stdin);
    del_space(buffer);
    if(strlen(buffer) == 0 || is_int(buffer) == 0){
        return -1;
    }
    else{
        (*elem).shelf_life = atoi(buffer);
    }

    return 0;
}

void add(product **table, size_t *len, const product *elem){
    if(table == NULL || len == NULL || elem == NULL){
        return;
    }
    (*len)++;
    *table = realloc(*table, sizeof(product) * (*len));
    if(table == NULL){
        return;
    }
    else if(len != NULL && elem != NULL){
        strcpy((*table)[*len - 1].name, (*elem).name);
        (*table)[*len - 1].price = (*elem).price;
        (*table)[*len - 1].quantity = (*elem).quantity;
        strcpy((*table)[*len - 1].brand, (*elem).brand);
        (*table)[*len - 1].shelf_life = (*elem).shelf_life;
    }
}

void del(product **table, size_t *len, int p){
    if(table == NULL || len == NULL){
        return;
    }
    if(p == 0){
        *table = realloc(*table, 0);
        *len = 0;
        return;
    }
    *table = realloc(*table, sizeof(product) * (*len));
    if(*table == NULL){
        return;
    }
    for(product *i = *table, *j = *table, *e = *table + *len; i < e; i++){
        if(i - *table != p - 1){
            *j++ = *i;
        }
    }
    (*len)--;
}

void savefile(const product *table, const size_t *len, const char *filename){
    if(table == NULL || len == NULL || filename == NULL){
        return;
    }
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        return;
    }
    else{
        for(const product *i = table, *e = table + *len; i < e; i++){
            fprintf(file, "%s|%.2lf|%d|%s|%d|\n",
                   (*i).name, (*i).price, (*i).quantity, (*i).brand, (*i).shelf_life);
        }
    }
    fclose(file);
}

void loadfile(product **table, size_t *len, const char *filename){

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        return;
    }
    else{
        del(table, len, 0);
        product elem;
        char *p = malloc(max_len_string * 6);
        if(p == NULL){
            return;
        }
        char *j;
        char *p1 = malloc(max_len_string + 1);
        if(p1 == NULL){
            return;
        }
        char *i = p1;
        int n;
        while(!feof(file)){
            n = 0;
            fgets(p, max_len_string, file);
            j = p;
            while(*j != '\0'){
                if(*j != '|'){
                    *i++ = *j++;
                }
                else{
                    n++;
                    j++;
                    i = p1;
                    del_space(p1);
                    switch(n){
                        case 1:
                            strcpy(elem.name, p1);
                            break;
                        case 2:
                            elem.price = atof(p1);
                            break;
                        case 3:
                            elem.quantity = atoi(p1);
                            break;
                        case 4:
                            strcpy(elem.brand, p1);
                            break;
                        case 5:
                            elem.shelf_life = atoi(p1);
                            break;
                    }
                }
                i[1]='\0';
            }
            if(!feof(file)){
                add(table, len, &elem);
            }
        }
        free(p);
        free(p1);
    }
    fclose(file);
}

int sortquan(const product token1, const product token2){
    return token1.quantity - token2.quantity;
}

int sortlife(const product token1, const product token2){
    return token1.shelf_life - token2.shelf_life;
}

int sortprice(const product token1, const product token2){
    if(token1.price > token2.price) return 1;
    return -1;
}

int sortname(const product token1, const product token2){
    if(strcmp(token1.name, token2.name) > 0){
        return 1;
    }
    return -1;
}

int sortbrand(const product token1, const product token2){
    if(strcmp(token1.brand, token2.brand) > 0){
        return 1;
    }
    return -1;
}

void sort(product *table, size_t len, func f, int label){
    product ind3;
    size_t ind2;
    for(size_t ind1 = 0; ind1 < len; ind1++){
        ind2 = ind1;
        while(f(table[ind2], table[ind2 - 1]) * label < 0 && ind2 != 0){
            ind3 = table[ind2];
            table[ind2] = table[ind2 - 1];
            table[ind2 - 1] = ind3;
            ind2--;
        }
    }
}
