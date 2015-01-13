#ifndef SESSION_H_
#define SESSION_H_

#include "../ClientServer/server_http.hpp"

using namespace std;
using namespace SimpleWeb;

class Session : public Server<HTTP>::Resource
{
public:
    using Resource::Resource;

    virtual void display(std::string &content);
    virtual void create(std::string &content);
    virtual void update(std::string &content);
    virtual void remove(std::string &content);
};

#endif /* SESSION_H_ */
