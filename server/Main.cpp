#include <iostream>
#include "../libs/cpp-httplib/httplib.h"

int main(void) {
    httplib::Server svr;
    int _PORT = 3000;

    svr.Get("/hi", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("{ \"key\": \"value\" }", "application/json");
    });

    svr.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
        svr.stop();
    });


    svr.listen("localhost", _PORT);
}