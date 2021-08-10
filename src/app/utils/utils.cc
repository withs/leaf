#include "utils.hh"

int Utils::find(const char* word, const char* in, const int startAt = 0, int endAt = 0) {
  int begin;
  int verifyCount = 0;
  int withSize = std::strlen(in);
  // loop jusqu'a trouver une égalité du premier characthere de word et le char de l'index dans la loop
  for ( int i = startAt; i <= ((endAt == 0) ? withSize:endAt); i++ ) {
    // si le premier char de word et le char de l'index dans la loop sont égaux alors ont enrefistre l'index
    // qui correspond a la position du premier char de word
    if ( in[i] == word[0] ) {
      begin = i;
      // loop en testant l'egalité de tout word par raport a begin
      for ( int s = 0; s < std::strlen(word); s++ ) {
        // si un char est égal alors verifyCount++ et ont test si verifyCount est égal a la taille de word
        // si oui cela veut dire que nous avons trouvé la position de word sinon on repart pour un tour
        if ( in[i + s] == word[s]) {
          verifyCount++;
          if ( verifyCount == std::strlen(word) )
            return begin;
        }
      }
      verifyCount = 0;
    }
  }
  return -1;
}

std::string Utils::methodToString(const cex::Method& httpMethod) {
  switch (httpMethod) {
    case cex::methodGET:
      return std::string("GET");
    case cex::methodHEAD:
      return std::string("HEAD");
    case cex::methodPOST:
      return std::string("POST");
    case cex::methodPUT:
      return std::string("PUT");
    case cex::methodDELETE:
      return std::string("DELETE");
    case cex::methodOPTIONS:
      return std::string("OPTIONS");
    case cex::methodTRACE:
      return std::string("TRACE");
    case cex::methodCONNECT:
      return std::string("CONNECT");
    case cex::methodPATCH:
      return std::string("PATCH");
    case cex::methodMKCOL:
      return std::string("MKCOL");
    case cex::methodCOPY:
      return std::string("COPY");
    case cex::methodMOVE:
      return std::string("MOVE");
    case cex::methodPROPFIND:
      return std::string("PROFIND");
    case cex::methodPROPPATCH:
      return std::string("PROPATCH");
    case cex::methodLOCK:
      return std::string("LOCK");
    case cex::methodUNLOCK:
      return std::string("UNLOCK");
    default:
      return std::string("NA");
  }
}

std::string Utils::makeFileName(const int len) {
  const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  const std::string alphanum = "1234567890";

  std::stringstream filename;
  std::srand(std::time(nullptr));

  for (int i = 0; i <= len; i++) {
    filename << (std::rand()/((RAND_MAX + 1u)/2) ? alphabet[std::rand()/((RAND_MAX + 1u)/alphabet.length())] : alphanum[std::rand()/((RAND_MAX + 1u)/alphanum.length())]);
  }

  return filename.str();
}

std::string Utils::getFileExtension(std::vector<char>& uploadBuffer) {
  int fileNameEqualPos = Utils::find("filename=", uploadBuffer.data());
  int endQuotePos = Utils::find("\"", uploadBuffer.data(), (fileNameEqualPos + 10));
  int dotPos = Utils::find(".", uploadBuffer.data(), fileNameEqualPos, endQuotePos);
  if ( dotPos == -1 )
    return std::string("");
  int extLen = ( endQuotePos - dotPos );

  std::stringstream ext;

  for ( int i = 0; i < extLen; i++ ) {
    ext << uploadBuffer.data()[dotPos + i];
  }

  return ext.str();
}

void Utils::dropBegin(std::vector<char>& uploadBuffer) {

  int typePos = Utils::find("Content-Type:", uploadBuffer.data());
  int documentStart = Utils::find("\n", uploadBuffer.data(), typePos) + 3;

  for (int i = 0; i < documentStart; ++i) {
    uploadBuffer.erase(uploadBuffer.begin());
  }

}
