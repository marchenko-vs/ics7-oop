#include <cstdio>

#include "edges.h"
#include "points.h"

static error_t edges_get_amount(edges_array_t &edges, FILE *stream)
{
    error_t return_code = SUCCESS;

    if ((fscanf(stream, "%zu", &edges.size)) != 1)
        return_code = ERROR_FILE_READING;

    if (return_code == SUCCESS && edges.size < 1)
        return_code = ERROR_EDGES_ARRAY_SIZE;

    return return_code;
}

static error_t edges_scan(edge_t *const array, const int &size, FILE *stream)
{
    error_t return_code = SUCCESS;

    for (int i = 0; return_code == SUCCESS && i < size; i++)
        if ((fscanf(stream, "%d %d", &array[i].point_1,
                    &array[i].point_2)) != 2)
            return_code = ERROR_FILE_READING;

    return return_code;
}

static error_t edges_allocate(edges_array_t &edges)
{
    error_t return_code = SUCCESS;

    edge_t *temp_array = (edge_t *)malloc(edges.size * sizeof(edge_t));

    if (temp_array == NULL)
        return_code = ERROR_MEMORY_ALLOCATION;

    edges.array = temp_array;

    return return_code;
}

error_t edges_allocate(points_array_t &points)
{
    error_t return_code = SUCCESS;

    point_t *temp_array = (point_t *)malloc(points.size * sizeof(point_t));

    if (temp_array == NULL)
        return_code = ERROR_MEMORY_ALLOCATION;

    points.array = temp_array;

    return return_code;
}

error_t edges_handle(edges_array_t &edges, FILE *stream)
{
     error_t return_code = SUCCESS;

     return_code = edges_get_amount(edges, stream);

     if (return_code == SUCCESS)
         return_code = edges_allocate(edges);

     if (return_code == SUCCESS)
         return_code = edges_scan(edges.array, edges.size, stream);

     if (return_code != SUCCESS)
        edges_free(edges);

     return return_code;
}

void edges_free(const edges_array_t &edges)
{
    if (edges.array)
        free(edges.array);
}
