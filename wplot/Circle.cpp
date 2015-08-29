#include "wplot/Circle.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Circle::Circle() :
	Item2D(),
	m_radius(1.0),
	m_fillColor(Qt::white),
	m_lineColor(Qt::black),
	m_lineStyle(Qt::SolidLine),
	m_lineWidth(1.0)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_pen.setStyle(m_lineStyle);
	m_brush.setColor(m_fillColor);
	m_brush.setStyle(Qt::SolidPattern);
}

/**
 * Set circle radius.
 *
 * @param[in] radius Radius.
 */
void Circle::setRadius(const double &radius) {
	m_radius = radius;
}

/**
 * Set the color of the circumference.
 *
 * @param[in] color Color.
 */
void Circle::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

/**
 * @brief Circle::setFillColor
 * @param color
 */
void Circle::setFillColor(const QColor &color) {
	m_fillColor = color;
	m_brush.setColor(color);
}

/**
 * Set the width of circunference line in pixels.
 *
 * @param[in] width Width.
 */
void Circle::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

/**
 * Set the style of circunference line.
 *
 * @param[in] style Style.
 */
void Circle::setLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the circle in specified plot.
 *
 * @param[in] plot Plot where circle must be drawn.
 */
void Circle::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	painter.setPen(m_pen);
	painter.setBrush(m_brush);
	const QPointF center = getScaledPosition(m_pivot, plot);
	const double radiusX = getScaledDimensionX(m_radius, plot);
	const double radiusY = getScaledDimensionY(m_radius, plot);
	painter.drawEllipse(center, radiusX, radiusY);
}

} // namespace WPlot
