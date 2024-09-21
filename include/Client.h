#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "crow.h"

class Client {
public:
    // Members
    crow::websocket::connection* conn;

    Client(crow::websocket::connection* c);
    ~Client();

    void send(const std::string& text);
};

#endif 
