IF(NOT WINDOWS)
set(headers ${headers} platform/Networking
)
set(currsources
  platform/Networking/CMakeLists.txt
  platform/Networking/ITcpClient.h
  platform/Networking/ITcpClientFactory.h
  platform/Networking/ITcpListener.h
  platform/Networking/Networking.h
  platform/Networking/TcpClient.cpp
  platform/Networking/TcpClient.h
  platform/Networking/TcpClientCallback.h
  platform/Networking/TcpClientFactory.cpp
  platform/Networking/TcpClientFactory.h
  platform/Networking/TcpListener.cpp
  platform/Networking/TcpListener.h
  platform/Networking/TcpListenerState.h
)
set(sources ${sources} ${currsources})
source_group(\\Networking FILES ${currsources})
endif(NOT WINDOWS)