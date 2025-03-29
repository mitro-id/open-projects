#include "grap.h"
#include "processing.h"

void enter(){
    printf("press ENTER to continue\n");
    char a = '\0';
    while(a != '\n'){
        a = getchar();
    }
    return;
}

double double_max(const double *array, size_t len){
    double count = array[0];
    for(const double *i = array + 1, *e = array + len; i < e; i++){
        if(count < *i){
            count = *i;
        }
    }
    return count;
}

void arrprice(const product *table, size_t len, double *array){
    for(size_t i = 0; i < len; i++){
        array[i] = table[i].price;
    }
}

void arrlife(const product *table, size_t len, double *array){
    for(size_t i = 0; i < len; i++){
        array[i] = (double)table[i].shelf_life;
    }
}

void arrquan(const product *table, size_t len, double *array){
    for(size_t i = 0; i < len; i++){
        array[i] = (double)table[i].quantity;
    }
}

void draw_graph(const product *table, size_t len, cnst f){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double array[len];
    f(table, len, array);

    int start[] = {5, getmaxy()};
    int color = 1, space = 5, width, scale_x, scale_y, step;
    double max = double_max(array, len);
    int window[] = {450, 450};
    int grid_y = start[1], grid_x = start[0];
    int size_label = 10;
    char buffer[21];

    double step1 = log10(max) - floor(log10(max));
    int pw = step1 < 0.5 ? floor(log10(max)) - 1 : floor(log10(max));
    step = pow(10, pw) * window[1] / max;

    setfillstyle(SOLID_FILL, 8);
    while(grid_x < window[0]){
        bar(grid_x, start[1], grid_x, 0);
        grid_x += step;
    }

    window[0] = grid_x - step;
    while(grid_y > 0){
        bar(start[0], grid_y, window[0], grid_y);
        grid_y -= step;
    }

    settextstyle(7, 5, 1);
    width = (window[0] - 10 * len) / len + 5;

    for(size_t i = 0; i < len; i++){
        setfillstyle(SOLID_FILL, color++%16);
        scale_x = start[0] + (width + space) * i;
        scale_y = array[i] * window[1] / max;
        bar(scale_x, start[1] - scale_y, scale_x + width, start[1]);

        bar(window[0] + size_label, (size_label + space) * i + size_label,
            window[0] + 2 * size_label, (size_label + space) * i + size_label * 2);
        setcolor(15);
        outtextxy(window[0] + 2 * size_label + space, (size_label + space) * i + size_label, table[i].name);
        sprintf(buffer, "%g", array[i]);
        outtextxy(getmaxx() - strlen(buffer) * 8, (size_label + space) * i + size_label, buffer);
    }

    sprintf(buffer, "%g", pow(10, pw));
    outtextxy(window[0] + space, getmaxy() - 10, "grid");
    outtextxy(window[0] + space + 32, getmaxy() - 10, buffer);

    enter();
    closegraph();
}

double sum(const double *array, size_t len){
    double count = 0;
    for(const double *i = array, *e = array + len; i < e; i++){
        count += *i;
    }
    return count;
}

void draw_pie(const product *table, size_t len, cnst f){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double array[len];
    f(table, len, array);

    int window[] = {440, 450};
    int size_label = 10, space = 10;
    char buffer[21];

    setfillstyle(SOLID_FILL, 8);
    bar(window[0], getmaxy(), window[0], 0);

    double s = sum(array, len);
    int angle = 0, sumangle = 0, color = 0;
    int center[] = {window[0] / 2, window[1] / 2};
    int r = window[1] > window[0] ? (window[0] - 10) / 2 : (window[1] - 10) / 2;

    for(size_t i = 0; i < len; i++){
        if(i == len - 1){
            angle = 360 - sumangle;
        }
        else{
            angle = 360 * array[i] / s;
            if(angle == 0){
                angle += 1;
            }
        }
        setfillstyle(0, color++%16);
        pieslice(center[0], center[1], sumangle, sumangle + angle, r);
        sumangle += angle;

        bar(window[0] + size_label, (size_label + space) * i + size_label,
            window[0] + 2 * size_label, (size_label + space) * i + size_label * 2);
        setcolor(15);
        outtextxy(window[0] + 2 * size_label + 5, (size_label + space) * i + size_label, table[i].name);
        sprintf(buffer, "%g", array[i]);
        outtextxy(getmaxx() - strlen(buffer) * 8, (size_label + space) * i + size_label, buffer);
    }

    enter();
    closegraph();
}
