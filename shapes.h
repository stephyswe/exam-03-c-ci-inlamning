#ifndef __SHAPES_H_
#define __SHAPES_H_

#include <stdbool.h>

typedef enum {
    Shapes_Status_Ok,
    Shapes_Status_InvalidShape,
    Shapes_Status_InvalidInput,
} Shapes_Status;

typedef struct {
    double area;
    double perimeter;
} Shapes;

int shapesMenu();

#endif
