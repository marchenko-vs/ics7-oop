#ifndef _ERRORS_H_
#define _ERRORS_H_

typedef enum
{
    SUCCESS,
    ERROR_FILE_OPEN,
    ERROR_MEMORY_ALLOCATION,
    ERROR_FILE_READING,
    ERROR_EDGES_ARRAY_SIZE,
    ERROR_POINTS_ARRAY_SIZE,
    ERROR_MEMORY_TROUBLE,
    ERROR_UNKNOWN_REQUEST
} error_t;

void error_handle(const error_t &code);

#endif // _ERRORS_H_
