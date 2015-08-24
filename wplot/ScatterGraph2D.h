#ifndef WPLOT_SCATTERGRAPH2D_H_
#define WPLOT_SCATTERGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/ScalarGraph2D.h"
#include "wplot/Item2D.h"
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT ScatterGraph2D : public ScalarGraph2D
{

public:

	typedef std::shared_ptr<ScatterGraph2D> Ptr;

public:
	ScatterGraph2D();
	virtual ~ScatterGraph2D() = default;
	void setItem(const Item2D::Ptr &item);

public:

	virtual void draw(Plot2D *plot);

private:

	Item2D::Ptr m_item;
};

} // namespace WPlot

#endif // WPLOT_SCATTERGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::ScatterGraph2D
 *
 * This class allows to define a graph in which a set of items are drawn at
 * data position. It's a scatter plot.
 */
