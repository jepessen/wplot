#include "wplot/ScalarGraph2D.h"

namespace WPlot {

ScalarGraph2D::ScalarGraph2D() :
	Graph2D()
{}

void ScalarGraph2D::setData(const QPolygonF &data) {
	m_data = data;
}

void ScalarGraph2D::appendPoint(const QPointF &point) {
	m_data.append(point);
}

void ScalarGraph2D::appendPoint(const double &x, const double &y) {
	m_data.append(QPointF(x, y));
}

void ScalarGraph2D::insertPoint(const int &index, const QPointF &point) {
	m_data.insert(index, point);
}

void ScalarGraph2D::insertPoint(const int &index, const double &x, const double &y) {
	m_data.insert(index, QPointF(x, y));
}

void ScalarGraph2D::clear() {
	m_data.clear();
}

} // namespace WPlot
