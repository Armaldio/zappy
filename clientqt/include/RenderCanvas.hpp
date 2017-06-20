//
//-----------------------------------------------------------------------------
//Filename:    RenderCanvas.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_RENDERCANVAS_HPP
#define CLIENTQT_RENDERCANVAS_HPP

#include "QSFML/QSFMLWidget.hpp"

namespace zappy {
    class RenderCanvas : public qsf::QSFMLCanvas {
    public:
        RenderCanvas(QWidget *parent, const QPoint &position, const QSize &size,
                     const unsigned int timeFrame);

        virtual ~RenderCanvas();

    protected:
        void OnUpdate() override;

        void OnInit() override;

        void OnDestroy() override;
    };
}


#endif //CLIENTQT_RENDERCANVAS_HPP
