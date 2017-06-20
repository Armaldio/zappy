//
//-----------------------------------------------------------------------------
//Filename:    RenderCanvas.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include <include/Scene/SceneManager.hpp>
#include <include/Scene/SplashScene.hpp>
#include <include/Scene/GameScene.hpp>
#include "RenderCanvas.hpp"

zappy::RenderCanvas::RenderCanvas(QWidget *parent, const QPoint &position, const QSize &size,
                                  const unsigned int timeFrame)
        : qsf::QSFMLCanvas(parent, position, size, timeFrame) {
    std::cerr << "RenderCanvas";
}

zappy::RenderCanvas::~RenderCanvas() {
    OnDestroy();
}

void zappy::RenderCanvas::OnUpdate() {
    zappy::SceneManager::get_instance_ptr()->update();
    sf::RenderWindow::clear(sf::Color(0, 0, 255));
    zappy::SceneManager::get_instance_ptr()->draw();


    sf::Event event;
    while (pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                    QWidget::close();
                break;
            case sf::Event::Resized:
                std::cout << "Resized" << std::endl;
                break;
        }
    }
}

void zappy::RenderCanvas::OnInit() {
    zappy::SceneManager::get_instance_ptr()->addScene(new zappy::SplashScene(this, "splashScreen"));
    zappy::SceneManager::get_instance_ptr()->addScene(new zappy::GameScene(this, "gameScene"));
    zappy::SceneManager::get_instance_ptr()->loadRessources();
}

void zappy::RenderCanvas::OnDestroy() {
    zappy::SceneManager::get_instance_ptr()->unloadRessources();
}