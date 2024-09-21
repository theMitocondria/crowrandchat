#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <mutex>
#include <queue>
#include <unordered_map>
#include "Client.h" // Include Client header
#include "Room.h"   // Include Room header

class Manager {
private:
    std::mutex mtx;  // Mutex for thread safety
    std::queue<Client*> users;  // Queue to hold clients

public:
    std::unordered_map<crow::websocket::connection*, Room*> rooms; // Map to hold rooms

    // Constructor
    Manager();

    // Destructor
    ~Manager();

    // Add a new client connection
    void add(Client* conn);
};

#endif // MANAGER_H
