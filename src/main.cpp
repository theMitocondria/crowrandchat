#include "bits/stdc++.h"
#include "crow.h"

#include "Client.h"           // Include the Client class header
#include "Room.h"             // Include the Room class header
#include "Manager.h"          // Include the Manager class header

using namespace std; 

// class Client {

//     public :

//         crow::websocket::connection* conn ;
//         string username ;
//         string getUsername(){
//             return username ;
//         }
//         Client(string user ,  crow::websocket::connection* c ){
//             conn = c ;
//             username = user ;
//             CROW_LOG_INFO << "CLient created :"<<user ;
//         }

//         ~Client(){
//             CROW_LOG_INFO << "CLient destroyed :"<<username ;
//         }

//         void send(string text){
//             conn->send_text(text);
//         }

// };

// class Room {
//     private :
//         Client *conn1 , *conn2 ;

//     public :
//         Room( Client *c1 , Client *c2 ){
//             conn1 = c1 , conn2 = c2 ;
//             //json type : INIT , user : username
//             conn1->send(
//                 "{\"type\" : \"INIT\" , \"user\" : \""+conn2->getUsername()+"\" }"
//             );
//             conn2->send(
//                 "{\"type\" : \"INIT\" , \"user\" : \""+conn1->getUsername()+"\" }"
//             );


//             CROW_LOG_INFO << "New room of con1 , con2 made" ;
//         }

//         void send(crow::websocket::connection* c1,string text){
//             if(c1 == conn1->conn){
//                 conn2->send(text);
//             }else{
//                 conn1->send(text);
//             }
//         }

//         ~Room(){
//             CROW_LOG_INFO << "New room of con1 , con2 disconnected" ;
//         }
// };

// class Manager
// {
//     std::mutex mtx;
//     std::queue<Client*> users;
//     public:
//         std::unordered_map<crow::websocket::connection*, Room*> rooms;
//         Manager()
//         {
//             cout << "Manager created" << endl;
//         }
//         ~Manager()
//         {
//             cout << "Manager destroyed" << endl;
//         }
//         //jab new connection bna to usko queue me add krra h
//         void add(Client* conn)
//         {
//             std::lock_guard<std::mutex> _(mtx);
//             users.push(conn);
           
//             if(users.size()<=1) return;
//             else
//             {
//                 Client* conn1 = users.front();
//                 users.pop();
//                 Client* conn2 = users.front();
//                 users.pop();
//                 Room * room = new Room(conn1 , conn2 );
//                 rooms[conn1->conn] = room;
//                 rooms[conn2->conn] = room;
//             }
//         }
// };

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
        if(data == "ping"){
            conn.send_text("pong");
        }else{
            CROW_LOG_INFO << "message from frontend :" << data;
            auto room = manager->rooms.find(&conn);
            if(room != manager->rooms.end()){
                room->second->send(&conn, data);
            }
        }
    });


     CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
    

    app.port(8080).multithreaded().run();
}