// Copyright Baklanov 2021
#ifndef INCLUDE_RESOURCE_H_
#define INCLUDE_RESOURCE_H_

#include <iostream>
#include <string>
#include <fstream>

class Resource {
 public:
    std::string readpath;
    std::string writepath;
    Resource(std::string readpath, std::string writepath) :
        readpath(readpath), writepath(writepath) {}
};

#endif  // INCLUDE_RESOURCE_H_
