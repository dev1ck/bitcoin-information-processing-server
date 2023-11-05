#ifndef MONGODB_HPP
#define MONGODB_HPP
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <nlohmann/json.hpp>
#include <optional>

using json = nlohmann::json;
class MongoDB
{
public:
  MongoDB(const std::string &uri);
  ~MongoDB();
  static void Instance();
  json getProfile(const std::string &target);
  std::optional<json> clusterFindById(const std::string &target);
  std::optional<json> clusterFindByName(const std::string &target);
  json clusterFindByAddr(const std::string &addr);

  // void CreateIndexes();
  // void UpdateHeight(int);
  // int GetSavedHeight();
  // nlohmann::json GetWalletData(std::string);
  // void StoreWalletData(nlohmann::json &);
  // void UpdateWalletData(std::string, nlohmann::json &);

private:
  mongocxx::client client;
  mongocxx::database db;
};

#endif