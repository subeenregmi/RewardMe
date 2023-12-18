#include <button.hpp>

Button::Button(std::string t, sf::Font* font, sf::Color textColor, sf::IntRect buttonDims, sf::Color buttonColor, Padding p)
	: color(buttonColor), padding(p), dimensions(buttonDims), buttonPressed(false) {

	auto size = buttonDims.getSize();
	auto position = buttonDims.getPosition();

	sf::Texture texture;
	texture.create(size.x, size.y);
	
	button.setPosition(position.x, position.y);
	button.setTexture(texture);
	button.setColor(buttonColor);
	
	float charSize = 1;
	float charWidth = 27/40;

	text.setString(t);
	text.setFont(*font);
	text.setCharacterSize(1);
	text.setPosition(position.x + p.x, position.y);
	
	while(text.findCharacterPos(t.length()-1).x + charWidth < position.x + size.x - p.x){
		charSize += 0.01;
		charWidth = 0.675 * charSize;
		text.setCharacterSize(charSize);
	}

	text.setPosition(position.x + p.x, position.y + (size.y/2) - charSize*0.675);
	text.setFillColor(textColor);
}

inline void Button::onHover(){
	if (button.getColor() == color){
		button.setColor(sf::Color(0.75*color.r, 0.75*color.g, 0.75*color.b));
	}
}

inline void Button::offHover(){
	if (button.getColor() != color){
		button.setColor(color);
	}
}

void Button::handleMouse(sf::Vector2i mousePos, bool clicked){
	auto size = dimensions.getSize();
	auto pos = dimensions.getPosition();
	if (mousePos.x >= pos.x && mousePos.x <= pos.x + size.x && mousePos.y >= pos.y && mousePos.y <= pos.y+size.y){
		onHover();
		if (clicked){
			buttonPressed = true;
		}
		else{
			buttonPressed = false;
		}
	}
	else{
		offHover();
	}
}
