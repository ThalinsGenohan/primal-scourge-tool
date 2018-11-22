#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

template <typename T>
std::vector<T> operator+(std::vector<T> vector1, std::vector<T> vector2)
{
  std::vector<T> v;
  for (auto i = 0; i < int(vector1.size()); i++)
  {
    v.push_back(vector1[i]);
  }
  for (auto i = 0; i < int(vector2.size()); i++)
  {
    v.push_back(vector2[i]);
  }
  return v;
}

inline sf::Packet& operator<<(sf::Packet& packet, const sf::IpAddress& ip)
{
  return packet << ip.toString();
}
inline sf::Packet& operator>>(sf::Packet& packet, sf::IpAddress& ip)
{
  std::string str;
  packet >> str;
  ip = str;
  return packet;
}

inline sf::Packet& operator<<(sf::Packet& packet, const sf::Color& color)
{
  return packet << color.r << color.g << color.b << color.a;
}
inline sf::Packet& operator>>(sf::Packet& packet, sf::Color& color)
{
  return packet >> color.r >> color.g >> color.b >> color.a;
}

#endif