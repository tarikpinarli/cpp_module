#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

bool replace_file(const std::string& filename,
                  const std::string& s1,
                  const std::string& s2,
                  std::string& err);

#endif
