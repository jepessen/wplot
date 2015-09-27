#ifndef WPLOT_POLARGRAPH2D_H_
#define WPLOT_POLARGRAPH2D_H_

#include "wplot/Graph2D.h"

namespace WPlot {

class PolarGraph2D : public Graph2D
{
public:

	typedef std::shared_ptr<PolarGraph2D> Ptr;

public:
	PolarGraph2D();
	virtual ~PolarGraph2D() = default;
};

} // namespace WPlot

#endif // WPLOT_POLARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::PolarGraph2D
 *
 * This class is a base class for all 2D polar plots.
 */
