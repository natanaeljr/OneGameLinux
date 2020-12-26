#include "filesystem.h"

#include <sstream>
#include <spdlog/spdlog.h>

using firstgame::platform::File;

/**************************************************************************************************/

FileLinux::FileLinux(std::fstream&& fstream, const char* filename)
    : fstream_(std::move(fstream)), fpath_(filename)
{
    SPDLOG_TRACE("File opened (\"{}\")", fpath_.c_str());
}

/**************************************************************************************************/

std::string FileLinux::ReadToString()
{
    std::string string;
    fstream_.seekg(0, std::ios::end);
    string.reserve(fstream_.tellg());
    fstream_.seekg(0, std::ios::beg);
    string.assign((std::istreambuf_iterator<char>(fstream_)), std::istreambuf_iterator<char>());
    SPDLOG_TRACE("File read to string, size: {}B ({})", string.length(), fpath_.c_str());
    return string;
}

/**************************************************************************************************/

void FileLinux::Close()
{
    SPDLOG_TRACE("File closed ({})", fpath_.c_str());
    fstream_.close();
}

/**************************************************************************************************/

std::unique_ptr<File> FileSystemLinux::Open(const char* filename)
{
    std::fstream fstream(filename);
    if (fstream) {
        return std::unique_ptr<FileLinux>(new FileLinux(std::move(fstream), filename));
    }
    SPDLOG_WARN("Failed to open file (\"{}\"): {}", filename, std::strerror(errno));
    return nullptr;
}
