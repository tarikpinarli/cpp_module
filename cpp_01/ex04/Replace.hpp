#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

std::string replace_all(const std::string& text,
                        const std::string& s1,
                        const std::string& s2);

bool replace_file(const std::string& filename,
                  const std::string& s1,
                  const std::string& s2,
                  std::string& err);

#endif
