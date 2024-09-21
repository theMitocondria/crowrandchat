#include "Manager.h"

Manager::Manager() {
    std::cout << "Manager created" << std::endl;
}

Manager::~Manager() {
    std::cout << "Manager destroyed" << std::endl;
}

void Manager::add(Client* conn) {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for thread safety
    users.push(conn);

    // Check if we have at least two clients to create a room
    if (users.size() <= 1) return;

    // Create a room for two clients
    Client* conn1 = users.front();
    users.pop();
    Client* conn2 = users.front();
    users.pop();
    Room* room = new Room(conn1, conn2);

    // Add room to the map for both connections
    rooms[conn1->conn] = room;
    rooms[conn2->conn] = room;
}
