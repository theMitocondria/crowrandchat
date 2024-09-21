#include "bits/stdc++.h"
#include "crow.h"

#include "Client.h"           // Include the Client class header
#include "Room.h"             // Include the Room class header
#include "Manager.h"          // Include the Manager class header

using namespace std; 

int main()
{
    crow::SimpleApp app;
    unordered_map<string, string> username;
    Manager *manager = new Manager();

    CROW_WEBSOCKET_ROUTE(app, "/ws")
   .onopen([&](crow::websocket::connection& conn){
        CROW_LOG_INFO << "new websocket connection from " << conn.get_remote_ip();
        CROW_LOG_ERROR<<"asdasdsadsa";
        
        manager->add(new Client(&conn));
    })
    .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary) {
        CROW_LOG_INFO << "message from frontend :" << data;
        
        auto room = manager->rooms.find(&conn);
        if(room != manager->rooms.end()){
            room->second->send(&conn, data);
        }
        
    });


     CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
    

    app.port(8080).multithreaded().run();
}