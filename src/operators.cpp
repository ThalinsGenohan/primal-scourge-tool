#include "operators.h"

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

template <typename T>
std::vector<T>& operator+(const std::vector<T>& vector1, const std::vector<T>& vector2)
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

std::ostream& operator<<(std::ostream& os, const sf::Color& c)
{
  return os << int(c.r) << "/" << int(c.g) << "/" << int(c.b) << "/" << int(c.a);
}
std::istream& operator>>(std::istream& is, sf::Color& c)
{
  return is >> c.r >> c.g >> c.b >> c.a;
}

std::wostream& operator<<(std::wostream& os, const std::map<std::string, std::wstring>& m)
{
  for (auto it = m.begin(); it != m.end(); ++it)
  {
    os << std::wstring(it->first.begin(), it->first.end()) << " - " << it->second << std::endl;
  }
  return os;
}

sf::Packet& operator<<(sf::Packet& packet, const sf::Color& color)
{
  return packet << color.r << color.g << color.b << color.a;
}
sf::Packet& operator>>(sf::Packet& packet, sf::Color& color)
{
  return packet >> color.r >> color.g >> color.b >> color.a;
}