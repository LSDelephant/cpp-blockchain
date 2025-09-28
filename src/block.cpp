#include "block.hpp"
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <chrono>


static std::string to_hex(const unsigned char* data, size_t len) {
std::ostringstream oss;
for (size_t i = 0; i < len; ++i)
oss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
return oss.str();
}


static std::string sha256(const std::string& input) {
unsigned char hash[SHA256_DIGEST_LENGTH];
SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
return to_hex(hash, SHA256_DIGEST_LENGTH);
}


Block::Block(uint64_t idx, uint64_t ts, std::string prev, std::string d)
: index(idx), timestamp(ts), prev_hash(std::move(prev)), nonce(0), data(std::move(d)) {
hash = calculate_hash();
}


std::string Block::calculate_hash() const {
std::ostringstream oss;
oss << index << timestamp << prev_hash << nonce << data;
return sha256(oss.str());
}
