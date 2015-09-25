#ifndef WPLOT_CARTESIANSCATTERGRAPH2D_H_
#define WPLOT_CARTESIANSCATTERGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/CartesianScalarGraph2D.h"
#include "wplot/Item2D.h"
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CartesianScatterGraph2D : public CartesianScalarGraph2D
{

public:

	typedef std::shared_ptr<CartesianScatterGraph2D> Ptr;

public:
	CartesianScatterGraph2D();
	virtual ~CartesianScatterGraph2D() = default;
	void setItem(const Item2D::Ptr &item);

public:

	virtual void draw(Plot2D *plot);

private:

	Item2D::Ptr m_item;
};

} // namespace WPlot

#endif // WPLOT_CARTESIANSCATTERGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CartesianScatterGraph2D
 *
 * This class allows to define a graph in which a set of items are drawn at
 * data position. It's a scatter plot.
 */
