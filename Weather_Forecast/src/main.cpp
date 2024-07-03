#include <iostream>
#include "CurlInterface.h"
#include "DataInterface.h"
#include "RapidjasonInterface.h"


int main()
{

    Data * data = new Data();
    Curl curlobj("29.9964", "31.295", data);
    curlobj.Curl_Init();
    curlobj.Curl_Setup();
    curlobj.Curl_Preform();

    Rapidjson json(data->GetResponse());
    json.JsonParse();
    std::cout << json.GetTemperature() << std::endl;


    return 0;
}
