//
//-----------------------------------------------------------------------------
//Filename:    QSFMLCanvas.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_QSFMLCANVAS_HPP
#define CLIENTQT_QSFMLCANVAS_HPP


#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>

namespace qsf {
    class QSFMLCanvas : public QWidget, public sf::RenderWindow {
    public:
        QSFMLCanvas(QWidget *parent, const QPoint& position, const QSize& size, const unsigned int timeFrame);

        virtual ~QSFMLCanvas();

        QPaintEngine *paintEngine() const override;

    protected:
        virtual void paintEvent(QPaintEvent *event);

        virtual void showEvent(QShowEvent *event);

        virtual void wheelEvent(QWheelEvent *event);

        virtual void mousePressEvent(QMouseEvent *event);

        virtual void mouseReleaseEvent(QMouseEvent *event);

        virtual void keyPressEvent(QKeyEvent *event);

        virtual void keyReleaseEvent(QKeyEvent *event);

        virtual void resizeEvent(QResizeEvent *event);

        virtual void mouseMoveEvent(QMouseEvent *event);

        virtual void OnUpdate();

        virtual void OnInit();

        virtual void OnDestroy();

        bool pollEvent(sf::Event& event);

    protected:
        QTimer _timer;
        bool _initialized;
        std::vector<sf::Event> _sfEvents;
    };
};


#endif //CLIENTQT_QSFMLCANVAS_HPP
