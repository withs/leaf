#pragma once
#include "cex.hpp"
#include "sstream"

class Utils {

  public:

    static std::string methodToString(const cex::Method& httpMethod);

    static int find(const char* word, const char* in, const int startAt, int endAt);

    static std::string makeFileName(const int len);

    static std::string getFileExtension(std::vector<char>& uploadBuffer);

    static void dropBegin(std::vector<char>& uploadBuffer);

};
