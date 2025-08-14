#include "Replace.hpp"
#include <fstream>
#include <sstream>

static std::string replace_line(std::string line,
                               std::string s1,
                               std::string s2)
{
    std::string out;
    int pos = 0;

    while (true) {
        std::string::size_type hit = line.find(s1, pos);
        if (hit == std::string::npos) {
            out.append(line, pos, line.size() - pos);
            break;
        }
        out.append(line, pos, hit - pos);
        out.append(s2);
        pos = hit + s1.size();
    }
    return out;
}

bool replace_file(const std::string& filename,
                  const std::string& s1,
                  const std::string& s2,
                  std::string& err)
{
    if (filename.empty()) {
        err = "empty filename";
        return false;
    }
    if (s1.empty()) {
        err = "s1 must not be empty";
        return false;
    }

    std::ifstream in(filename.c_str());
    if(!in)
    {
        err = "file cannot open.";
        return false;
    }
    std::ofstream out((filename + ".replace").c_str());
    if (!out) {
        err = "cannot create output file";
        return false;
    }
    std::string line;
    bool first = true;
    while (std::getline(in, line)) {
        if (!first)
            out << '\n';
        first = false;
        out << replace_line(line, s1, s2);
    }
    return true;
}
