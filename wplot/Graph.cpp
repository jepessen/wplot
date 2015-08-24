#include "wplot/Graph.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Graph::Graph() :
	Layer2D()
{}

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Set the clip region for specified painter. The clip region is the widget
 * portion in which we can draw. For a plot, is the region of the widget that
 * stay inside the padding area.
 *
 * @param[inout] painter Painter for which clip region must be specified.
 * @param[in] plot Plot.
 */
void Graph::setClipRegion(QPainter &painter, Plot2D *plot) {
	QPoint upperLeftCorner = plot->scalePoint(plot->getUpperLeftCorner()).toPoint();
	QPoint lowerRightCorner = plot->scalePoint(plot->getLowerRightCorner()).toPoint();
	upperLeftCorner.setY(plot->height() - lowerRightCorner.y());
	lowerRightCorner.setX(plot->width() - upperLeftCorner.x());
	QRegion clipRegion(QRect(upperLeftCorner, lowerRightCorner));
	painter.setClipRegion(clipRegion);
}

} // namespace WPlot
