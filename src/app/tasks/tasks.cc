#include "tasks.hh"

TaskFileRetention::TaskFileRetention() {
  m_cleaUpThread = std::thread(clean);
}

int TaskFileRetention::fileLifeTime(const std::string& fileName) {
  struct stat fileInfo;
  stat(fileName.c_str(), &fileInfo);
  return (int)fileInfo.st_ctime;
}

void TaskFileRetention::clean() {
  while ( 1 ) {

    std::cout << "Task=TaskFileRetention -> starting file clean up" << '\n';
    int deletedFilesCount = 0;
    for(auto const& dir_entry: std::filesystem::directory_iterator{APP_FILE_PATH}) {
        //std::cout << TaskFileRetention::fileLifeTime(dir_entry.path().string());
        //std::cout << " - " << std::time(nullptr) - TaskFileRetention::fileLifeTime(dir_entry.path().string()) << " " << dir_entry.path() << '\n';

        if ( std::time(nullptr) - TaskFileRetention::fileLifeTime(dir_entry.path().string()) >= APP_FILE_RENTENTION_MAX_TIME) {
          std::cout << "file=" << dir_entry.path().string() << " -> " << "deleted" << '\n';
          std::filesystem::remove(dir_entry);
          deletedFilesCount++;
        }
      }
    std::cout << "Task=TaskFileRetention -> done, deleted : " << deletedFilesCount << '\n';
    std::this_thread::sleep_for (std::chrono::seconds(APP_FILE_RENTENTION_LOOP_SLEEP));
  }
}
