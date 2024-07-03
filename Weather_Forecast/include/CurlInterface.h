#ifndef CURLINTERFACE_H
#define CURLINTERFACE_H

#include <curl/curl.h>
#include "DataInterface.h"

typedef enum 
{
    CURLNOK,
    CURLOK
}Curl_Status;

class Curl
{
    public:
    Curl(std::string latitude, std::string longitude, Data * data);
    Curl_Status Curl_Init();
    Curl_Status Curl_Setup();
    Curl_Status Curl_Preform();
    ~Curl();

    private:
    CURL *curl;
    CURLcode result;
    char *weatherAPI;
    Data * data;
};

#endif