#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

namespace sf
{
  class Packet;
}

class Channel
{
public:
  enum ChannelType
  {
    NO_CHANNEL,
    PUBLIC_OOC,
    PRIVATE_OOC,
    PUBLIC_IC,
    PRIVATE_IC
  };

  Channel();
  Channel(std::string id, std::string name, ChannelType type = PUBLIC_OOC);

  std::string getId() const { return this->_id; }
  std::string getName() const { return this->_name; }
  ChannelType getType() const { return this->_type; }

  void setId(std::string id) { this->_id = id; }
  void setName(std::string name) { this->_name = name; }
  void setType(ChannelType type) { this->_type = type; }

  friend sf::Packet& operator<<(sf::Packet& p, const Channel& c);
  friend sf::Packet& operator>>(sf::Packet& p, Channel& c);

private:
  std::string _id;
  std::string _name;
  ChannelType _type;
};

sf::Packet& operator<<(sf::Packet& p, const Channel::ChannelType& t);
sf::Packet& operator>>(sf::Packet& p, Channel::ChannelType& t);
sf::Packet& operator<<(sf::Packet& p, const Channel& c);
sf::Packet& operator>>(sf::Packet& p, Channel& c);

//extern Channel noIcChannel;
//extern Channel noOocChannel;
//extern Channel generalChannel;

#endif
