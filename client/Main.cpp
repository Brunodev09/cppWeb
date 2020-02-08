#include <iostream>
#include "../libs/cpp-httplib/httplib.h"
#include "../shared/JSON.cpp"
#include "../shared/JSON.h"

struct jsonResponse {
    std::string str;
    std::string errors;
    std::string result;
};

struct parser {
    jsonResponse* res;
    Json::Value jv;
    JSON* jparser;
};


parser parseJsonData(jsonResponse *j, std::string strigifiedObject) {
    
    JSON *jsonParser = new JSON();
    Json::Value json = jsonParser->newJsonValue();

    jsonParser->parseString(&strigifiedObject, &json, &j->errors);
    parser p = {j, json, jsonParser};

    if (j->errors.size() > 0) {
        std::cout << j->errors << std::endl;
        return p;
    }
    std::cout << j->result << std::endl;
    // delete jsonParser;
    
    return p;
}


int main(void) {
    httplib::Client cli("jsonplaceholder.typicode.com");
    httplib::Headers headers = {{"Content-Type", "application/json"}};
    parser p;
    jsonResponse j;

    auto res = cli.Get("/todos/1");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;
        try {
            
            p = parseJsonData(&j, res->body);
            std::cout << p.jparser->get("userId", &p.jv) << std::endl;
            std::cout << p.jparser->get("title", &p.jv) << std::endl;
            delete p.jparser;
        
        } catch(int e) {
            std::cout << e << std::endl;
            return e;
        }
    }

    return 0;
}

