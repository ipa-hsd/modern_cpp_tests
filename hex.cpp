#include <iostream>
#include <boost/lexical_cast.hpp>

bool is_packet_type(std::string type, std::string str) {
  if(str[0] == type[0] && str[1] == type[1])
    return true;
  return false;
}


int main(int argc, char* argv[]){
  std::string type = "C";
  char str[] = {0x43, 0x31};
  char str1[] = {0x43, 0x00};

  std::cout << is_packet_type(type, str1) << std::endl;
  // std::cout << c.c_str() << " " << c[0] << " " << c[1] << std::endl;
  // std::cout << (c[0] == 0x43) << " " << (c[1] == 0x31) << std::endl;
  return 0;
}
