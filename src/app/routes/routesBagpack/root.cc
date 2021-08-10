#include "root.hh"

void Root::GETRoot(cex::Request* req, cex::Response* res, std::function<void()> next) {

  std::string file = std::string(req->getFile());

  if ( file != std::string("")) {
    Root::GETFile(file, req, res);
  }

  std::string resp = R"""(

<pre>
leaf v1.0


Send a post request from terminal with curl via :

    curl -F'data=@file.ext' air.local:12001/up

or via the upload form bellow :
</pre>

<form action="/" method="post" enctype="multipart/form-data">
  <input type="file" name="file">
  <button>upload</button>
</form>


  )""";

  res->set("Content-Type", "text/html");
  res->end(resp.c_str(), resp.size(), 200);
}

void Root::GETFile(std::string fileName, cex::Request* req, cex::Response* res) {
  std::stringstream finalName;
  finalName << APP_FILE_PATH.string() << "/" << fileName;

  std::ifstream file;
  file.open(finalName.str().c_str(), std::ios::in|std::ios::binary);
  if ( file.is_open() == 0) {
    std::string resp = "404";
    res->set("Content-Type", "text/plain");
    res->end(resp.c_str(), resp.size(), 404);
    return;
  }

  res->set("Content-Type", "application/octet-stream");
  res->stream(200, &file);
}
