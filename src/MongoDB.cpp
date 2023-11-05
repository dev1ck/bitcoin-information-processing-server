#include "MongoDB.hpp"

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

MongoDB::MongoDB(const std::string &uri) : client{mongocxx::uri{uri}}
{
  db = client["btds"];
}
json MongoDB::getProfile(const std::string &target)
{
  auto profiles = db["profiles"];
  auto result = profiles.find_one(make_document(kvp("target", target)));
  if (result)
    return json::parse(bsoncxx::to_json(*result));
  else
  {
    return json::object();
  }
}

std::optional<json> MongoDB::clusterFindById(const std::string &target)
{
  auto clusters = db["clusters"];
  auto oid = bsoncxx::types::b_oid{bsoncxx::oid(target)};
  auto result = clusters.find_one(make_document(kvp("_id", oid)));
  if (result)
  {
    return json::parse(bsoncxx::to_json(*result));
  }
  else
  {
    return std::nullopt;
  }
}

std::optional<json> MongoDB::clusterFindByName(const std::string &target)
{
  auto clusters = db["clusters"];
  auto result = clusters.find_one(make_document(kvp("name", target)));
  if (result)
    return json::parse(bsoncxx::to_json(*result));
  else
  {
    return std::nullopt;
  }
}

json MongoDB::clusterFindByAddr(const std::string &addr)
{
  auto clusters = db["clusters"];
  auto doc = make_document(kvp("address",
                               make_document(
                                   kvp("$elemMatch",
                                       make_document(
                                           kvp("$eq", addr))))));
  auto result = clusters.find_one(doc.view());
  if (result)
    return json::parse(bsoncxx::to_json(*result));
  else
  {
    return json::object();
  }
}

// void MongoDB::CreateIndexes() {
//   auto result = walletCol.find_one({});
//   if (result)
//     return;
//   else {
//     auto index_specification = make_document(kvp("address", 1));
//     auto index_option = make_document(kvp("unique", true));
//     walletCol.create_index(std::move(index_specification),
//                            std::move(index_option));
//   }
// }

// int MongoDB::GetSavedHeight() {
//   auto result = updateCol.find_one({});
//   if (result) {
//     auto height = result->view()["height"];
//     return height.get_int32().value;
//   } else {
//     auto doc = make_document(kvp("height", 0), kvp("time", time(NULL)));
//     updateCol.insert_one(doc.view());

//     return 0;
//   }
// }

// void MongoDB::UpdateHeight(int saveBlock) {
//   auto doc = make_document(kvp("$set", make_document(kvp("height",
//   saveBlock),
//                                                      kvp("time",
//                                                      time(NULL)))));
//   updateCol.update_many({}, doc.view());
// }

// json MongoDB::GetWalletData(std::string addr) {
//   auto result = walletCol.find_one(make_document(kvp("address", addr)));
//   if (result)
//     return json::parse(bsoncxx::to_json(*result));
//   else {
//     return {};
//   }
// }

// void MongoDB::StoreWalletData(json& data) {
//   auto document = bsoncxx::from_json(data.dump());
//   walletCol.insert_one(document.view());
// }

// void MongoDB::UpdateWalletData(std::string id, json& updateData) {
//   std::string oid_value = id.substr(9, 24);
//   walletCol.update_one(
//       make_document(kvp("_id", bsoncxx::oid(oid_value))),
//       make_document(kvp("$set", bsoncxx::from_json(updateData.dump()))));
// }

void MongoDB::Instance() { mongocxx::instance inst{}; }

MongoDB::~MongoDB() { client.reset(); }