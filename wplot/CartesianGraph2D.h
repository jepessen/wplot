#ifndef WPLOT_CARTESIANGRAPH2D_H_
#define WPLOT_CARTESIANGRAPH2D_H_

#include "wplot/Graph2D.h"

namespace WPlot {

class CartesianGraph2D : public Graph2D
{
public:

	typedef std::shared_ptr<CartesianGraph2D> Ptr;

public:
	CartesianGraph2D();
	virtual ~CartesianGraph2D() = default;
};

} // namespace WPlot

#endif // WPLOT_CARTESIANGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CartesianGraph2D
 *
 * This class is a base class for all 2D cartesian plots.
 */
