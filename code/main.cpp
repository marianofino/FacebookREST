#include "ClientServer/server_http.hpp"

#include "Resources/Session.cpp"

//Added for the json-example
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

//Added for the default_resource example
#include<fstream>

using namespace std;
using namespace SimpleWeb;
//Added for the json-example:
using namespace boost::property_tree;

int main() {
    //HTTP-server at port 8080 using 4 threads
    Server<HTTP> server(8080, 4);

    // Link paths to objects (REST resources)
    server.route("^/session/?$", new Session()); // Login using oAuth

    thread server_thread([&server](){
        //Start server
        server.start();
    });

    server_thread.join();
    
    return 0;
}
