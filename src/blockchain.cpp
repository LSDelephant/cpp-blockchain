#include "blockchain.hpp"
#include <chrono>
#include <sstream>


Blockchain::Blockchain() {
uint64_t ts = std::chrono::duration_cast<std::chrono::seconds>(
std::chrono::system_clock::now().time_since_epoch()).count();
Block genesis(0, ts, "0", "genesis");
chain_.push_back(genesis);
}


std::vector<Block> Blockchain::get_blocks() {
std::lock_guard<std::mutex> lock(mu_);
return chain_;
}


Block Blockchain::last_block() {
std::lock_guard<std::mutex> lock(mu_);
return chain_.back();
}


bool Blockchain::valid_proof(const std::string& hash) const {
// Check if hash starts with DIFFICULTY zeros
for (int i = 0; i < DIFFICULTY; ++i) {
if (hash[i] != '0') return false;
}
return true;
}


void Blockchain::mine(Block& b) const {
while (true) {
b.hash = b.calculate_hash();
if (valid_proof(b.hash)) break;
++b.nonce;
}
}
}
