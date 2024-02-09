//
// Created by Alexander on 26.01.2024.
//

#include "ScannerFunctions.h"
#include <filesystem>
#include <iostream>


std::string ScanDirectory(const std::string& path, const AVBase& Base) {
    std::string result;
    try {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if ( std::filesystem::is_regular_file(entry.path())) {
                std::string currentResult = Base.isFileInfected(entry.path().string());
                if (currentResult != ""){
                    result += currentResult + "\n";
                }
            } else if ( std::filesystem::is_directory(entry.path())) {
                result += ScanDirectory(entry.path().string(), Base); // Recurse call to scan underdirectory
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}
