#pragma once
#include "cex.hpp"
#include "iostream"
#include "fstream"
#include "../../utils/utils.hh"
#include "config.hh"

class Upload {
  public:
    static void upload(cex::Request* req, const char* data, size_t len);
    static void POSTUpload(cex::Request* req, cex::Response* res, std::function<void()> next);
};
