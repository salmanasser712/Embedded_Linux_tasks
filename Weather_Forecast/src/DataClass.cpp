#include <string>
#include <cstring>
#include "DataInterface.h"


Data::Data()
{
    this->Response = (char * )malloc(1);
    this->size = 0;
}

char * Data:: GetResponse()
{
    return this->Response;
}

size_t Data:: write_chunk(void *data, size_t size, size_t nmemb, void *userdata)
{   
    size_t real_size = size * nmemb;

    Data * data_instance = (Data *)userdata;

    char *ptr = (char * )realloc(data_instance->Response, data_instance->size + real_size + 1);
    if(ptr == NULL)
    {
        return -1;
    }

    data_instance->Response = ptr;

    memcpy(&(data_instance->Response[data_instance->size]), data, real_size);
    data_instance->size += real_size;
    data_instance->Response[data_instance->size] = 0;


    return real_size;
}


