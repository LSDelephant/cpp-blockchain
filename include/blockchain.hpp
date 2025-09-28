#pragma once
#include "block.hpp"
#include <vector>
#include <mutex>


class Blockchain {
public:
Blockchain();
std::vector<Block> get_blocks();
Block add_block(const std::string& data);
Block last_block();
bool is_valid_chain(const std::vector<Block>& chain) const;
bool replace_chain(const std::vector<Block>& new_chain);


private:
std::vector<Block> chain_;
mutable std::mutex mu_;
static const int DIFFICULTY = 4; // number of leading zeros in hex
bool valid_proof(const std::string& hash) const;
void mine(Block& b) const;
};
