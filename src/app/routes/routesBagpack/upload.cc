#include "upload.hh"

static std::unordered_map<std::string, std::vector<char>> table = {};

void Upload::upload(cex::Request* req, const char* data, size_t len) {
  std::string fileName;
  std::vector<char> buffer;

  if (!req->properties.has("uploadFileHandle")) {
   fileName = Utils::makeFileName(APP_FILE_NAME_LENGHT);
   table[fileName] = buffer;
   req->properties.set("uploadFileHandle", fileName);
  } else {
    fileName= req->properties.getString("uploadFileHandle");
    buffer = table[fileName];
  }


  if ( data && len && buffer.size() <= (APP_MAX_FILE_SIZE + len)) {
    size_t oldSize= buffer.size();
    buffer.resize(buffer.size() + len);
    std::memcpy(buffer.data() + oldSize, data, len);
    table[fileName] = buffer;
  }
}


void Upload::POSTUpload(cex::Request* req, cex::Response* res, std::function<void()> next) {
  if (req->properties.has("uploadFileHandle")){

    std::string fileName = req->properties.getString("uploadFileHandle");

    std::vector<char> buffer = table[fileName];

    int size = buffer.size();

    if ( buffer.size() >= APP_MAX_FILE_SIZE ) {
      std::cout << "file=" << fileName << " -> too large" << '\n';
      std::string resp = "too large";
      res->set("Content-Type", "text/plain");
      res->end(resp.c_str(), resp.size(), 200);
      return;
    }

    std::stringstream finalName;
    finalName << APP_FILE_PATH.string() << "/" << fileName << Utils::getFileExtension(buffer);
    Utils::dropBegin(buffer);
    std::ofstream outFile;
    outFile.open(finalName.str().c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
    outFile.write(buffer.data(), size);
    outFile.close();

    std::cout << "file=" << finalName.str() << " -> saved " << '\n';

    res->set("Content-Type", "text/plain");
    res->end(finalName.str().c_str(), finalName.str().size(), 200);

    table.erase(fileName);
    req->properties.remove("uploadFileHandle");
   }

   res->end(200);
}
