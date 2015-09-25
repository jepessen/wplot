#include "wplot/PolarPlot2D.h"

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

PolarPlot2D::PolarPlot2D(QWidget *parent) :
	Plot2D(parent),
	m_minRadius(0.0),
	m_maxRadius(1.0),
	m_screenRadius(double()),
	m_graphBackground(nullptr)
{}

void PolarPlot2D::setRadiusLimits(const double &rMin, const double &rMax) {
	m_minRadius = rMin;
	m_maxRadius = rMax;
}

std::pair<double, double> PolarPlot2D::getRadiusLimits() const {
	std::pair<double, double> res;
	res.first = m_minRadius;
	res.second = m_maxRadius;
	return res;
}

void PolarPlot2D::setGraphBackground(const Background::Ptr &background) {
	m_graphBackground = background;
}

/**
 * Add a grid to the plot.
 *
 * @param[in] grid Grid that must be added.
 */
void PolarPlot2D::addGrid(const PolarGrid2D::Ptr &grid) {
	if (grid == nullptr) {
		return;
	}
	m_gridList.append(grid);
}

/**
 * Add a grid to the plot at specified index.
 *
 * @param[in] index Index.
 * @param[in] grid Grid that must be added.
 */
void PolarPlot2D::addGrid(const int &index, const PolarGrid2D::Ptr &grid) {
	if (grid == nullptr) {
		return;
	}
	if (index > m_gridList.size()) {
		m_gridList.append(grid);
	} else if (index < 0) {
		m_gridList.prepend(grid);
	} else {
		m_gridList.insert(index, grid);
	}
}

/**
 * Add a graph to plot. The graph will be set with highest available index, so
 * it will be the last to be drawn.
 *
 * @param[in] graph Graph to be added.
 */
void PolarPlot2D::addGraph(const PolarGraph2D::Ptr &graph) {
	if (graph == nullptr) {
		return;
	}
	m_graphList.append(graph);
}

/**
 * Insert a graph in specified position. If a graph exists in that position, it
 * will be moved before it. If an out-of-range index is given, the graph will be
 * put in first or last position.
 *
 * @param[in] index Position index.
 * @param[in] graph Graph to be added.
 */
void PolarPlot2D::addGraph(const int &index, const PolarGraph2D::Ptr &graph) {
	if (graph == nullptr) {
		return;
	}
	if (index > m_graphList.size()) {
		m_graphList.append(graph);
	} else if (index < 0) {
		m_graphList.prepend(graph);
	} else {
		m_graphList.insert(index, graph);
	}
}

QPointF PolarPlot2D::scalePolarPoint(const QPointF &point) const {
	const double radiusMultiplier = (point.y() - m_minRadius) / (m_maxRadius - m_minRadius);
	const double scaledRadius = m_screenRadius * radiusMultiplier;
	const double x = m_screenCenter.x() + scaledRadius * sin(point.x());
	const double y = m_screenCenter.y() + scaledRadius * cos(point.x());
	return QPointF(x, y);
}

QPointF PolarPlot2D::scalePolarPoint(const double &angle, const double &radius) const {
	const double radiusMultiplier = (radius - m_minRadius) / (m_maxRadius - m_minRadius);
	const double scaledRadius = m_screenRadius * radiusMultiplier;
	const double x = m_screenCenter.x() + scaledRadius * sin(angle);
	const double y = m_screenCenter.y() + scaledRadius * cos(angle);
	return QPointF(x, y);
}


///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Perform drawing. All layers will be drawn starting from the one with the
 * lowest index.
 *
 * @param event Painting event.
 */
void PolarPlot2D::paintEvent(QPaintEvent * /*event*/) {
	initPainterCoordinates();
	updateScreenData();
	drawBackground();
	drawGraphBackground();
	drawGrids();
	drawGraphs();
	//drawAxes();
	//drawItems();
	drawBoundaries();
}

void PolarPlot2D::drawGraphBackground() {
	if (nullptr == m_graphBackground) {
		return;
	}
	const auto backgroundType = m_graphBackground->getType();
	QBrush brush;
	switch (backgroundType) {
		case Background::FLAT : {
			brush = QBrush(m_graphBackground->getColor());
		} break;
		case Background::GRADIENT : {
			brush = QBrush(m_graphBackground->getGradient());
		} break;
		default : {
			return;
		}
	}
	QPainter painter(this);
	painter.setBrush(brush);
	painter.drawEllipse(m_screenCenter, m_screenRadius, m_screenRadius);
}

/**
 * Draw all grids that are added.
 */
void PolarPlot2D::drawGrids() {
	for (auto& it : m_gridList) {
		it->drawLines(this);
	}
}

/**
 * Draw all graphs that are added.
 */
void PolarPlot2D::drawGraphs() {
	for (auto& it : m_graphList) {
		it->draw(this);
	}
}

/**
 * Draw grid boundaries.
 */
void PolarPlot2D::drawBoundaries() {
	for (auto& it : m_gridList) {
		it->drawBoundary(this);
	}
}

void PolarPlot2D::updateScreenData() {
	const double screenSemiHeight = height() * 0.5;
	const double screenSemiWidth = width() * 0.5;
	m_screenCenter.setX(screenSemiWidth);
	m_screenCenter.setY(screenSemiHeight);
	const auto screenPadding = getPixelPadding();
	const double screenHorizontalRadius = screenSemiWidth - std::max(screenPadding.left, screenPadding.right);
	const double screenVerticalRadius = screenSemiHeight - std::max(screenPadding.top, screenPadding.bottom);
	m_screenRadius = std::min(screenHorizontalRadius, screenVerticalRadius);
}

} // namespace WPlot
