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