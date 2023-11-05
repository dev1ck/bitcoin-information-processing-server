#include <blocksci/blocksci.hpp>
#include <iostream>
#include <signal.h>
#include <atomic>
#include <thread>
#include <chrono>

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
  MongoDB::Instance();
  std::string mongoUri = "mongodb://username:password@localhost:27017";
  blocksci::Blockchain chain("BlockSCI-setting-file-location");

  // "address:port"
  // address : 0.0.0.0 -> Access anyware, 127.0.0.1 -> Access localhost
  utility::string_t url = U("http://0.0.0.0:4000"); 
  Handler listener(url, chain, mongoUri);

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