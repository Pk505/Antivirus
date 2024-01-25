//
// Created by Alexander on 26.01.2024.
//

#include "ScannerFunctions.h"
#include <filesystem>
#include <iostream>


void ScanDirectory(const std::string& path) {
    try {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if ( std::filesystem::is_regular_file(entry.path())) {
                std::cout << "File: " << entry.path().string() << std::endl;
            } else if ( std::filesystem::is_directory(entry.path())) {
                std::cout << "Directory: " << entry.path().string() << std::endl;
                ScanDirectory(entry.path().string()); // Рекурсивный вызов для сканирования подкаталогов
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
