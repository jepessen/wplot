#include "wplot/Private/TicksCalculator.h"
#include "wplot/Plot2D.h"

namespace WPlot {
namespace Private {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

TicksCalculator::TicksCalculator() :
	m_step(1.0),
	m_lowerLimit(-1.0),
	m_upperLimit(1.0) {
}

TicksCalculator::TicksCalculator(const double &step, const double &lower, const double &upper) :
	m_step(step),
	m_lowerLimit(lower),
	m_upperLimit(upper) {
}

/**
 * Set the step value used for tick distantiation.
 *
 * @param[in] step Step.
 */
void TicksCalculator::setStep(const double &step) {
	m_step = step;
}

/**
 * Set the lower limit of the range in which ticks must be drawn.
 *
 * @param[in] limit Lower limit.
 */
void TicksCalculator::setLowerLimit(const double &limit) {
	m_lowerLimit = limit;
}

/**
 * Set the upper limit of the range in which ticks must be drawn.
 *
 * @param[in] limit Upper limit.
 */
void TicksCalculator::setUpperLimit(const double &limit) {
	m_upperLimit = limit;
}

/**
 * Set both lower and upper limits at once.
 *
 * @param[in] lower Lower limit.
 * @param[in] upper Upper limit.
 */
void TicksCalculator::setLimits(const double &lower, const double &upper) {
	setLowerLimit(lower);
	setUpperLimit(upper);
}

} // namespace Private
} // namespace WPlot
