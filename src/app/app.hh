#pragma once
#include "iostream"
#include "cex.hpp"
#include "routes/routesManager.hh"
#include "tasks/tasks.hh"
#include "config.hh"

class App {
  public:
    cex::Server* m_server;
    routesManager* m_routesManager;
    TaskFileRetention* m_cleanUpTask;

    App();

    void run();
};
