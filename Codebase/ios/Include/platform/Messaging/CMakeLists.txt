set(headers ${headers} platform/Messaging
)
set(currsources
  platform/Messaging/ActiveObject.h
  platform/Messaging/ActiveObjectBlockingRunner.h
  platform/Messaging/ActiveObjectNonBlockingRunner.h
  platform/Messaging/CatalogBinding.h
  platform/Messaging/CMakeLists.txt
  platform/Messaging/DispatchQueue.h
  platform/Messaging/IMessage.h
  platform/Messaging/IMessageQueue.h
  platform/Messaging/ImmediateMessageBus.h
  platform/Messaging/MessageQueue.h
  platform/Messaging/MPMCMessageBus.h
)
set(sources ${sources} ${currsources})
source_group(\\Messaging FILES ${currsources})
