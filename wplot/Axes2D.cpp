#include "wplot/Axes2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Axes2D::Axes2D() :
	Layer2D(),
	m_axisXWidth(1.0),
	m_axisYWidth(1.0),
	m_axisXColor(Qt::black),
	m_axisYColor(Qt::black),
	m_axisXStyle(Qt::SolidLine),
	m_axisYStyle(Qt::SolidLine),
	m_origin(),
	m_ticks(nullptr) {
	m_axisXPen.setColor(m_axisXColor);
	m_axisXPen.setStyle(m_axisXStyle);
	m_axisXPen.setWidthF(m_axisXWidth);
	m_axisYPen.setColor(m_axisYColor);
	m_axisYPen.setStyle(m_axisYStyle);
	m_axisYPen.setWidthF(m_axisYWidth);
	m_axisX.setLineColor(m_axisXColor);
	m_axisX.setArrowLineColor(m_axisXColor);
	m_axisX.setArrowFillColor(m_axisXColor);
	m_axisX.setLineWidth(m_axisXWidth);
	m_axisX.setArrowLineWidth(m_axisXWidth);
	m_axisX.setLineStyle(m_axisXStyle);
	m_axisY.setLineColor(m_axisYColor);
	m_axisY.setArrowLineColor(m_axisYColor);
	m_axisY.setArrowFillColor(m_axisYColor);
	m_axisY.setLineWidth(m_axisYWidth);
	m_axisY.setArrowLineWidth(m_axisYWidth);
	m_axisY.setLineStyle(m_axisYStyle);
	m_axisX.setArrowWidth(10.0);
	m_axisX.setArrowLength(15.0);
	m_axisY.setArrowWidth(10.0);
	m_axisY.setArrowLength(15.0);
}

/**
 * Set ticks for axes. By default axes have no ticks and they must be
 * created and added manually.
 *
 * @param[in] ticks Ticks that must be drawn.
 */
void Axes2D::setTicks(const Ticks2D::Ptr &ticks) {
	m_ticks = ticks;
}

/**
 * Set the color for X axis.
 *
 * @param[in] color Color.
 */
void Axes2D::setAxisXColor(const QColor &color) {
	m_axisXColor = color;
	m_axisXPen.setColor(color);
	m_axisX.setLineColor(color);
	m_axisX.setArrowLineColor(color);
	m_axisX.setArrowFillColor(color);
}

/**
 * Set the color for Y axis.
 *
 * @param[in] color Color.
 */
void Axes2D::setAxisYColor(const QColor &color) {
	m_axisYColor = color;
	m_axisYPen.setColor(color);
	m_axisY.setLineColor(color);
	m_axisY.setArrowLineColor(color);
	m_axisY.setArrowFillColor(color);
}

/**
 * Set the same color for both axes.
 *
 * @param[in] color Color.
 */
void Axes2D::setAxesColor(const QColor &color) {
	setAxisXColor(color);
	setAxisYColor(color);
}

/**
 * Set the line style for the X axis.
 *
 * @param[in] style Line style.
 */
void Axes2D::setAxisXStyle(const Qt::PenStyle &style) {
	m_axisXStyle = style;
	m_axisXPen.setStyle(style);
	m_axisX.setLineStyle(style);
}

/**
 * Set the line style for the Y axis.
 *
 * @param[in] style Line style.
 */
void Axes2D::setAxisYStyle(const Qt::PenStyle &style) {
	m_axisYStyle = style;
	m_axisYPen.setStyle(style);
	m_axisY.setLineStyle(style);
}

/**
 * Set the line style for the both axes..
 *
 * @param[in] style Line style.
 */
void Axes2D::setAxesStyle(const Qt::PenStyle &style) {
	setAxisXStyle(style);
	setAxisYStyle(style);
}

/**
 * Set the line width for X axis.
 *
 * @param[in] width Width.
 */
void Axes2D::setAxisXWidth(const double &width) {
	m_axisXWidth = width;
	m_axisXPen.setWidthF(width);
	m_axisX.setLineWidth(width);
	m_axisX.setArrowLineWidth(width);
}

/**
 * Set the line width for Y axis.
 *
 * @param[in] width Width.
 */
void Axes2D::setAxisYWidth(const double &width) {
	m_axisYWidth = width;
	m_axisYPen.setWidthF(width);
	m_axisY.setLineWidth(width);
	m_axisY.setArrowLineWidth(width);
}

/**
 * Set the line width for both axes.
 *
 * @param[in] width Width.
 */
