#include "requests.h"
#include "errors.h"
#include "object.h"

error_t request_handle(const request_t &request_code)
{
    error_t return_code = SUCCESS;

    static object_t object = object_init();

    switch (request_code.option)
    {
        case LOAD:
            return_code = object_load(object, request_code.file_name);
            break;
        case SCALE:
            return_code = object_scale(object, request_code.scale);
            break;
        case ROTATE:
            return_code = object_rotate(object, request_code.rotate);
            break;
        case TRANSFER:
            return_code = object_transfer(object, request_code.transfer);
            break;
        case DRAW:
            return_code = object_draw(object, request_code.canvas);
            break;
        case QUIT:
            object_free(object);
            break;
        default:
            return_code = ERROR_UNKNOWN_REQUEST;
    }

    return return_code;
}
