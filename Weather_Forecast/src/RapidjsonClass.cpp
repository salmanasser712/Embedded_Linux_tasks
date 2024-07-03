#include "RapidjasonInterface.h"

Rapidjson::Rapidjson(char * Res): Response(Res)
{

}

void Rapidjson:: JsonParse()
{
    this->d.Parse(Response);
    std::string s = d["current"]["time"].GetString();

    bool date = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'T')
        {
            date = false;
            continue;
        }
        (date? this->Current_Date += s[i]: this->Current_Time += s[i]);
    }

    this->Current_Temperature = d["current"]["temperature_2m"].GetFloat();
}

std::string Rapidjson::GetDate()
{
    return this->Current_Date;
}

std::string Rapidjson:: GetTime()
{
    return this->Current_Time;
}

float Rapidjson:: GetTemperature()
{
    return this->Current_Temperature;
}
