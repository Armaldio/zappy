//
//-----------------------------------------------------------------------------
//Filename:    RenderCanvas.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include <Scene/SceneManager.hpp>
#include <Scene/SplashScene.hpp>
#include <Scene/GameScene.hpp>
#include "RenderCanvas.hpp"

zappy::RenderCanvas::RenderCanvas(QWidget *parent, const QPoint &position, const QSize &size,
                                  const unsigned int timeFrame)
        : qsf::QSFMLCanvas(parent, position, size, timeFrame) {
    std::cerr << "RenderCanvas";
    setFramerateLimit(60);
}

zappy::RenderCanvas::~RenderCanvas() {
    OnDestroy();
}

void zappy::RenderCanvas::OnUpdate(sf::Clock &clock) {
    sf::RenderWindow::clear(sf::Color(0, 0, 0));

    sf::Event event;
    event.type = (sf::Event::EventType) -1;
    zappy::SceneManager::get_instance_ptr()->update(event);
    while (pollEvent(event)) {
        std::cout << "event: " << event.type << std::endl;
        zappy::SceneManager::get_instance_ptr()->update(event);
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                    QWidget::close();
                break;
            case sf::Event::Resized:
                zappy::SceneManager::get_instance_ptr()->resize(event.size.width, event.size.height);
                break;
        }
    }
    zappy::SceneManager::get_instance_ptr()->draw(clock.restart());
}

void zappy::RenderCanvas::OnInit() {
    zappy::SceneManager::get_instance_ptr()->addScene(new zappy::SplashScene(this, "splashScreen"));
    zappy::SceneManager::get_instance_ptr()->addScene(new zappy::GameScene(this, "gameScene"));
    zappy::SceneManager::get_instance_ptr()->loadRessources();
}

void zappy::RenderCanvas::OnDestroy() {
    zappy::SceneManager::get_instance_ptr()->unloadRessources();
}