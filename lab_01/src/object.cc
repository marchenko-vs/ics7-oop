#include "object.h"
#include "errors.h"
#include "points.h"

object &object_init(void)
{
    static object_t object;

    object.edges.array = NULL;
    object.edges.size = 0;

    object.points.array = NULL;
    object.points.size = 0;

    return object;
}

static error_t object_load_tmp(object_t &temp_figure, FILE *stream)
{
    error_t return_code = SUCCESS;

    return_code = points_handle(temp_figure.points, stream);

    if (return_code == SUCCESS)
    {
        return_code = edges_handle(temp_figure.edges, stream);

        if (return_code != SUCCESS)
            points_free(temp_figure.points);
    }

    return return_code;
}

error_t object_load(object_t &figure, const char *name)
{
    error_t return_code = SUCCESS;
    FILE *stream = NULL;

    if (!(stream = fopen(name, "r")))
        return_code = ERROR_FILE_OPEN;

    if (return_code == SUCCESS)
    {
        object_t temp_figure;
        return_code = object_load_tmp(temp_figure, stream);
        fclose(stream);

        if (!return_code)
            figure = temp_figure;
    }

    return return_code;
}

error_t object_draw(const object_t &figure, const canvas_t &canvas)
{
    error_t return_code = SUCCESS;

    if (figure.edges.array == NULL || figure.points.array == NULL)
        return_code = ERROR_MEMORY_TROUBLE;

    if (return_code == SUCCESS)
    {
        canvas_clear_all(canvas);
        canvas_draw_edges(figure.edges, figure.points, canvas);
    }

    return return_code;
}

static void points_transfer(points_array_t &points,
                            const transfer_t &coefficients)
{
    for (size_t i = 0; i < points.size; i++)
        points_transfer(points.array[i], coefficients);
}

error_t object_transfer(object_t &figure, const transfer_t &coefficients)
{
    error_t return_code = SUCCESS;

    if (figure.points.array == NULL || figure.edges.array == NULL)
        return_code = ERROR_MEMORY_TROUBLE;

    if (return_code == SUCCESS)
        points_transfer(figure.points, coefficients);

    return return_code;
}

static void points_scale(points_array_t &points, const scale_t &coefficients)
{
    for (size_t i = 0; i < points.size; i++)
        point_scale(points.array[i], coefficients);
}

error_t object_scale(object_t &figure, const scale_t &coeffs)
{
    error_t return_code = SUCCESS;

    if (figure.points.array == NULL || figure.edges.array == NULL)
        return_code = ERROR_MEMORY_TROUBLE;

    if (return_code == SUCCESS)
        points_scale(figure.points, coeffs);

    return return_code;
}

static void object_rotate(points_array_t &points, const rotate_t &coeffs)
{
    for (size_t i = 0; i < points.size; i++)
    {
        point_x_rotate(points.array[i], coeffs.phi_x);
        point_y_rotate(points.array[i], coeffs.phi_y);
        point_z_rotate(points.array[i], coeffs.phi_z);
    }
}

error_t object_rotate(object_t &figure, const rotate_t &coeffs)
{
    error_t return_code = SUCCESS;

    if (figure.points.array == NULL || figure.edges.array == NULL)
        return_code= ERROR_MEMORY_TROUBLE;

    if (return_code == SUCCESS)
        object_rotate(figure.points, coeffs);

    return return_code;
}

void object_free(const object_t &figure)
{
    points_free(figure.points);
    edges_free(figure.edges);
}
