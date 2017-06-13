/**
* \file      graphicsnodes.hh
* \brief     nodes in sfmlgraphics window
* \author    Leo Jenneskens
* \copyright Copyright (c) 2017, The R2D2 Team
* \license   See LICENSE
*/

#include "graphicsnodes.hh"

#include <iostream>

GraphNode::GraphNode(sf::Vector2f position, std::string name, float size):
    position{position},
    size{size},
    name{name}
{
    circle.setFillColor(sf::Color::White);
}

void GraphNode::draw( sf::RenderWindow & window ) {
    sf::Font font;
    if (!font.loadFromFile("BebasNeue.otf")) {
        std::cout<< "Error: Can not load font\n";
    }
    sf::Text txt;
    txt.setFont(font);
    txt.setString(name);
    txt.setCharacterSize(30);
    txt.setStyle(sf::Text::Bold);
    txt.setColor(sf::Color::Green);
    txt.setPosition(position.x+20,position.y+20);
    window.draw(txt);

    circle.setRadius(size);
    circle.setPosition(position);
    circle.setOrigin(size,size);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(2);

    window.draw(circle);
}

sf::Vector2f GraphNode::getPosition() {
    return sf::Vector2f(position.x+size,position.y+size);
}

