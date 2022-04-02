#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "points.h"
#include "edges.h"
#include "canvas.h"
#include "errors.h"

struct object
{
    points_array_t points;
    edges_array_t edges;
};

typedef struct object object_t;

object &object_init(void);
error_t object_load(object_t &object, const char * name);
error_t object_draw(const object_t &object, const canvas_t &canvas);
error_t object_transfer(object_t &object, const transfer_t &coefficients);
error_t object_scale(object_t &object, const scale_t &coefficients);
error_t object_rotate(object_t &object, const rotate_t &coefficients);
void object_free(const object_t &object);

#endif // _OBJECT_H_
