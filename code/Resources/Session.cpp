#include "Session.h"

void Session::display(std::string &content) {
  content = "display22y";
};

void Session::create(std::string &content) {
  auto r1 = client->request("GET", "/" + kApiVersion + "/oauth/access_token?client_id=" + kAppId + "&client_secret=" + kAppSecret + "&grant_type=client_credentials");

  stringstream tmp;
  tmp << r1->content.rdbuf();
  content = tmp.str();
};

void Session::update(std::string &content) {
  content = "update content";
};

void Session::remove(std::string &content) {
  content = "remove content";
};
