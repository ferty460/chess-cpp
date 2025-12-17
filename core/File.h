#ifndef CHESS_HORIZONTAL_H
#define CHESS_HORIZONTAL_H
#include <vector>


enum class File {
    A, B, C, D, E, F, G, H
};

inline std::vector<File> getAllFiles() {
    return { File::A, File::B, File::C, File::D,
             File::E, File::F, File::G, File::H };
}

inline char toChar(File file) {
    return 'A' + static_cast<int>(file);
}

inline File fromChar(char c) {
    return static_cast<File>(c - 'A');
}


#endif //CHESS_HORIZONTAL_H