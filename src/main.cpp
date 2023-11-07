#include <blocksci/blocksci.hpp>
#include <iostream>
#include <signal.h>
#include <atomic>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "Handler.hpp"
#include "MongoDB.hpp"

std::atomic<bool> running(true);

void signalHandler(int signum)
{
  running = false;
  std::cout << "stop server" << std::endl;
}

int main()
{
  const char* mongo_uri_env = std::getenv("MONGO_URI");
  const char* blocksci_setting_env = std::getenv("BLOCKSCI_SETTING");
  const char* server_url_env = std::getenv("SERVER_URL");

  if (!mongo_uri_env || !blocksci_setting_env || !server_url_env) 
  {
      std::cerr << "One or more required environment variables are not set." << std::endl;
      return 1;
  }
  MongoDB::Instance();

  // 환경 변수 값을 std::string 객체로 변환
  const std::string mongoUri(mongo_uri_env);
  const std::string blocksciSetting(blocksci_setting_env);
  const utility::string_t serverUrl = utility::conversions::to_string_t(server_url_env);

  // BlockSci와 Handler 객체를 초기화
  blocksci::Blockchain chain(blocksciSetting);
  Handler listener(serverUrl, chain, mongoUri);

  signal(SIGINT, signalHandler);  // Ctrl+C
  signal(SIGTERM, signalHandler); // 종료 명령

  try
  {
    listener.open().wait();
    ucout << U("Listening for requests at: ") << listener.uri().to_string() << std::endl;
    while (running)
    {
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    listener.close().wait();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}