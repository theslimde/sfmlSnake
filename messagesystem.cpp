#include "messagesystem.hpp"

MessageSystem::sendMessage(std::unique_ptr<Message> message,
    std::weak_ptr<MessageClient> sender) noexcept {
    auto pair = subsriptions_.equal_range(message.getString());
    for(auto it : pair.first; it != pair.second; it++) {
        auto weak_receiver = it->second;
        auto shared_receiver = weak_receiver.lock();

        if(!shared_receiver) {
            unsubscribeFromAllMessages(weak_receiver);
        }
        else {
            shared_receiver->receiveMessage(*message, weak_receiver);
        }
    }
}

MessageSystem::subscribeToMessages(std::string message,
    std::weak_ptr<MessageClient> receiver) noexcept {
    // TODO : Implement here

}

MessageSystem::unsubscribeFromMessages(std::string message,
    std::weak_ptr<MessageClient> receiver) noexcept;

MessageSystem::unsubscribeFromAllMessages(
    std::weak_ptr<MessageClient> receiver) noexcept;


