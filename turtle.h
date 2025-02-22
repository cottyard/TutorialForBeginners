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
        float rad = angle * 3.14159265 / 180.0;  // 转为弧度
        sf::Vector2f delta(distance * cos(rad), -distance * sin(rad)); // SFML的Y轴向下
        sf::Vector2f newPos = position + delta;

        if (penDown) {
            path.append(sf::Vertex(position, color_));
            path.append(sf::Vertex(newPos, color_));
        }
        position = newPos;
    }

    void bk(float distance) { fd(-distance); } // 反向移动

    void lt(float degrees) { angle += degrees; } // 左转增加角度
    void rt(float degrees) { angle -= degrees; } // 右转减少角度

    void pu() { penDown = false; } // 抬笔
    void pd() { penDown = true; }  // 落笔
	void go(float x, float y) {
        position = sf::Vector2f(x, y);
    }

    void color(sf::Color c) { color_ = c; }

    void draw() {
        window.draw(path);
    }
};

