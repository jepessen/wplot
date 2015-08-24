#ifndef WPLOT_GRAPH_H_
#define WPLOT_GRAPH_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT Graph : public Layer2D
{
public:

	typedef std::shared_ptr<Graph> Ptr;

public:

	Graph();
	virtual ~Graph() = default;

public:

	virtual void clear() = 0;

protected:

	void setClipRegion(QPainter &painter, Plot2D *plot);
};

} // namespace WPlot

#endif // WPLOT_GRAPH_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Graph
 *
 * This class represent a base class for all graphs that can be drawn inside the
 * library. Its main purpose is to give basic operation that are common to all
 * graph types.
 */
