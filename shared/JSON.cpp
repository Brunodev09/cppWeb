#include "./JSON.h"

JSON::JSON() {};

JSON::~JSON() {};

Json::Value JSON::newJsonValue() {
    Json::Value json;
    return json;
};

bool JSON::parseString(std::string *JSON_STR, Json::Value *JSON, std::string *errors) {
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    bool r = reader->parse(JSON_STR->c_str(), JSON_STR->c_str() + JSON_STR->size(), JSON, errors);
    delete reader;
    return r;
}

std::string JSON::get(std::string key, Json::Value *json) {
    return json->get(key, "NOT_FOUND").asString();
}



