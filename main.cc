#include "iostream"

int main(int argc, char const *argv[]) {
  for ( int i = 0; i <= argc; i++ ) {
    std::cout << i << '\n';
    std::cout << argv[i] << '\n';
  }
  return 0;
}
