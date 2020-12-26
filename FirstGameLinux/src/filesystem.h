#ifndef FIRSTGAMELINUX_FILESYSTEM_H_
#define FIRSTGAMELINUX_FILESYSTEM_H_

#include <fstream>
#include <filesystem>
#include "firstgame/platform/filesystem.h"

class FileLinux final : public firstgame::platform::File {
   public:
    auto ReadToString() -> std::string override;
    void Close() override;
    auto Path() -> std::filesystem::path override { return fpath_; }
    ~FileLinux() override { Close(); }

   private:
    explicit FileLinux(std::fstream&& fstream, const char* filename);
    std::fstream fstream_;
    std::filesystem::path fpath_;
    friend class FileSystemLinux;
};

class FileSystemLinux final : public firstgame::platform::FileSystem {
   public:
    auto Open(const char* filename) -> std::unique_ptr<firstgame::platform::File> override;
    ~FileSystemLinux() override = default;
};

#endif  // FIRSTGAMELINUX_FILESYSTEM_H_