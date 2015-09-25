#include "wplot/CartesianPlot2D.h"

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

CartesianPlot2D::CartesianPlot2D(QWidget *parent) :
	Plot2D(parent)
{}

/**
 * Add a grid to the plot.
 *
 * @param[in] grid Grid that must be added.
 */
void CartesianPlot2D::addGrid(const CartesianGrid2D::Ptr &grid) {
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
void CartesianPlot2D::addGrid(const int &index, const CartesianGrid2D::Ptr &grid) {
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
void CartesianPlot2D::addGraph(const CartesianGraph2D::Ptr &graph) {
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
void CartesianPlot2D::addGraph(const int &index, const CartesianGraph2D::Ptr &graph) {
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


/**
 * Set the limits of the plot area.
 *
 * @param[in] upperLeftCorner Coordinetes of upper left corner.
 * @param[in] lowerRightCorner Coordinates of lower right corner.
 */
void CartesianPlot2D::setPlotLimits(const QPointF &upperLeftCorner, const QPointF &lowerRightCorner) {
	m_upperLeftCorner = upperLeftCorner;
	m_lowerRightCorner = lowerRightCorner;
}

/**
 * Set the limits of the plot area.
 *
 * @param[in] xMin Minimum X value.
 * @param[in] xMax Maximum X value.
 * @param[in] yMin Minimym Y value.
 * @param[in] yMax Maximym Y value.
 */
void CartesianPlot2D::setPlotLimits(const double &xMin, const double &xMax, const double &yMin, const double &yMax) {
	m_upperLeftCorner.setX(xMin);
	m_upperLeftCorner.setY(yMax);
	m_lowerRightCorner.setX(xMax);
	m_lowerRightCorner.setY(yMin);
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
void CartesianPlot2D::paintEvent(QPaintEvent * /*event*/) {
	initPainterCoordinates();
	drawBackground();
	drawGrids();
	drawGraphs();
	drawAxes();
	drawItems();
	drawBoundaries();
}

/**
 * Draw all grids that are added.
 */
void CartesianPlot2D::drawGrids() {
	for (auto& it : m_gridList) {
		it->drawLines(this);
	}
}

/**
 * Draw grid boundaries.
 */
void CartesianPlot2D::drawBoundaries() {
	for (auto& it : m_gridList) {
		it->drawBoundary(this);
	}
}

/**
 * Draw all graphs that are added.
 */
void CartesianPlot2D::drawGraphs() {
	for (auto& it : m_graphList) {
		it->draw(this);
	}
}

} // namespace WPlot
