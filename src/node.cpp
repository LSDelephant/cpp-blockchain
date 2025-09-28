#include "blockchain.hpp"
#include "httplib.h" // third_party/httplib.h
#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>
#include <vector>


using json = nlohmann::json;


int main_server(int port) {
Blockchain chain;
httplib::Server svr;


svr.Get("/blocks", [&](const httplib::Request&, httplib::Response& res){
auto blocks = chain.get_blocks();
json j = json::array();
for (const auto& b : blocks) {
j.push_back({
{"index", b.index},
{"timestamp", b.timestamp},
{"prev_hash", b.prev_hash},
{"hash", b.hash},
{"nonce", b.nonce},
{"data", b.data}
});
}
res.set_content(j.dump(), "application/json");
});


svr.Post("/mine", [&](const httplib::Request& req, httplib::Response& res){
try {
auto j = json::parse(req.body);
std::string data = j.value("data", "");
auto newb = chain.add_block(data);
json jb = {
{"index", newb.index},
}
