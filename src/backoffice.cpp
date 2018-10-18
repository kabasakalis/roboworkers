#include "backoffice.h"
#include "operation.h"

#include <fstream>
#include <exception>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <numeric>

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
//        std::vector<int> requests_per_batch = std::map(lines_, [](std::string line) { return (splitStr(line, " ").size() - 1) ;});
//        total_requests_count_ = std::accumulate(requests_per_batch.begin(), requests_per_batch.end(), 0);
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

                Operation::Type operation_type;
                switch (s[0]) {
                    case 'I':
                        operation_type = Operation::Type::INBOUND;
                        break;
                    case 'D':
                        operation_type = Operation::Type::DELIVER;
                        break;
                    default:
                        throw std::runtime_error("Malformed input file.");
                }

                Product::Type product_type;
                switch (s[1]) {
                    case 'S':
                        product_type = Product::Type::SOFA;
                        break;
                    case 'C':
                        product_type = Product::Type::CHAIR;
                        break;
                    default:
                        throw std::runtime_error("Malformed input file.");
                }

                requests.emplace_back(Request(product_type, operation_type));
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
