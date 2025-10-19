#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!", sf::Style::Default);
	window.setFramerateLimit(60);

	// Rectangle 
    sf::RectangleShape rect(sf::Vector2(100.0f, 50.0f));
	rect.setPosition(sf::Vector2(100.0f, 300.0f));
	rect.setFillColor(sf::Color(255,100,100,100));

    // Circle
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(-10.0f);
    circle.setOutlineColor(sf::Color(250, 150, 150));

    // Triangle
	sf::CircleShape triangle;
	triangle.setRadius(100.f);
	triangle.setPointCount(3);

    // Line
    sf::Vertex line[] = {

        // X,Y Point 1 - To X,Y Point 2
        { {10.f, 10.f}, sf::Color::White, {0.f, 0.f} },
        { {10.f, 20.f}, sf::Color::White, {0.f, 0.f} }
    };


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

			if (event->is<sf::Event::KeyPressed>())
            {
                circle.setRadius(circle.getRadius() - 1.0f);
			}
        }

		circle.move(sf::Vector2(0.5f, 0.0f));
		rect.move(sf::Vector2(0.0f, -1.f));

        window.clear();

        window.draw(circle);
		window.draw(rect);
        window.draw(triangle);
		window.draw(line, 2, sf::PrimitiveType::Lines);
       


        window.display();
    }
}