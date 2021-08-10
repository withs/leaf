#pragma once
#include "cex.hpp"
#include "iostream"
#include "fstream"
#include "config.hh"
#include "sstream"

class Root {
public:
  static void GETRoot(cex::Request* req, cex::Response* res, std::function<void()> next);
  static void GETFile(std::string fileName, cex::Request* req, cex::Response* res);
};
