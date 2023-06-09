#include "shapesfunc.h"

#include <ctype.h>

Shapes_Status createRectangle(double length, double width, double *area,
                              double *perimeter) {
    if (length <= 0 || width <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = length * width;
    *perimeter = 2 * (length + width);
    return Shapes_Status_Ok;
}

Shapes_Status createTriangle(double base, double height, double *area,
                             double *perimeter) {
    if (base <= 0 || height <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = base * height / 2;
    *perimeter = 2 * (base + height);
    return Shapes_Status_Ok;
}

Shapes_Status createCircle(double radius, double *area, double *perimeter) {
    const double PI = 3.14;
    if (radius <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = PI * radius * radius;
    *perimeter = 2 * PI * radius;
    return Shapes_Status_Ok;
}

Shapes_Status createParallelogram(double base, double height, double side,
                                  double *area, double *perimeter) {
    if (base <= 0 || height <= 0 || side <= 0) {
        return Shapes_Status_InvalidInput;
    }
    *area = base * height;
    *perimeter = 2 * (base + side);
    return Shapes_Status_Ok;
}
