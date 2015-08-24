#include "wplot/BarGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

BarGraph2D::BarGraph2D() :
	ScalarGraph2D(),
	m_lineColor(Qt::black),
	m_fillColor(Qt::white),
	m_lineWidth(1.0),
	m_barLength(1.0),
	m_barSizeType(SIZE_PIXELS),
	m_barLengthType(LENGTH_WIDTH)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_brush.setColor(m_fillColor);
}

/**
 * Set the line color.
 *
 * @param[in] color Color.
 */
void BarGraph2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

/**
 * Set the filling color.
 *
 * @param[in] color Color.
 */
void BarGraph2D::setFillColor(const QColor &color) {
	m_fillColor = color;
	m_brush.setColor(color);
}

/**
 * Set the line width in pixels.
 *
 * @param[in] width Width.
 */
void BarGraph2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

void BarGraph2D::setSpaceBetweenBars(const double &space, const SizeType &type) {
	m_barLength = space;
	m_barSizeType = type;
	m_barLengthType = LENGTH_SPACE;
}

void BarGraph2D::setBarWidth(const double &width, const SizeType &type) {
	m_barLength = width;
	m_barSizeType = type;
	m_barLengthType = LENGTH_WIDTH;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void BarGraph2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	painter.setPen(m_pen);
	painter.setBrush(m_brush);
	plot->initializePainter(painter);
	for (const auto& it : m_data) {

	}
}

} // namespace WPlot

