#pragma once
#include <SFML/Graphics.hpp>
#include <string>

struct Padding {
	float x;
	float y;
};

class Button {
	public:
		sf::Sprite button;
		sf::Color color;
		Padding padding;
		sf::IntRect dimensions;

		sf::Text text;

		bool buttonPressed;

		Button(std::string t, sf::Font* font, sf::Color textColor, sf::IntRect buttonDims, sf::Color buttonColor, Padding p);

		inline void onHover();
		inline void offHover();
		void handleMouse(sf::Vector2i mousePos, bool clicked);
};

