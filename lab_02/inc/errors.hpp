#ifndef _ERRORS_HPP_
#define _ERRORS_HPP_

#include <exception>
#include <string>

class BaseError : public std::exception
{
protected:
    std::string error_info;

public:
    BaseError(std::string file_name, std::string class_name, int line_number,
              const char *time, std::string info = "Error.")
    {
        error_info = "File name: " + file_name + "\nClass: " + class_name +
                "\nline_number#: " + std::to_string(line_number) +
                "\nTime: " + time + "Info: " + info;
    }
    virtual const char* what() const noexcept override
    {
        return error_info.c_str();
    }
};

class MemoryError : public BaseError
{
public:
    MemoryError(std::string file_name, std::string class_name, int line_number,
                const char *time, std::string info = "Memory error.") :
    BaseError(file_name, class_name, line_number, time, info) {};
    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

class EmptyVectorError : public BaseError
{
public:
    EmptyVectorError(std::string file_name, std::string class_name,
                     int line_number, const char *time,
                     std::string info = "Trying to use empty vector.") :
    BaseError(file_name, class_name, line_number, time, info) {};

    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

class IndexError : public BaseError
{
public:
    IndexError(std::string file_name, std::string class_name,
               int line_number, const char *time,
               std::string info = "Index out of range.") :
    BaseError(file_name, class_name, line_number, time, info) {};
    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

class ZeroDivisionError : public BaseError
{
public:
    ZeroDivisionError(std::string file_name, std::string class_name,
                      int line_number, const char *time,
                      std::string info = "Zero division error.") :
    BaseError(file_name, class_name, line_number, time, info) {};
    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

class DeletedObjectError : public BaseError
{
public:
    DeletedObjectError(std::string file_name, std::string class_name,
                       int line_number, const char *time,
                       std::string info = "Working with deleted object.") :
    BaseError(file_name, class_name, line_number, time, info) {};

    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

#endif //_ERRORS_HPP_
