#include <iostream>
#include "stdio.h"
#include <cex.hpp>

int main(int argc, char const *argv[]) {

  cex::Server app;

  std::cout << "leaf :) v0.0.1" << '\n';

  app.get("/debug", [](cex::Request* req, cex::Response* res, std::function<void()> next) {
   printf("Protocol: [%d], Method [%d], port [%d], host [%s], url [%s], path [%s], file [%s], user [%s], password [%s]\n",
     req->getProtocol(),
     req->getMethod(),
     req->getPort(),
     req->getHost(),
     req->getUrl(),
     req->getPath(),
     req->getFile(),
     req->properties.getString("basicUsername").c_str(),
     req->properties.getString("basicPassword").c_str());

     res->set("Content-Type", "text/html");
     res->end("leaf :) v0.0.1", 200);
  });

  app.listen("127.0.0.1", 12001, true);
  return 0;
}
