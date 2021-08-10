#pragma once
#include "iostream"
#include <filesystem>

const std::string VERSION = "1.0-dev";

const std::string APP_HOST = "0.0.0.0";
const int APP_PORT= 12002;

const std::filesystem::path APP_FILE_PATH{"files"};
const int APP_FILE_NAME_LENGHT = 20;
const int APP_MAX_FILE_SIZE = 1000000; // bytes
const int APP_FILE_RENTENTION_MAX_TIME = 700 ; // seconds
const int APP_FILE_RENTENTION_LOOP_SLEEP = 60; // seconds
