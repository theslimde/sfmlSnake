#ifndef SFMLSNAKE_MESSAGESYSTEM_HPP
#define SFMLSNAKE_MESSAGESYSTEM_HPP

#include <memory>
#include <unordered_map>
#include <vector>

class Message;
class MessageClient : std::enable_shared_from_this<MessageClient>
{
public:
    MessageClient(MessageSystem& messageSys) :
        messageSys_(messageSys)
    {}

    virtual ~MessageClient() {
    }

     virtual void receiveMessage(const Message& message,
            std::weak_ptr<MessageClient> sender) noexcept = 0;

protected:

    void sendMessage(std::unique_ptr<Message> message) {
        messageSys_.sendMessage(message, shared_from_this());
    }

    void subsribeToMessage(std::string message) {
        messageSys_.subscribeToMessage(message, shared_from_this());
    }

    void unsubscribeFormMessage(std::string message) {
        messageSys_.unsubscribeFromMessage(message, shared_from_this());
    }

    void unsubscribeFromAllMessages() {
        messageSys_.unsubscribeFromAllMessages(shared_from_this());
    }

private:

    MessageSystem& messageSys_;
};

/*
 * MessageSystem is a typical game engine message system. I have chosen
 * correctness over speed here, so messages have a (hashed) string as
 * identifier and every reference to a MessageClient is via a weak_ptr.
 * If a MessageClient goes out of scope, the Message System will automatically
 * erase all references to it.
 */
class MessageSystem final
{
public:

    // No copying or moving
    MessageSystem(MessageSystem& other)             = delete;
    MessageSystem(MessageSystem&& other)            = delete;
    MessageSystem& operator=(MessageSystem& other)  = delete;
    MessageSystem& operator=(MessageSystem&& other) = delete;

    void sendMessage(std::unique_ptr<Message> message,
            std::weak_ptr<MessageClient> sender) noexcept;

    void subscribeToMessages(std::string message,
            std::weak_ptr<MessageClient> receiver) noexcept;

    void unsubscribeFromMessages(std::string message,
            std::weak_ptr<MessageClient> receiver) noexcept;

    void unsubscribeFromAllMessages(
            std::weak_ptr<MessageClient> receiver) noexcept;

private:

    std::unordered_map<std::string, std::weak_ptr<MessageClient>>
        subscribtions_;
};

#endif // SFMLSNAKE_MESSAGESYSTEM_HPP
