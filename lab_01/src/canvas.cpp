#include <cstdio>

#include "canvas.h"

static void canvas_draw_edge(double x_0, double y_0, double x_1, double y_1,
                             const canvas_t &canvas)
{
    canvas.scene->addLine(x_0, y_0, x_1, y_1);
}

static void canvas_draw_in_center(const edge_t &edge,
                      const point_t *const points, const canvas_t &canvas)
{
    point_t point_1 = points[edge.point_1];
    point_t point_2 = points[edge.point_2];

    canvas_draw_edge(
        point_1.x + canvas.width / 2,
        point_1.y + canvas.height / 2,
        point_2.x + canvas.width / 2,
        point_2.y + canvas.height / 2,
        canvas
   );
}

void canvas_draw_edges(const edges_array_t &edges,
                const points_array_t &points, const canvas_t &canvas)
{
    for (size_t i = 0; i < edges.size; i++)
        canvas_draw_in_center(edges.array[i], points.array, canvas);
}

void canvas_clear_all(const canvas_t &canvas)
{
    canvas.scene->clear();
}
