#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

Plot2D::Plot2D(QWidget *parent) :
	Plot(parent),
	m_upperLeftCorner(-1.0, 1.0),
	m_lowerRightCorner(1.0, -1.0),
	m_scaleX(1.0),
	m_scaleY(1.0)
{}

/**
 * Add a axes to the plot.
 *
 * @param[in] axes Axes that must be added.
 */
void Plot2D::addAxes(const Axes2D::Ptr &axes) {
	if (axes == nullptr) {
		return;
	}
	m_axesList.append(axes);
}

/**
 * Add axes to the plot at specified index.
 *
 * @param[in] index Index.
 * @param[in] axes Axes that must be added.
 */
void Plot2D::addAxes(const int &index, const Axes2D::Ptr &axes) {
	if (axes == nullptr) {
		return;
	}
	if (index > m_axesList.size()) {
		m_axesList.append(axes);
	} else if (index < 0) {
		m_axesList.prepend(axes);
	} else {
		m_axesList.insert(index, axes);
	}
}

/**
 * Add an item to the plot. The item will be drawn above graphs.
 *
 * @param[in] item Item.
 */
void Plot2D::addItem(const Item2D::Ptr &item) {
	if (item == nullptr) {
		return;
	}
	m_itemList.append(item);
}

/**
 * Add an item to the plot at specified index. The item will be
 * drawn above graphs.
 *
 * @param[in] index Index.
 * @param[in] item Item.
 */
void Plot2D::addItem(const int &index, const Item2D::Ptr &item) {
	if (item == nullptr) {
		return;
	}
	if (index > m_itemList.size()) {
		m_itemList.append(item);
	} else if (index < 0) {
		m_itemList.prepend(item);
	} else {
		m_itemList.insert(index, item);
	}
}

/**
 * Retrieve the plot origin in widget coordinates.
 *
 * @return Origin.
 */
QPointF Plot2D::getScreenOrigin() const {
	return QPointF(m_screenOriginX, m_screenOriginY);
}

/**
 * Retrieve the scale factor for X coordiate.
 *
 * @return Scale factor.
 */
double Plot2D::getScaleX() const {
	return m_scaleX;
}

/**
 * Retrieve the scale factor for Y coordiate.
 *
 * @return Scale factor.
 */
double Plot2D::getScaleY() const {
	return m_scaleY;
}

/**
 * Retrieve the scaled point from plot coordinates to widget coordinates.
 *
 * @param[in] point Point in plot coordinates.
 *
 * @return Point in widget coordinates.
 */
QPointF Plot2D::scalePoint(const QPointF &point) const {
	return scalePoint(point.x(), point.y());
}

/**
 * Retrieve the scaled point from plot coordinates to widget coordinates.
 *
 * @param[in] x \f$X\f$ coordinate.
 * @param[in] y \f$Y\f$ coordinate.
 *
 * @return Point in widget coordinates.
 */
QPointF Plot2D::scalePoint(const double &x, const double &y) const {
	const double sx = scalePointX(x);
	const double sy = scalePointY(y);
	return QPointF(sx, sy);
}

/**
 * Scale the \f$X\f$ coordinate from plot coordinates to widget coordinates.
 *
 * @param[in] x \f$X\f$ coordinate.
 *
 * @return Scaled coordinate.
 */
double Plot2D::scalePointX(const double &x) const {
	const double paddingLeft = m_padding.getLeftPadding(Padding::PIXELS);
	const double paddingRight = m_padding.getRightPadding(Padding::PIXELS);
	const double multX = paddingLeft + paddingRight - width();
	const double fracX = (x - m_upperLeftCorner.x()) / (m_upperLeftCorner.x() - m_lowerRightCorner.x());
	return paddingLeft + multX * fracX;
}

/**
 * Scale the \f$Y\f$ coordinate from plot coordinates to widget coordinates.
 *
 * @param[in] y \f$Y\f$ coordinate.
 *
 * @return Scaled coordinate.
 */
