#ifndef _EDGES_H_
#define _EDGES_H_

#include <cstdio>
#include <cstdlib>

#include "errors.h"
#include "points.h"

typedef struct
{
    int point_1;
    int point_2;
} edge_t;

typedef struct
{
    edge_t *array;
    size_t size;
} edges_array_t;

error_t edges_allocate(points_array_t &points);
error_t edges_handle(edges_array_t &edges, FILE *stream);
void edges_free(const edges_array_t &edges);

#endif // _EDGES_H_
