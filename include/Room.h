#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "crow.h"
#include "Client.h"

class Room {
private:
    Client *conn1;
    Client *conn2;

public:
    // Constructor
    Room(Client *c1, Client *c2);

    // Method to send a message to the other client
    void send(crow::websocket::connection* c1, const std::string& text);

    // Destructor
    ~Room();
};

#endif // ROOM_H