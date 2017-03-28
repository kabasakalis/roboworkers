#ifndef BACKOFFICE_H
#define BACKOFFICE_H

#include <string>
#include <functional>
#include <vector>

#include "request.h"

class Backoffice {
 public:
  Backoffice(std::string filename);
  void start(std::function<void(std::vector<Request>&)> callback);

  int workers_count() { return workers_count_; }

 private:
  std::vector<std::string> splitStr(std::string str, std::string delimiter);

  std::vector<std::string> lines_;
  int workers_count_;
};

#endif  // BACKOFFICE_H
