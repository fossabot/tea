#include "assets.h"

#include <fstream>
#include <iostream>

namespace Tea {
    Asset::Asset(std::vector<uint8_t> data): data(data) {}
    std::vector<uint8_t>& Asset::get_data() { return *&this->data; }

    AssetManager::AssetManager() {}
    AssetManager::~AssetManager() {}

    Asset* AssetManager::find_asset(std::string name) {
        // Check open file cache
        auto existing_file = this->loaded_assets.find(name);
        if (existing_file != this->loaded_assets.end()) return &existing_file->second;

        std::ifstream stream;
        stream.open(name, std::ifstream::in | std::ifstream::binary);

        // Check if file exists
        if (!stream.is_open()) return nullptr;

        std::vector<uint8_t> contents((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

        auto inserted_asset = this->loaded_assets.emplace(name, contents);
        return &inserted_asset.first->second;
    }
}