double Plot2D::scalePointY(const double &y) const {
	const double paddingBottom = m_padding.getBottomPadding(Padding::PIXELS);
	const double paddingTop = m_padding.getTopPadding(Padding::PIXELS);
	const double multY = paddingBottom + paddingTop - height();
	const double fracY = (y - m_lowerRightCorner.y()) / (m_lowerRightCorner.y() - m_upperLeftCorner.y());
	return height() - paddingBottom - multY * fracY;
}

/**
 * Scale the given point from widget coordinates to plot coordinates.
 *
 * @param[in] point Point.
 *
 * @return Scaled point in plot coordinates.
 */
QPointF Plot2D::inverseScalePoint(const QPointF &point) const {
	return inverseScalePoint(point.x(), point.y());
}

/**
 * Scale the given point from widget coordinates to plot coordinates.
 *
 * @param[in] x X coordinate.
 * @param[in] y Y coordinate.
 *
 * @return Scaled point in plot coordinates.
 */
QPointF Plot2D::inverseScalePoint(const double &x, const double &y) const {
	return QPointF(inverseScalePointX(x), inverseScalePointY(y));
}

/**
 * Scale the coordiante in X axis from widget coordinates to plot coordinates.
 *
 * @param[in] x X coordinate.
 *
 * @return Scaled coordinate in plot coordinates.
 */
double Plot2D::inverseScalePointX(const double &x) const {
	const double paddingLeft = m_padding.getLeftPadding(Padding::PIXELS);
	const double paddingRight = m_padding.getRightPadding(Padding::PIXELS);
	const double multX = paddingLeft + paddingRight - width();
	const double a = m_upperLeftCorner.x();
	const double b = m_lowerRightCorner.x();
	const double num1 = a * (multX - paddingLeft + x);
	const double num2 = b * (paddingLeft - x);
	return (num1 + num2) / multX;
}

/**
 * Scale the coordiante in Y axis from widget coordinates to plot coordinates.
 *
 * @param[in] y Y coordinate.
 *
 * @return Scaled coordinate in plot coordinates.
 */
double Plot2D::inverseScalePointY(const double &y) const {
	const double paddingBottom = m_padding.getBottomPadding(Padding::PIXELS);
	const double paddingTop = m_padding.getTopPadding(Padding::PIXELS);
	const double multY = paddingBottom + paddingTop - height();
	const double a = m_lowerRightCorner.y();
	const double b = m_upperLeftCorner.y();
	const double num1 = a * (height() + multY - paddingBottom - y);
	const double num2 = b * (paddingBottom - height() + y);
	return (num1 + num2) / multY;
}

/**
 * Retrieve the upper left corner.
 *
 * @return Corner coordinates.
 */
QPointF Plot2D::getUpperLeftCorner() const {
	return m_upperLeftCorner;
}

/**
 * Retrieve the lower right corner.
 *
 * @return Corner coordinates.
 */
QPointF Plot2D::getLowerRightCorner() const {
	return m_lowerRightCorner;
}

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Initialize coordinate conversion. To be used before paint anything.
 */
void Plot2D::initPainterCoordinates() {
	const double dx = m_upperLeftCorner.x() - m_lowerRightCorner.x();
	const double dy = m_lowerRightCorner.y() - m_upperLeftCorner.y();
	m_padding.setSize(static_cast<double>(width()), static_cast<double>(height()));
	const Padding::Values paddingValues = m_padding.getPaddingValues(Padding::PIXELS);
	m_scaleX = (static_cast<double>(width()) * (1.0 - paddingValues.left - paddingValues.right)) / -dx;
	m_scaleY = (static_cast<double>(height()) * (1.0 - paddingValues.bottom - paddingValues.top)) / -dy;
	m_screenOriginX = scalePointX(0.0);
	m_screenOriginY = scalePointY(0.0);
}

void Plot2D::drawAxes() {
	for (auto& it : m_axesList) {
		it->draw(this);
	}
}

/**
 * Draw all items that are added.
 */
void Plot2D::drawItems() {
	for (auto& it : m_itemList) {
		it->draw(this);
	}
}

} // namespace WPlot
