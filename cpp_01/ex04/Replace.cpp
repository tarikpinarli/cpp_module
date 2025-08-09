#include "Replace.hpp"
#include <fstream>
#include <sstream>

std::string replace_all(const std::string& text,
                        const std::string& s1,
                        const std::string& s2)
{
    if (s1.empty() || s1 == s2) return text;

    std::string out;
    out.reserve(text.size());
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;

    while ((pos = text.find(s1, prev)) != std::string::npos) {
        out.append(text, prev, pos - prev); // aradaki kısmı kopyala
        out.append(s2);                      // yerine s2 koy
        prev = pos + s1.size();              // aramaya kaldığın yerden devam
    }
    out.append(text, prev, std::string::npos); // kalan kuyruk
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
    if (!in) {
        err = "cannot open input file";
        return false;
    }

    std::ostringstream buf;
    buf << in.rdbuf();
    const std::string content = buf.str();

    const std::string replaced = replace_all(content, s1, s2);

    std::ofstream out((filename + ".replace").c_str());
    if (!out) { err = "cannot open output file"; return false; }

    out << replaced;
    return true;
}
