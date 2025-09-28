#include "blockchain.hpp"
#include <cassert>
#include <iostream>


int main() {
Blockchain c;
auto b1 = c.add_block("tx1");
auto b2 = c.add_block("tx2");
auto blocks = c.get_blocks();
assert(blocks.size() == 3);
assert(blocks[1].index == 1);
assert(blocks[2].index == 2);
std::cout << "All tests passed\n";
return 0;
}
