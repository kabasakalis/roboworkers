#include "backoffice.h"

#include <fstream>
#include <exception>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

Backoffice::Backoffice(std::string filename) {
  std::string line;
  std::ifstream input(filename);
  if (!input.is_open()) {
    throw std::runtime_error("File not found!");
  }

  std::getline(input, line);
  workers_count_ = boost::lexical_cast<int>(line);

  while (std::getline(input, line)) {
    if (line == "") break;
    lines_.push_back(line);
  }
  input.close();
}

void Backoffice::start(std::function<void(std::vector<Request> &)> callback) {

  int wait_for = 0;

  for (std::string &line : lines_) {
    std::vector<Request> requests;
    std::vector<std::string> fields = splitStr(line, " ");
    wait_for = boost::lexical_cast<int>(fields.back());
    fields.pop_back();
    for (std::string &s : fields) {
      if (s.size() != 2) {
        std::cout << s << std::endl;
        throw std::runtime_error("Malformed input file.");
      }
      OperationType op =
          s[0] == 'I' ? OperationType::INBOUND : OperationType::DELIVER;
      ProductType pr =
          s[1] == 'S' ? ProductType::SOFA : ProductType::CHAIR;

      requests.push_back(Request(pr, op));
    }
    callback(requests);
    usleep(wait_for * 1000);
  }
}

std::vector<std::string> Backoffice::splitStr(std::string str,
                                              std::string delimiter) {
  std::vector<std::string> strs;
  boost::split(strs, str, boost::is_any_of(delimiter));
  return strs;
}
