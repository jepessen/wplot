#ifndef WPLOT_PRIVATE_LINEARTICKSCALCULATOR_H_
#define WPLOT_PRIVATE_LINEARTICKSCALCULATOR_H_

#include "wplot/Private/TicksCalculator.h"

namespace WPlot {

class Plot2D;

namespace Private {

class LinearTicksCalculator : public TicksCalculator {

public:

	typedef std::shared_ptr<LinearTicksCalculator> Ptr;

public:

	LinearTicksCalculator();
	LinearTicksCalculator(const double &step, const double &lower, const double &upper);
	virtual ~LinearTicksCalculator() = default;

public:

	virtual QVector<double> getTicks() const;
};

} // namespace Private
} // namespace WPlot

#endif // !WPLOT_PRIVATE_LINEARTICKSCALCULATOR_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Private::LinearTicksCalculator
 *
 * This class is a specialization of TicksCalculator that allows to calculate
 * ticks in a linear scale.
 *
 * @image html ruler.svg "Ticks inside lower and upper limits."
 *
 * Considering the image, we can see the axis with lower and upper limits that
 * are set. Ticks start from axis origin and go to the right (and to the left
 * as well). The distance between two ticks is always the same and is equal to
 * step that we set.
 *
 * The ticks that this class returns are the ones that are between lower and
 * upper limit.
 */