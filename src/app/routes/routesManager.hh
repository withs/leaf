#pragma once
#include "cex.hpp"

#include "routesBagpack/root.hh"
#include "routesBagpack/upload.hh"


class routesManager {
private:
  cex::Server* m_app;
public:

  routesManager(cex::Server* myApp);

  void setupRoutes();
};
