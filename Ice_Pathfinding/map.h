#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <tuple>

#include "global_macros.h"


class Map
{   
    std::vector<std::tuple<char, int, int>> m_pathfinder_map;   // Contains: Identifier, X Coord, Y Coord

private:
    std::string read_file(std::filesystem::path file_path)
    {
        auto file_stream = std::ifstream{};

        file_stream.exceptions(std::ios::failbit | std::ios::badbit);
        file_stream.open(file_path, std::ios::binary | std::ios::in | std::ios::ate);
        
        auto size = file_stream.tellg();
        file_stream.seekg(0);

        auto contents = std::string{};
        contents.resize(size);
        file_stream.read(contents.data(), size);

        return contents;
    }

public:
    void get_map()
    {
        std::string file_name;
        std::string file_type = ".txt";


        std::cout << "Please enter the name of the file you wish to open: ";

        std::cin >> file_name;
        
        std::transform(file_name.begin(), file_name.end(), file_name.begin(), std::tolower);

        __NEW_LINE__

        auto file_data = read_file(file_name + file_type);

        //m_pathfinder_map.assign(std::begin(file_data), std::end(file_data)); // <--- FIX THIS

    };

    void output_map()
    {
        for (const auto &tuple : m_pathfinder_map)
        {
            std::cout << std::get<0>(tuple);
        }

        __NEW_LINE__
    }

};