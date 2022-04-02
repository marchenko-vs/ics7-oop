#ifndef _POINTS_H_
#define _POINTS_H_

#include <cstdio>
#include <cstdlib>

#include "errors.h"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    point_t *array;
    size_t size;
} points_array_t;

typedef struct
{
    double dx;
    double dy;
    double dz;
} transfer_t;

typedef struct
{
    double k_x;
    double k_y;
    double k_z;
} scale_t;

typedef struct
{
    double phi_x;
    double phi_y;
    double phi_z;
} rotate_t;

error_t points_handle(points_array_t &points, FILE *stream);
void points_transfer(point_t &point, const transfer_t &coefficients);
void points_free(const points_array_t &points);

void point_scale(point_t &point, const scale_t &coefficients);
void point_x_rotate(point_t &point, const double &angle);
void point_y_rotate(point_t &point, const double &angle);
void point_z_rotate(point_t &point, const double &angle);

#endif // _POINTS_H_
