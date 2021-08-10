#include <iostream>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  struct stat fileInfo;

  stat("test_image.jpg", &fileInfo);
  std::cout << "sss" << '\n';
  std::cout << std::time(nullptr) << '\n';
  std::cout << "Created       : " << (int)fileInfo.st_ctime;
  std::cout << "lifetime       : " << std::time(nullptr) - (long)fileInfo.st_ctime;
  return 0;
}
