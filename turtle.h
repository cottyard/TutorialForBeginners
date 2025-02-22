#include <SFML/Graphics.hpp>
#include <cmath>
class Turtle {
private:
    sf::RenderWindow& window;
    sf::Vector2f position;
    float angle;
    bool penDown;
    sf::Color color_;
    sf::VertexArray path;

public:
    Turtle(sf::RenderWindow& win) 
        : window(win), position(win.getSize().x/2, win.getSize().y/2), 
          angle(0), penDown(true), color_(sf::Color::Black) {}

    void fd(float distance) {
        float rad = angle * 3.14159265 / 180.0;  // תΪ����
        sf::Vector2f delta(distance * cos(rad), -distance * sin(rad)); // SFML��Y������
        sf::Vector2f newPos = position + delta;

        if (penDown) {
            path.append(sf::Vertex(position, color_));
            path.append(sf::Vertex(newPos, color_));
        }
        position = newPos;
    }

    void bk(float distance) { fd(-distance); } // �����ƶ�

    void lt(float degrees) { angle += degrees; } // ��ת���ӽǶ�
    void rt(float degrees) { angle -= degrees; } // ��ת���ٽǶ�

    void pu() { penDown = false; } // ̧��
    void pd() { penDown = true; }  // ���
	void go(float x, float y) {
        position = sf::Vector2f(x, y);
    }

    void color(sf::Color c) { color_ = c; }

    void draw() {
        window.draw(path);
    }
};

