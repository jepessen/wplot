#include "wplot/ScalarGraph2D.h"

namespace WPlot {

ScalarGraph2D::ScalarGraph2D() :
	Graph2D()
{}

/**
 * Set scalar data.
 *
 * @param[in] data Data.
 */
void ScalarGraph2D::setData(const QPolygonF &data) {
	m_data = data;
}

/**
 * Append a point that must be shown.
 *
 * @param[in] point Point.
 */
void ScalarGraph2D::appendPoint(const QPointF &point) {
	m_data.append(point);
}

/**
 * Append a point that must be shown.
 *
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void ScalarGraph2D::appendPoint(const double &x, const double &y) {
	m_data.append(QPointF(x, y));
}

/**
 * Insert a point at specified index.
 *
 * @param[in] index Index.
 * @param[in] point Point.
 */
void ScalarGraph2D::insertPoint(const int &index, const QPointF &point) {
	m_data.insert(index, point);
}

/**
 * Insert a point at specified index.
 *
 * @param[in] index Index.
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void ScalarGraph2D::insertPoint(const int &index, const double &x, const double &y) {
	m_data.insert(index, QPointF(x, y));
}

/**
 * Clear all data.
 */
void ScalarGraph2D::clear() {
	m_data.clear();
}

} // namespace WPlot
