#include <SFML/Graphics.hpp>
#include <cmath>
#include <format>
#include <iostream>
#include <vector>

sf::Font font;

void setTextProperties(sf::Text& txt, float x, float y)
{
    txt.setFont(font);
    txt.setCharacterSize(22);
    txt.setFillColor(sf::Color::Green);
    txt.setPosition({ x, y });
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Controller Tester");
    window.setFramerateLimit(24);
    if (!font.loadFromFile("DroidSansMono.ttf")) {
        std::cout << "Couldn't load font file\n";
        return 2;
    }

    sf::Text txtAxisX;
    setTextProperties(txtAxisX, 10, 10);
    sf::Text txtAxisY;
    setTextProperties(txtAxisY, 10, 40);
    sf::Text txtAxisZ;
    setTextProperties(txtAxisZ, 10, 70);
    sf::Text txtAxisR;
    setTextProperties(txtAxisR, 10, 100);
    sf::Text txtAxisU;
    setTextProperties(txtAxisU, 10, 130);
    sf::Text txtAxisV;
    setTextProperties(txtAxisV, 10, 160);
    sf::Text txtAxisPovX;
    setTextProperties(txtAxisPovX, 10, 190);
    sf::Text txtAxisPovY;
    setTextProperties(txtAxisPovY, 10, 220);

    std::vector<sf::Text> vecBtn;
    unsigned int yPos = 10;
    for (unsigned int n = 0; n < sf::Joystick::getButtonCount(0); ++n) {
        sf::Text t;
        setTextProperties(t, 360, yPos);
        vecBtn.push_back(t);
        yPos += 30;
    }

    const float deadZone = 20.f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Joystick::isConnected(0)) {
                for (unsigned int n = 0; n < sf::Joystick::getButtonCount(0); ++n) {
                    if (sf::Joystick::isButtonPressed(0, n)) {
                        vecBtn[n].setString(std::format("Button {:2} pressed", n));
                    } else {
                        vecBtn[n].setString(std::format("Button {:2}", n));
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::X)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
                    if (std::abs(value) > deadZone) {
                        txtAxisX.setString(std::format("Axis    X: {:.1f}", value));
                    } else {
                        txtAxisX.setString("Axis    X: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::Y)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
                    if (std::abs(value) > deadZone) {
                        txtAxisY.setString(std::format("Axis    Y: {:.1f}", value));
                    } else {
                        txtAxisY.setString("Axis    Y: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::Z)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
                    if (std::abs(value) > deadZone) {
                        txtAxisZ.setString(std::format("Axis    Z: {:.1f}", value));
                    } else {
                        txtAxisZ.setString("Axis    Z: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::R)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);
                    if (std::abs(value) > deadZone) {
                        txtAxisR.setString(std::format("Axis    R: {:.1f}", value));
                    } else {
                        txtAxisR.setString("Axis    R: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::U)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
                    if (std::abs(value) > deadZone) {
                        txtAxisU.setString(std::format("Axis    U: {:.1f}", value));
                    } else {
                        txtAxisU.setString("Axis    U: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::V)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);
                    if (std::abs(value) > deadZone) {
                        txtAxisV.setString(std::format("Axis    V: {:.1f}", value));
                    } else {
                        txtAxisV.setString("Axis    V: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::PovX)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX);
                    if (std::abs(value) > deadZone) {
                        txtAxisPovX.setString(std::format("Axis PovX: {:.1f}", value));
                    } else {
                        txtAxisPovX.setString("Axis PovX: centred");
                    }
                }
                if (sf::Joystick::hasAxis(0, sf::Joystick::Axis::PovY)) {
                    float value = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY);
                    if (std::abs(value) > deadZone) {
                        txtAxisPovY.setString(std::format("Axis PovY: {:.1f}", value));
                    } else {
                        txtAxisPovY.setString("Axis PovX: centred");
                    }
                }
            } else {
                std::cout << "No controller is connected\n";
                return 1;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(txtAxisX);
        window.draw(txtAxisY);
        window.draw(txtAxisZ);
        window.draw(txtAxisR);
        window.draw(txtAxisU);
        window.draw(txtAxisV);
        window.draw(txtAxisPovX);
        window.draw(txtAxisPovY);
        for (const auto& btn : vecBtn) {
            window.draw(btn);
        }
        window.display();
    }
    return 0;
}
