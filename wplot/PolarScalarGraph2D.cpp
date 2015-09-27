#include "wplot/PolarScalarGraph2D.h"

namespace WPlot {

PolarScalarGraph2D::PolarScalarGraph2D() :
	PolarGraph2D(),
	m_colorFunctionDefined(false),
	m_colorFunction(nullptr)
{}

/**
 * Set scalar data.
 *
 * @param[in] data Data.
 */
void PolarScalarGraph2D::setData(const QPolygonF &data) {
	m_data = data;
}

/**
 * Append a point that must be shown.
 *
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void PolarScalarGraph2D::appendPoint(const double &angle, const double &radius) {
	m_data.append(QPointF(angle, radius));
}

/**
 * Insert a point at specified index.
 *
 * @param[in] index Index.
 * @param[in] x Point X coordinate.
 * @param[in] y Point Y coordinate.
 */
void PolarScalarGraph2D::insertPoint(const int &index, const double &angle, const double &radius) {
	m_data.insert(index, QPointF(angle, radius));
}

/**
 * Clear all data.
 */
void PolarScalarGraph2D::clear() {
	m_data.clear();
}

void PolarScalarGraph2D::setColorFunction(const std::function<QColor(const double&, const double&)> &colorFunction) {
	m_colorFunction = colorFunction;
	m_colorFunctionDefined = true;
}

} // namespace WPlot
