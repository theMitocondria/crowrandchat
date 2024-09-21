#include "Client.h"
#include <string>

Client::Client(crow::websocket::connection* c ){
    conn = c ;
    CROW_LOG_INFO << "CLient created :" ;
}

Client::~Client(){
    CROW_LOG_INFO << "CLient destroyed :" ;
}

void Client::send(const std::string& text){
    conn->send_text(text);
}