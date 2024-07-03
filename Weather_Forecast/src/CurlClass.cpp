#include <curl/curl.h>
#include <string>
#include <iostream>
#include "DataInterface.h"
#include "CurlInterface.h"


Curl::Curl(std::string latitude, std::string longitude, Data * data)
{
    static std::string temp = "https://api.open-meteo.com/v1/forecast?latitude=" + latitude + "&longitude=" + longitude + "&current=temperature_2m,wind_speed_10m&timezone=Africa%2FCairo"; 
    this->weatherAPI = temp.data();
    this->data = data;
}

Curl_Status Curl::Curl_Init()
{
    this->curl = curl_easy_init();

    if(this->curl == NULL)
    {
        printf("HTTP request failed\n");
        return CURLNOK;
    }

    return CURLOK;
}

Curl_Status Curl:: Curl_Setup()
{
    if(this->data == NULL)
    {
        printf("data null\n");
        return CURLNOK;
    }
    curl_easy_setopt(this->curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(this->curl, CURLOPT_URL, weatherAPI);
    curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, Data::write_chunk);
    curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, (void *) (this->data));

    return CURLOK;
}

Curl_Status Curl::Curl_Preform()
{
    this->result = curl_easy_perform(this->curl);

    if(this->result != CURLE_OK)
    {
        printf("Error: %s\n", curl_easy_strerror(this->result));
        return CURLNOK;
    }

    return CURLOK;
}

Curl::~Curl()
{
    curl_easy_cleanup(this->curl);
}
