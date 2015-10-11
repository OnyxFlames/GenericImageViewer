#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char* argv[])
{
	float rotationValue = 0;
	sf::Texture texture;
	sf::Sprite image;

	if (argc < 2)
	{
		std::cerr << "Usage: <program> <filename>" << std::endl;
		exit(1);
	}
	else
	{
		if (!texture.loadFromFile(argv[1]))
		{
			std::cerr << argv[1] << " does not exist!" << std::endl;
			exit(1);
		}
		image.setTexture(texture);
	}
	std::string pretitle = argv[1];
	std::string title = "Generic Image Viewer - " + pretitle;
	sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), title);
	window.setPosition(sf::Vector2i(0, 0));
	if (texture.getSize().x >= 1000 || texture.getSize().y >= 1000)
	{
		image.setScale(sf::Vector2f(0.5, 0.5));
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
			{
				image.setScale(sf::Vector2f(0.5, 0.5));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash))
			{
				image.setScale(sf::Vector2f(1.0, 1.0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (rotationValue >= 270)
				{
					rotationValue = 0;
				}
				else{
					rotationValue += 90;
				}

				if (rotationValue == 0)
				{
					image.setPosition(0.f, 0.f);
				}
				if (rotationValue == 90)
				{
					image.setPosition((float)window.getSize().x, 0.f);
				}
				if (rotationValue == 180)
				{
					image.setPosition((float)window.getSize().x, (float)window.getSize().y);
				}
				if (rotationValue == 270)
				{
					image.setPosition(0.f, (float)window.getSize().y);
				}
				image.setRotation(rotationValue);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (rotationValue == 0)
				{
					rotationValue = 270;
				}
				else{
					rotationValue -= 90;
				}

				if (rotationValue == 0)
				{
					image.setPosition(0.f, 0.f);
				}
				if (rotationValue == 90)
				{
					image.setPosition((float)window.getSize().x, 0.f);
				}
				if (rotationValue == 180)
				{
					image.setPosition((float)window.getSize().x, (float)window.getSize().y);
				}
				if (rotationValue == 270)
				{
					image.setPosition(0.f, (float)window.getSize().y);
				}
				image.setRotation(rotationValue);
			}
		}

		window.clear(sf::Color::Black);
		window.draw(image);
		window.display();
	}

	return 0;
}