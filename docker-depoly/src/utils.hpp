#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

std::string char_to_string(std::vector<char> vc) {
  std::string request;
  for (size_t i = 0; i < vc.size(); i++) {
    //std::cout << vc[i];
    request += vc[i];
  }
  //std::cout << std::endl;
  return request;
}

std::vector<char> recvChar(int client_fd) {
  int data_rec;
  int total = 0;
  int increment = 65535;
  int start = 0;
  std::vector<char> data_buff(increment, 0);
  while ((data_rec = recv(client_fd, &data_buff.data()[start], increment, 0)) > 0) {
    //There is data received
    total += data_rec;
    // std::cout << "size is " << data_buff.size() << std::endl;
    if (data_rec < increment) {
      //connection close
      break;
    }
    //need to do another recv
    data_buff.resize(data_buff.size() + increment);
    start += data_rec;
  }
  data_buff.resize(total);
<<<<<<< HEAD
  // std::cout << "data_buff is:" << total << std::endl;
=======
>>>>>>> 2aa5ff6cd66f23b4e3a2eb419712fee69462af5f
  return data_buff;
}

std::string recvAll(int client_fd) {
  std::vector<char> data_buff = recvChar(client_fd);
  if (data_buff.size() == 0) {
    return "";
  }
  std::string request;
  for (size_t i = 0; i < data_buff.size(); i++) {
    request += data_buff[i];
  }
  return request;
}

std::string parseTime(time_t time) {
  struct tm * timeinfo;
  timeinfo = localtime(&time);
  std::string time_str = asctime(timeinfo);
  return time_str;
}
