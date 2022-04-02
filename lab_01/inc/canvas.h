#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <QGraphicsScene>

#include "points.h"
#include "edges.h"

typedef struct
{
    QGraphicsScene *scene;
    double width;
    double height;
} canvas_t;

void canvas_draw_edges(const edges_array_t &edges,
                const points_array_t &points, const canvas_t &canvas);
void canvas_clear_all(const canvas_t &canvas);

#endif // _CANVAS_H_
