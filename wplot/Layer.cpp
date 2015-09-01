#include "wplot/Layer.h"
#include "wplot/Plot.h"

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

Layer::Layer() :
	m_usePaddingArea(false)
{}

/**
 * By default a painter can draw in all widget area. Sometime is useful to limit
 * the drawing area to the padded one. The padding area is the widget area inside
 * padding border in the central widget. This method allows to set the painter
 * in order to use only padded area.
 *
 * @param[in] plot Plot.
 */
void Layer::setDrawingInPaddingArea(const bool &limit) {
	m_usePaddingArea = limit;
}

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Initialize a painter. This should be called before drawing.
 *
 * @param[inout] painter Painter.
 * @param[in] plot Plot.
 */
void Layer::initPainter(QPainter &painter, Plot* plot) {
	if (true == plot->getAntialiasingFlag()) {
		painter.setRenderHint(QPainter::Antialiasing);
	}
}

/**
 * Set the corresponding painter to be able to draw only inside the
 * padded area.
 *
 * @param[inout] painter Painter.
 * @param[inout] plot Plot.
 */
void Layer::limitPainterInPaddingArea(QPainter &painter, Plot *plot) {
	if (true == m_usePaddingArea) {
		const auto padding = plot->getPixelPadding();
		const double w = plot->width() - padding.left - padding.right;
		const double h = plot->height() - padding.top - padding.bottom;
		painter.setClipRect(padding.left, padding.top, w, h);
	}
}

} // namespace WPlot
