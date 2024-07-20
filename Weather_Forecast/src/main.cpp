#include <iostream>
#include <fstream>
#include "CurlInterface.h"
#include "DataInterface.h"
#include "RapidjasonInterface.h"
#include <rapidjson/istreamwrapper.h>
#include "rapidjson/error/en.h"


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

    std::ifstream ifs("src/csvjson.json");

    if (!ifs.is_open()) {
        std::cerr << "Could not open file: test.json" << std::endl;
        return 1;
    }

    IStreamWrapper isw(ifs);
 
    Document doc;
    doc.ParseStream(isw);
  
    // Check for parse errors 
    if (doc.HasParseError()) { 
        std::cerr << "Error parsing JSON: " << GetParseError_En(doc.GetParseError()) << std::endl;
        std::cerr << "Error parsing JSON: "
             << doc.GetParseError() << std::endl; 
        return 1; 
    } 

    std::cout << doc[0]["city"].GetString() << std::endl;

    return 0;
}
