//
//-----------------------------------------------------------------------------
//Filename:    QSFMLCanvas.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#include <SFML/System.hpp>
#include <QMouseEvent>
#include <include/QSFML/KeyConverter.hpp>
#include "QSFML/QSFMLWidget.hpp"

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif


qsf::QSFMLCanvas::QSFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size, const unsigned int timeFrame)
    : QWidget(parent), _initialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_PaintUnclipped);

    setFocusPolicy(Qt::StrongFocus);

    //Under X11, we need to flush the commands sent to the server to ensure that
    //SFML will get an updated view of the windows
    #ifdef Q_WS_X11
        XFlush(QX11Info::display());
    #endif

    move(position);
    resize(size);

    _timer.setInterval(timeFrame);
}

qsf::QSFMLCanvas::~QSFMLCanvas() {
    OnDestroy();
}

QPaintEngine *qsf::QSFMLCanvas::paintEngine() const {
    return 0;
}

void qsf::QSFMLCanvas::paintEvent(QPaintEvent *event) {
    OnUpdate();

    sf::RenderWindow::display();
}

void qsf::QSFMLCanvas::showEvent(QShowEvent *event) {
    if (!_initialized) {
        sf::RenderWindow::create(static_cast<sf::WindowHandle>(winId()));

        OnInit();

        // On paramètre le timer de sorte qu'il génère un rafraîchissement à la fréquence souhaitée
        connect(&_timer, SIGNAL(timeout()), this, SLOT(repaint()));
        _timer.start();

        _initialized = true;
    }
}

void qsf::QSFMLCanvas::OnUpdate() {
    sf::RenderWindow::clear(sf::Color(0, 255, 0));
}

void qsf::QSFMLCanvas::OnInit() {

}

void qsf::QSFMLCanvas::OnDestroy() {

}

void qsf::QSFMLCanvas::wheelEvent(QWheelEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::MouseWheelMoved;

    ev.mouseWheel.delta = event->delta() / 8 / 15;
    ev.mouseWheel.x = sf::Mouse::getPosition(*this).x;
    ev.mouseWheel.y = sf::Mouse::getPosition(*this).y;

    _sfEvents.push_back(ev);
    event->accept();
}

void qsf::QSFMLCanvas::mousePressEvent(QMouseEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::MouseButtonPressed;

    ev.mouseButton.button = (event->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
    ev.mouseButton.x = (int) event->localPos().x();
    ev.mouseButton.y = (int) event->localPos().y();

    _sfEvents.push_back(ev);
}

void qsf::QSFMLCanvas::mouseReleaseEvent(QMouseEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::MouseButtonReleased;

    ev.mouseButton.button = (event->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
    ev.mouseButton.x = (int) event->localPos().x();
    ev.mouseButton.y = (int) event->localPos().y();

    _sfEvents.push_back(ev);
}

void qsf::QSFMLCanvas::keyPressEvent(QKeyEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::KeyPressed;
    ev.key.code = qsf::QtKeyToSFML(event->key());

    _sfEvents.push_back(ev);
}

void qsf::QSFMLCanvas::keyReleaseEvent(QKeyEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::KeyReleased;
    ev.key.code = qsf::QtKeyToSFML(event->key());

    _sfEvents.push_back(ev);
}

void qsf::QSFMLCanvas::resizeEvent(QResizeEvent *event) {
    sf::Event ev;
    ev.type = sf::Event::Resized;
    ev.size = {
            static_cast<unsigned int>(event->size().width()),
            static_cast<unsigned int>(event->size().height())
    };

    _sfEvents.push_back(ev);
}

bool qsf::QSFMLCanvas::pollEvent(sf::Event &event) {
    if(_sfEvents.size() == 0)
        return false;

    event = _sfEvents.back();
    _sfEvents.pop_back();

    return true;
}
