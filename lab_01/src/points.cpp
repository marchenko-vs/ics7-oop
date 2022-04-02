#include <cstdio>
#include <cmath>

#include "points.h"
#include "errors.h"
#include "edges.h"

static error_t points_get_amount(points_array_t &points, FILE *stream)
{
    error_t return_code = SUCCESS;

    if ((fscanf(stream, "%zu", &points.size)) != 1)
        return_code = ERROR_FILE_READING;

    if (return_code == SUCCESS && points.size < 2)
        return_code = ERROR_POINTS_ARRAY_SIZE;

    return return_code;
}

static error_t points_scan(point_t *const array, const int size, FILE *stream)
{
    error_t return_code = SUCCESS;

    for (int i = 0; return_code == SUCCESS && i < size; i++)
        if ((fscanf(stream, "%lf %lf %lf", &array[i].x,
                    &array[i].y, &array[i].z)) != 3)
            return_code = ERROR_FILE_READING;

    return return_code;
}

void points_free(const points_array_t &points)
{
    if (points.array)
        free(points.array);
}

error_t points_handle(points_array_t &points, FILE *stream)
{
    error_t return_code = SUCCESS;

    return_code = points_get_amount(points, stream);

    if (return_code == SUCCESS)
        return_code = edges_allocate(points);

    if (return_code == SUCCESS)
    {
        return_code = points_scan(points.array, points.size, stream);

        if (return_code != SUCCESS)
            points_free(points);
    }

    return return_code;
}

void points_transfer(point_t &point, const transfer_t &coefficients)
{
    point.x += coefficients.dx;
    point.y += coefficients.dy;
    point.z += coefficients.dz;
}

void point_scale(point_t &point, const scale_t &coefficients)
{
    point.x *= coefficients.k_x;
    point.y *= coefficients.k_y;
    point.z *= coefficients.k_z;
}

static double degrees_to_radians(double (*function)(double),
                                 const double &angle)
{
    const double PI = 2 * acos(0.0);

    return (*function)(angle * PI / 180);
}

void point_x_rotate(point_t &point, const double &angle)
{
    double cos_radians = degrees_to_radians(cos, angle);
    double sin_radians = degrees_to_radians(sin, angle);
    double temp_y = point.y;

    point.y = point.y + cos_radians + point.z * sin_radians;
    point.z = -temp_y * sin_radians + point.z * cos_radians;
}

void point_y_rotate(point_t &point, const double &angle)
{
    double cos_radians = degrees_to_radians(cos, angle);
    double sin_radians = degrees_to_radians(sin, angle);
    double temp_x = point.x;

    point.x = point.x * cos_radians + point.z * sin_radians;
    point.z = -temp_x * sin_radians + point.z * cos_radians;
}

void point_z_rotate(point_t &point, const double &angle)
{
    double cos_radians = degrees_to_radians(cos, angle);
    double sin_radians = degrees_to_radians(sin, angle);
    double temp_x = point.x;

    point.x = point.x * cos_radians + point.y * sin_radians;
    point.y = -temp_x * sin_radians + point.y * cos_radians;
}
