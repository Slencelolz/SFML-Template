// SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Math.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("img/char.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture), sprite2(texture);
	sprite2.setPosition(250, (600/2)-16);
	sprite2.setColor(sf::Color::Green);
	// Clock object
	sf::Clock clock1, attackTimer;

	// Math object;
	Math math;

	float velocity, speed = 2500.0f;

    // Start the game loop
    while (window.isOpen())
    {
		clock1.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

		// Calculate velocity
		velocity = clock1.getElapsedTime().asSeconds() * speed;

        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
		window.draw(sprite2);
		// Move the sprite
		if(sprite.getPosition().y > 568)
		{
			sprite.setPosition(0, 0);
		}else
		{
			sprite.move(0, velocity);
		}

        // Update the window
        window.display();

		if (attackTimer.getElapsedTime().asSeconds() > 0.5f && math.getDistance(sprite.getPosition(), sprite2.getPosition()) < 300)
		{
			std::cout << "Shoot!" << std::endl;
			attackTimer.restart();
		}
    }
    return EXIT_SUCCESS;
}

