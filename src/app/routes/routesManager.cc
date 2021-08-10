#include "routesManager.hh"

routesManager::routesManager(cex::Server* myApp) {
  m_app = myApp;
}

void routesManager::setupRoutes() {
  m_app->uploads("/", Upload::upload);
  m_app->post("/", Upload::POSTUpload);
  m_app->get("/", Root::GETRoot);
}
