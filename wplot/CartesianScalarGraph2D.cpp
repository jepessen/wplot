#include "wplot/CartesianScalarGraph2D.h"

namespace WPlot {

CartesianScalarGraph2D::CartesianScalarGraph2D() :
	CartesianGraph2D(),
	m_colorFunctionDefined(false),
	m_colorFunction(nullptr)
{}

/**
 * Set scalar data.
 *
 * @param[in] data Data.
 */
void CartesianScalarGraph2D::setData(const QPolygonF &data) {
	m_data = data;
}

/**
 * Append a point that must be shown.
 *
 * @param[in] point Point.
 */
void CartesianScalarGraph2D::appendPoint(const QPointF &point) {
	m_data.append(point);
}

/**
 * Append a point that must be shown.
 *
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void CartesianScalarGraph2D::appendPoint(const double &x, const double &y) {
	m_data.append(QPointF(x, y));
}

/**
 * Insert a point at specified index.
 *
 * @param[in] index Index.
 * @param[in] point Point.
 */
void CartesianScalarGraph2D::insertPoint(const int &index, const QPointF &point) {
	m_data.insert(index, point);
}

/**
 * Insert a point at specified index.
 *
 * @param[in] index Index.
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void CartesianScalarGraph2D::insertPoint(const int &index, const double &x, const double &y) {
	m_data.insert(index, QPointF(x, y));
}

/**
 * Clear all data.
 */
void CartesianScalarGraph2D::clear() {
	m_data.clear();
}

void CartesianScalarGraph2D::setColorFunction(const std::function<QColor(QPointF)> &colorFunction) {
	m_colorFunction = colorFunction;
	m_colorFunctionDefined = true;
}

} // namespace WPlot
