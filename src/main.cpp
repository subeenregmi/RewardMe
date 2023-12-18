#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

struct Padding {
	float x;
	float y;
};

class Button {	
	public:
		sf::Sprite button;
		sf::Text text;
		sf::Font font;
		Padding padding;
		sf::Color color;
		sf::IntRect dimensions;

		Button(std::string t, Padding p, sf::Font* font, sf::Color textColor, sf::IntRect buttonDims, sf::Color buttonColor)
		{
			padding = p;
			color = buttonColor;
			dimensions = buttonDims;
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
			text.setCharacterSize(charSize);
			text.setPosition(position.x + p.x, position.y);

			while(text.findCharacterPos(t.length()-1).x + charWidth < position.x + size.x - p.x){
				charSize += 0.01;
				charWidth = 0.675 * charSize;
				text.setCharacterSize(charSize);
			}
			std::cout << charSize << std::endl;
			text.setPosition(position.x + p.x, position.y +  (size.y)/2 - charSize*0.675);
			text.setFillColor(textColor);
		}

		~Button(){
		}

		void onHover(){
			if (button.getColor() == color){
				button.setColor(sf::Color(0.75*color.r, 0.75*color.g, 0.75*color.b));
			}
		}

		void offHover(){
			if (button.getColor() != color){
				button.setColor(color);
			}
		}

		void handleMouse(sf::Vector2i mousePos){
			auto size = dimensions.getSize();
			auto pos  = dimensions.getPosition();
			if (mousePos.x >= pos.x && mousePos.x <= pos.x + size.x && mousePos.y >= pos.y && mousePos.y <= pos.y+size.y){
				onHover();
			}
			else{
				offHover();
			}
		}
};

int main(){
	sf::RenderWindow window(sf::VideoMode(400, 400), "button test");
	Padding p;
	p.x = 10;
	p.y = 10;
	sf::Font f;
	f.loadFromFile("../assets/fonts/WorkSans.ttf");
	Button b("Login", p, &f, sf::Color::Black, sf::IntRect(150, 150, 150, 90), sf::Color::Blue);

	while (window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			sf::IntRect buttonDims = b.dimensions;
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			b.handleMouse(mousePos);

		}
		window.clear(sf::Color::White);
		window.draw(b.button);
		window.draw(b.text);
		window.display();
	}
}

