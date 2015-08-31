#ifndef WPLOT_PRIVATE_TICKSCALCULATOR_H_
#define WPLOT_PRIVATE_TICKSCALCULATOR_H_

#include <memory>
#include <QVector>

namespace WPlot {

class Plot2D;

namespace Private {

class TicksCalculator {

public:

	typedef std::shared_ptr<TicksCalculator> Ptr;

public:

	TicksCalculator();
	TicksCalculator(const double &step, const double &lower, const double &upper);
	virtual ~TicksCalculator() = default;

	void setStep(const double &step);
	void setLowerLimit(const double &limit);
	void setUpperLimit(const double &limit);
	void setLimits(const double &lower, const double &upper);

public:

	/**
	 * This method must be implemented in derived classes and allows to calculate
	 * ticks between lower and upper limits.
	 *
	 * @return List of tick coordinates.
	 */
	virtual QVector<double> getTicks() const = 0;

protected:

	double m_step;
	double m_lowerLimit;
	double m_upperLimit;
};

} // namespace Private
} // namespace WPlot

#endif // !WPLOT_PRIVATE_TICKSCALCULATOR_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Private::TicksCalculator
 *
 * This base class allows to calculate places where ticks should be places in
 * all plot.
 *
 * Ticks placement means that given a step, we can calculate positions of every
 * tick. Step can have different meaning considering the different calculator
 * type. The logic must be implemented in derived classes in getTick() method.
 *
 * Here the user should put the logic that allows to calculate tick coordinates.
 *
 * This class calculate ticks in one axis.
 */
