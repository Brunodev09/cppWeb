#ifndef JSON_H
#define JSON_H

#include "../libs/jsoncpp/json/json.h"
#include "../libs/jsoncpp/jsoncpp.cpp"

class JSON {
    private:
    public:
        JSON();
        ~JSON();
        Json::Value newJsonValue();
        bool parseString(std::string *JSON_STR, Json::Value *JSON, std::string *errors);
        std::string get(std::string key, Json::Value *json);
};

#endif