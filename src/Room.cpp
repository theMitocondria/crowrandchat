#include "Room.h"


Room::Room(Client *c1, Client *c2) {
    conn1 = c1;
    conn2 = c2;

    // Initialize the connection for both clients
    conn1->send("{\"type\" : \"INIT\" , \"user\" : \"\" }");
    conn2->send("{\"type\" : \"INIT\" , \"user\" : \"\" }");

    CROW_LOG_INFO << "New room of conn1, conn2 made";
}

void Room::send(crow::websocket::connection* c1, const std::string& text) {
    if (c1 == conn1->conn) {
        conn2->send(text);
    } else {
        conn1->send(text);
    }
}

Room::~Room() {
    CROW_LOG_INFO << "Room of conn1, conn2 disconnected";
}
