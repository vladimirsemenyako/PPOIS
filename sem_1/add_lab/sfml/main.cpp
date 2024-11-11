#include <SFML/Graphics.hpp>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int logoWidth = 100;
    const int logoHeight = 50;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "DVD Save Screen");

    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("../img/DVD_logo.png")) {
        return -1;
    }

    sf::Sprite logoSprite;
    logoSprite.setTexture(logoTexture);
    logoSprite.setScale(
        static_cast<float>(logoWidth) / logoTexture.getSize().x,
        static_cast<float>(logoHeight) / logoTexture.getSize().y
    );

    float x = 100.0f, y = 100.0f;
    float dx = 0.2f, dy = 0.2f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        x += dx;
        y += dy;

        if (x <= 0 || x + logoWidth >= windowWidth) dx = -dx;
        if (y <= 0 || y + logoHeight >= windowHeight) dy = -dy;

        logoSprite.setPosition(x, y);

        window.clear(sf::Color::White);
        window.draw(logoSprite);
        window.display();
    }

    return 0;
}