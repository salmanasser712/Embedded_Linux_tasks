#ifndef RAPIDJSONINTERFACE_H
#define RAPIDJSONINTERFACE_H

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

class Rapidjson
{
    public:
    Rapidjson(char * Res);
    void JsonParse();
    std::string GetDate();
    std::string GetTime();
    float GetTemperature();

    private:
    Document d;
    char * Response;
    std::string Current_Date = "";
    std::string Current_Time = "";
    float Current_Temperature;
};


#endif