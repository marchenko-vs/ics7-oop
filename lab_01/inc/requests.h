#ifndef _REQUESTS_H_
#define _REQUESTS_H_

#include "errors.h"
#include "object.h"

typedef enum
{
    LOAD,
    SCALE,
    ROTATE,
    TRANSFER,
    DRAW,
    QUIT
} request_enum_t;

typedef struct
{
    int option;
    union
    {
        const char *file_name;
        transfer_t transfer;
        scale_t scale;
        rotate_t rotate;
        canvas_t canvas;
    };
} request_t;

error_t request_handle(const request_t &code);

#endif // _REQUESTS_H_
