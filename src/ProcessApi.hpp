#ifndef PROCESSAPI_HPP
#define PROCESSAPI_HPP
#include <blocksci/blocksci.hpp>
#include <nlohmann/json.hpp>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <regex>
#include <deque>
#include <unordered_map>
#include <vector>
#include "MongoDB.hpp"
using json = nlohmann::json;

const int THRESHOLD_SCORE = 8;

const int PEELING_CHAIN_SCORE = 3;
const int POWER_OF_TEN_SCORE = 2;
const int OPTIMAL_CHANGE_SCORE = 2;
const int ADDRESS_TYPE_SCORE = 1;
const int LOCKTIME_SCORE = 1;
const int ADDRESS_REUSE_SCORE = 3;
const int CLIENT_BEHAVIOR_SCORE = 2;
const int LEGACY_SCORE = 1;
const int FIXED_FEE_SCORE = 1;
const int SPENT_SCORE = 1;

class ProcessApi
{
public:
  ProcessApi() = default;
  ProcessApi(blocksci::Blockchain &chain, const std::string &mongoUri);
  std::string getTxData(const utility::string_t &input);
  std::string getWalletData(const utility::string_t &req);
  std::string getTxInWallet(const std::string &hash, const time_t &startDate, const time_t &endDate);
  std::string getClusterData(const utility::string_t &req);
  std::string getClusterResult(const utility::string_t &req);
  std::string getHeuristicResult(const utility::string_t &req);

private:
  blocksci::Blockchain &chain;
  const std::string &mongoUri;
  json MakeInputData(blocksci::Input input);
  json MakeOutputData(blocksci::Output output);
  std::string onlyAddress(const std::string &fullString);
  std::vector<std::string> determineChangeAddresses(const blocksci::Transaction &tx);
};

class InvalidHash : public std::runtime_error {
public:
    InvalidHash(const std::string& message)
        : std::runtime_error(message) {}
};

#endif