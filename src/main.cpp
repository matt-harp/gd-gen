#include "generator/generator.h"

int main(const int argc, char *argv[]) {
    std::filesystem::path src_path;
    std::filesystem::path dest_path;

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << "src_path dest_path" << '\n';
        return 1;
    }
    src_path = argv[1];
    dest_path = argv[2];

    src_path = src_path.lexically_normal();
    dest_path = dest_path.lexically_normal();

    // Removes trailing slashes
    src_path = src_path.filename().empty() ? src_path.parent_path() : src_path;
    dest_path = dest_path.filename().empty() ? dest_path.parent_path() : dest_path;

    if (!std::filesystem::exists(src_path)) {
        std::cerr << "Error: Path does not exist: " << src_path << '\n';
        return 1;
    }

    if (!std::filesystem::is_directory(src_path)) {
        std::cerr << "Error: Path is not a directory: " << src_path << '\n';
        return 1;
    }

    Generator generator;
    generator.generate(src_path, dest_path);
    return 0;
}
