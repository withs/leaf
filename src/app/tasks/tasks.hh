#include "thread"
#include "config.hh"
#include <sys/stat.h>
#include <filesystem>
#include "chrono"
#include "../utils/utils.hh"

class TaskFileRetention {
  private:
    std::thread m_cleaUpThread;
  public:
    static int fileLifeTime(const std::string& fileName);
    int deleteFile(const std::string& fileName);
    TaskFileRetention();

    static void clean();
};
