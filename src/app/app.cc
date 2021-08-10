#include "app.hh"


App::App() {

  m_server = new cex::Server;
  m_routesManager = new routesManager(m_server);
  m_routesManager->setupRoutes();
  m_cleanUpTask = new TaskFileRetention();
}


void App::run() {
  std::cout << "leaf (" << VERSION << ") listenings http://" << APP_HOST << ":" << APP_PORT <<'\n';
  m_server->listen(APP_HOST.c_str(), APP_PORT, true);

  delete m_server;
  delete m_routesManager;
  delete m_cleanUpTask;

}
