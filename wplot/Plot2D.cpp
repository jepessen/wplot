#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

Plot2D::Plot2D(QWidget *parent) :
	Plot(parent),
	m_coordinateType(Plot2D::COORDINATE_WINDOW),
	m_upperLeftCorner(-1.0, 1.0),
	m_lowerRightCorner(1.0, -1.0),
	m_scaleX(1.0),
	m_scaleY(1.0)
{}

/**
 * Set the limits of the plot area.
 *
 * @param[in] upperLeftCorner Coordinetes of upper left corner.
 * @param[in] lowerRightCorner Coordinates of lower right corner.
 */
void Plot2D::setPlotLimits(const QPointF &upperLeftCorner, const QPointF &lowerRightCorner) {
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
void Plot2D::setPlotLimits(const double &xMin, const double &xMax, const double &yMin, const double &yMax) {
	m_upperLeftCorner.setX(xMin);
	m_upperLeftCorner.setY(yMax);
	m_lowerRightCorner.setX(xMax);
	m_lowerRightCorner.setY(yMin);
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

/**
 * Add a grid to the plot.
 *
 * @param[in] grid Grid that must be added.
 */
void Plot2D::addGrid(const Grid2D::Ptr &grid) {
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
void Plot2D::addGrid(const int &index, const Grid2D::Ptr &grid) {
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
 * Add a graph to plot. The graph will be set with highest available index, so
 * it will be the last to be drawn.
 *
 * @param[in] graph Graph to be added.
 */
void Plot2D::addGraph(const Graph::Ptr &graph) {
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
void Plot2D::addGraph(const int &index, const Graph::Ptr &graph) {
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
 * Set the coordinate type. This coordinate is used for layers and elements that
 * have to be set manually. Graph are shown instead using the origin and the zoom.
 *
 * @param[in] type Coordinate type.
 */
void Plot2D::setCoordinateType(const CoordinateType &type) {
	m_coordinateType = type;
}

/**
 * Retrieve the type of coordinates.
 *
 * @return Coordinate type.
 */
Plot2D::CoordinateType Plot2D::getCoordinateType() const {
	return m_coordinateType;
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

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Perform drawing. All layers will be drawn starting from the one with the
 * lowest index.
 *
 * @param event Painting event.
 */
void Plot2D::paintEvent(QPaintEvent * /*event*/) {
	initPainterCoordinates();
	drawBackground();
	drawGrids();
	drawGraphs();
	drawAxes();
	drawItems();
	drawBoundaries();
}

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

/**
 * Draw all grids that are added.
 */
void Plot2D::drawGrids() {
	for (auto& it : m_gridList) {
		it->drawLines(this);
	}
}

void Plot2D::drawAxes() {
	for (auto& it : m_axesList) {
		it->draw(this);
	}
}

/**
 * Draw grid boundaries.
 */
void Plot2D::drawBoundaries() {
	for (auto& it : m_gridList) {
		it->drawBoundary(this);
	}
}

/**
 * Draw all graphs that are added.
 */
void Plot2D::drawGraphs() {
	for (auto& it : m_graphList) {
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
