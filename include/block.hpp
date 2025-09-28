#pragma once
#include <string>
#include <cstdint>


struct Block {
uint64_t index;
uint64_t timestamp;
std::string prev_hash;
std::string hash;
uint64_t nonce;
std::string data;


Block() = default;
Block(uint64_t idx, uint64_t ts, std::string prev, std::string d);
std::string calculate_hash() const;
};
