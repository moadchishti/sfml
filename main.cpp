#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void transform(sf::VertexArray &cube, sf::Vector3f vertices[4]);
float degToRad(float degrees);

sf::Vector2f center(400.0, 300.0);

sf::CircleShape c1(5);
sf::CircleShape c2(5);
sf::CircleShape c3(5);
sf::CircleShape c4(5);
sf::CircleShape c5(5);
sf::CircleShape c6(5);
sf::CircleShape c7(5);
sf::CircleShape c8(5);

sf::Vector2f points_new[4];
sf::Vector2f rotated_points[8];

float degrees = 0;
float radians = degToRad(degrees);
float radians1 = degToRad(degrees);
float radians2 = degToRad(degrees);

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template");
    window.setFramerateLimit(60);

    sf::VertexArray box(sf::LinesStrip, 16);

    sf::Color colors[16] = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color::White,
        sf::Color::Black,
        sf::Color(255, 128, 0), // Orange
        sf::Color(128, 0, 255), // Purple
        sf::Color(0, 255, 128), // Cyanish green
        sf::Color(0, 128, 255), // Bluish green
        sf::Color(255, 255, 0), // Yellow
        sf::Color(255, 0, 255), // Magenta
        sf::Color(0, 255, 255), // Cyan
        sf::Color(192, 192, 192) // Light gray
    };

    // Assign colors to each vertex
    for (int i = 0; i < box.getVertexCount(); ++i) {
        box[i].color = colors[i]; // Assign colors from the array
    }

    sf::Vector3f points[8];
    points[0] = sf::Vector3f(1, 1, 1);
    points[1] = sf::Vector3f(-1, 1, 1);
    points[2] = sf::Vector3f(-1, -1, 1);
    points[3] = sf::Vector3f(1, -1, 1);
    points[4] = sf::Vector3f(1, 1, -1);
    points[5] = sf::Vector3f(-1, 1, -1);
    points[6] = sf::Vector3f(-1, -1, -1);
    points[7] = sf::Vector3f(1, -1, -1);
    

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw here
        transform(box, points);
        window.draw(box);
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        window.draw(c4);
        window.draw(c5);
        window.draw(c6);
        window.draw(c7);
        window.draw(c8);
        

        if (degrees == 360)
        {
            degrees = 0;
        }
        else
        {
            degrees += 0.5;
        }
        radians = degToRad(degrees);
        radians1 = degToRad(degrees - 123);
        radians2 = degToRad(degrees - 200);

        // Update the window
        window.display();
    }

    return 0;
}

//functions
void transform(sf::VertexArray &cube, sf::Vector3f vertices[4])
{   
    float rotationX[3][3] = 
    {
        {1, 0, 0},
        {0, cos(radians), -sin(radians)},
        {0, sin(radians), cos(radians)},
    };
    float rotationY[3][3] = 
    {
        {cos(radians1), 0, sin(radians1)},
        {0, 1, 0},
        {-sin(radians1), 0, cos(radians1)},
    };
    float rotationZ[3][3] = 
    {
        {cos(radians2), -sin(radians2), 0},
        {sin(radians2), cos(radians2), 0},
        {0, 0, 1},
    };

    for (int i = 0; i < 8; i++)
    {   
        sf::Vector3f xy((vertices[i].x * rotationY[0][0]) + (vertices[i].y * rotationY[0][1]) + (vertices[i].z * rotationY[0][2]), (vertices[i].x * rotationY[1][0]) + (vertices[i].y * rotationY[1][1]) + (vertices[i].z * rotationY[1][2]), (vertices[i].x * rotationY[2][0]) + (vertices[i].y * rotationY[2][1]) + (vertices[i].z * rotationY[2][2]));

        sf::Vector3f xyz((xy.x * rotationX[0][0]) + (xy.y * rotationX[0][1]) + (xy.z * rotationX[0][2]), (xy.x * rotationX[1][0]) + (xy.y * rotationX[1][1]) + (xy.z * rotationX[1][2]), (xy.x * rotationX[2][0]) + (xy.y * rotationX[2][1]) + (xy.z * rotationX[2][2]));

        rotated_points[i] = sf::Vector2f(123 * ((xyz.x * rotationZ[0][0]) + (xyz.y * rotationZ[0][1]) + (xyz.z * rotationZ[0][2]))+ center.x, 123 * ((xyz.x * rotationZ[1][0]) + (xyz.y * rotationZ[1][1]) + (xyz.z * rotationZ[1][2])) + center.y);
    }

    cube[0].position = sf::Vector2f(rotated_points[0].x, rotated_points[0].y);
    cube[1].position = sf::Vector2f(rotated_points[1].x, rotated_points[1].y);
    cube[2].position = sf::Vector2f(rotated_points[2].x, rotated_points[2].y);
    cube[3].position = sf::Vector2f(rotated_points[3].x, rotated_points[3].y);
    cube[4].position = sf::Vector2f(rotated_points[0].x, rotated_points[0].y);
    cube[5].position = sf::Vector2f(rotated_points[4].x, rotated_points[4].y);
    cube[6].position = sf::Vector2f(rotated_points[5].x, rotated_points[5].y);
    cube[7].position = sf::Vector2f(rotated_points[6].x, rotated_points[6].y);
    cube[8].position = sf::Vector2f(rotated_points[7].x, rotated_points[7].y);
    cube[9].position = sf::Vector2f(rotated_points[4].x, rotated_points[4].y);
    cube[10].position = sf::Vector2f(rotated_points[7].x, rotated_points[7].y);
    cube[11].position = sf::Vector2f(rotated_points[3].x, rotated_points[3].y);
    cube[12].position = sf::Vector2f(rotated_points[2].x, rotated_points[2].y);
    cube[13].position = sf::Vector2f(rotated_points[6].x, rotated_points[6].y);
    cube[14].position = sf::Vector2f(rotated_points[5].x, rotated_points[5].y);
    cube[15].position = sf::Vector2f(rotated_points[1].x, rotated_points[1].y);


    c1.setPosition(rotated_points[0].x - 5, rotated_points[0].y - 5);
    c2.setPosition(rotated_points[1].x - 5, rotated_points[1].y - 5);
    c3.setPosition(rotated_points[2].x - 5, rotated_points[2].y - 5);
    c4.setPosition(rotated_points[3].x - 5, rotated_points[3].y - 5);
    c5.setPosition(rotated_points[4].x - 5, rotated_points[4].y - 5);
    c6.setPosition(rotated_points[5].x - 5, rotated_points[5].y - 5);
    c7.setPosition(rotated_points[6].x - 5, rotated_points[6].y - 5);
    c8.setPosition(rotated_points[7].x - 5, rotated_points[7].y - 5);
    

    std::cout << rotationX[0][0] << std::endl;
    std::cout << rotated_points[0].x << std::endl;

}

float degToRad(float degrees)
{
    return degrees * (M_PI / 180.0);
}