#include "ClientWindow.h"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "CONSTANTS.h"
#include "ChatDisplay.h"
#include "TextManager.h"

Client::ClientWindow::ClientWindow(Client& client, TextManagerRef textManager) : _client(client), _textManager(textManager), _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), this->_textManager->getText("GAME_TITLE"), sf::Style::Close | sf::Style::Titlebar), _gui(this->_window), _theme("themes/Black.txt"), _ic(new ChatDisplay(this->_client, "IC Channels")), _ooc(new ChatDisplay(this->_client, "OOC Channels"))
{
  auto v = this->_ic->getWidgets();
  for (auto i = 0; i < int(v.size()); i++)
  {
    this->_gui.add(v[i]);
  }
  v = this->_ooc->getWidgets();
  for (auto i = 0; i < int(v.size()); i++)
  {
    this->_gui.add(v[i]);
  }

  this->addChannel(noIcChannel);
  this->addChannel(generalChannel);
  this->_ic->setPosition({ MARGIN, MARGIN });
  this->_ooc->setPosition({ this->_ic->getPosition().x + this->_ic->getSize().x + 2.f * PADDING, MARGIN });
}

void Client::ClientWindow::addChannel(Channel channel)
{
  switch (channel.getType())
  {
  case Channel::PUBLIC_OOC:
  case Channel::PRIVATE_OOC:
    this->_ooc->addChannel(channel);
    this->_gui.add(this->_ooc->getChatBoxes()[channel.getName()]);
    break;

  case Channel::PUBLIC_IC:
  case Channel::PRIVATE_IC:
    this->_ic->addChannel(channel);
    this->_gui.add(this->_ic->getChatBoxes()[channel.getName()]);
    break;
  default:;
  }
}

void Client::ClientWindow::addUser(User user) const
{
  this->_ooc->addUser(user);
}

void Client::ClientWindow::removeUser(User user) const
{
  this->_ooc->removeUser(user);
}

void Client::ClientWindow::addMessage(Message message) const
{
  switch (message.getChannel().getType())
  {
  case Channel::PUBLIC_OOC:
  case Channel::PRIVATE_OOC:
    this->_ooc->addMessage(message);
    break;

  case Channel::PUBLIC_IC:
  case Channel::PRIVATE_IC:
    this->_ic->addMessage(message);
    break;
  default: ;
  }
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

      this->_ic->switchChatBox();
      this->_ooc->switchChatBox();
      /*for (auto i = 0; i < int(this->_ic->getChannels().size()); i++)
      {
        if (this->_ic->getChannels()[i].getName() != this->_ic->getTabs()->getSelected())
        {
          this->_ic->getChatBoxes()[this->_ic->getChannels()[i].getName()]->setVisible(false);
        }
      }
      for (auto i = 0; i < int(this->_ooc->getChannels().size()); i++)
      {
        if (this->_ooc->getChannels()[i].getName() != this->_ooc->getTabs()->getSelected())
        {
          this->_ooc->getChatBoxes()[this->_ooc->getChannels()[i].getName()]->setVisible(false);
        }
      }
      if (int(this->_ic->getChannels().size()) > 0)
      {
        this->_ic->getChatBoxes()[this->_ic->getTabs()->getSelected()]->setVisible(true);
      }
      if (int(this->_ooc->getChannels().size()) > 0)
      {
        this->_ooc->getChatBoxes()[this->_ooc->getTabs()->getSelected()]->setVisible(true);
      }*/

      this->_ic->checkInput(event);
      this->_ooc->checkInput(event);
    }

    this->_client.receive();

    this->_window.clear();
    this->_gui.draw();
    this->_window.display();
  }
}