void Axes2D::setAxesWidth(const double &width) {
	setAxisXWidth(width);
	setAxisYWidth(width);
}

/**
 * Set the arrow width for the X axis.
 *
 * @image html arrow_width.svg "Arrow width"
 *
 * @param[in] width Width.
 */
void Axes2D::setAxisXArrowWidth(const double &width) {
	m_axisX.setArrowWidth(width);
}

/**
 * Set the arrow width for the Y axis.
 *
 * @image html arrow_width.svg "Arrow width"
 *
 * @param[in] width Width.
 */
void Axes2D::setAxisYArrowWidth(const double &width) {
	m_axisY.setArrowWidth(width);
}

/**
 * Set the arrow width for both axes.
 *
 * @image html arrow_width.svg "Arrow width"
 *
 * @param[in] width Width.
 */
void Axes2D::setAxesArrowWidth(const double &width) {
	setAxisXArrowWidth(width);
	setAxisYArrowWidth(width);
}

/**
 * Set the arrow length for the X axis.
 *
 * @image html arrow_length.svg "Arrow length"
 *
 * @param[in] length Length.
 */
void Axes2D::setAxisXArrowLength(const double &length) {
	m_axisX.setArrowLength(length);
}

/**
 * Set the arrow length for the Y axis.
 *
 * @image html arrow_length.svg "Arrow length"
 *
 * @param[in] length Length.
 */
void Axes2D::setAxisYArrowLength(const double &length) {
	m_axisY.setArrowLength(length);
}

/**
 * Set the arrow length for the both axes.
 *
 * @image html arrow_length.svg "Arrow length"
 *
 * @param[in] length Length.
 */
void Axes2D::setAxesArrowLength(const double &length) {
	setAxisXArrowLength(length);
	setAxisYArrowLength(length);
}

/**
 * Set arrow with and length at the same time for X axis.
 *
 * @param[in] width Width.
 * @param[in] length Length.
 */
void Axes2D::setAxisXArrowDimensions(const double &width, const double &length) {
	m_axisX.setArrowDimensions(width, length);
}

/**
 * Set arrow with and length at the same time for Y axis.
 *
 * @param[in] width Width.
 * @param[in] length Length.
 */
void Axes2D::setAxisYArrowDimensions(const double &width, const double &length) {
	m_axisY.setArrowDimensions(width, length);
}

/**
 * Set arrow with and length at the same time for both axes.
 *
 * @param[in] width Width.
 * @param[in] length Length.
 */
void Axes2D::setAxesArrowDimensions(const double &width, const double &length) {
	setAxisXArrowDimensions(width, length);
	setAxisYArrowDimensions(width, length);
}

/**
 * Set the coordinates for axes origin.
 *
 * @param[in] origin Origin coordinates.
 */
void Axes2D::setOrigin(const QPointF &origin) {
	m_origin = origin;
}

/**
 * Set the coordinates for axes origin.
 *
 * @param[in] x Origin X coordinate.
 * @param[in] y Origin Y coordinate.
 */
void Axes2D::setOrigin(const double &x, const double &y) {
	m_origin.setX(x);
	m_origin.setY(y);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void Axes2D::draw(Plot2D *plot) {
	//drawAxisXTicks(plot);
	//drawAxisYTicks(plot);
	drawTicks(plot);
	drawAxes(plot);
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw axes.
 *
 * @param[in] plot Plot where axes must be plotted.
 */
void Axes2D::drawAxes(Plot2D *plot) {
	const auto upperLeftCorner = plot->scalePoint(plot->getUpperLeftCorner());
	const auto lowerRightCorner = plot->scalePoint(plot->getLowerRightCorner());
	const auto origin = plot->scalePoint(m_origin);
	const double x = std::max(upperLeftCorner.x(), std::min(origin.x(), lowerRightCorner.x()));
	const double y = std::max(upperLeftCorner.y(), std::min(origin.y(), lowerRightCorner.y()));
	m_axisX.setPivot(upperLeftCorner.x(), y);
	m_axisX.setFinalPoint(lowerRightCorner.x(), y);
	m_axisY.setPivot(x, lowerRightCorner.y());
	m_axisY.setFinalPoint(x, upperLeftCorner.y());
	m_axisX.draw(plot);
	m_axisY.draw(plot);
}

/**
 * Draw ticks.
 *
 * @param[in] plot Plot where axes must be plotted.
 */
void Axes2D::drawTicks(Plot2D *plot) {
	if (m_ticks == nullptr) {
		return;
	}
	m_ticks->setOrigin(m_origin);
	m_ticks->draw(plot);
}

} // namespace WPlot
