#include "pch.h"
#include "ClientWindow.h"

#include "CONSTANTS.h"
#include "ChatDisplay.h"
#include "TextManager.h"

Client::ClientWindow::ClientWindow(Client& client, TextManagerRef textManager) : _client(client), _textManager(textManager), _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), this->_textManager->getText("TITLE"), sf::Style::Close | sf::Style::Titlebar), _gui(this->_window), _theme("assets/themes/Black.txt"), _chat(new ChatDisplay(this->_client, this->_theme, "Channel(s)"))
{
  std::cout << "Creating ClientWindow..." << std::endl;
  auto v = this->_chat->getWidgets();
  for (auto i = 0; i < int(v.size()); i++)
  {
    this->_gui.add(v[i]);
  }

  this->addChannel(GENERAL_CHANNEL);
  this->addChannel(GENERAL_2_CHANNEL);
  this->_chat->setPosition({ MARGIN, MARGIN });
}

Channel Client::ClientWindow::getFocusedChannel() const
{
  return this->_chat->getFocusedChannel();
}

void Client::ClientWindow::addChannel(Channel channel)
{
  this->_chat->addChannel(channel);
  this->_gui.add(this->_chat->getChatBoxes()[channel.getName()]);
}

void Client::ClientWindow::addUser(User user) const
{
  this->_chat->addUser(user);
}

void Client::ClientWindow::removeUser(User user) const
{
  this->_chat->removeUser(user);
}

void Client::ClientWindow::setUsers(std::vector<User> users) const
{
  this->_chat->setUsers(users);
}

void Client::ClientWindow::addMessage(Message message) const
{
  this->_chat->addMessage(message);
}

void Client::ClientWindow::run()
{
  while (this->_window.isOpen())
  {
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        this->_window.close();
      }

      this->_gui.handleEvent(event);

      this->_chat->switchChatBox();

      this->_chat->checkInput(event);
    }

    this->_client.receive();

    this->_window.clear();
    this->_gui.draw();
    this->_window.display();
  }
}
