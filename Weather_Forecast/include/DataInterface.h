#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H


class Data
{
    public:
    Data();
    char * GetResponse();
    static size_t write_chunk(void *data, size_t size, size_t nmemb, void *userdata);
    ~Data();

    private:
    char * Response;
    size_t size;
};

#endif