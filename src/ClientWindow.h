#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <TGUI/TGUI.hpp>

#include "Message.h"
#include "Client.h"

class Client::ClientWindow
{
public:
  class ChatDisplay;

  explicit ClientWindow(Client& client, TextManagerRef textManager);

  std::vector<Channel> getOocChannels() const;

  Channel getFocusedChannel() const;

  void addChannel(Channel channel);
  void removeChannel(std::string id);
  void removeChannel(Channel channel);
  void addUser(User user) const;
  void removeUser(User user) const;
  void setUsers(std::list<User> users) const;
  void addMessage(Message message) const;

  void run();

private:
  Client& _client;
  TextManagerRef _textManager;

  sf::RenderWindow _window;

  tgui::Gui _gui;
  tgui::Theme _theme;

  ChatDisplay* _chat;
};

#endif
