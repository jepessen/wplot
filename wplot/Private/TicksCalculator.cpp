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

void TicksCalculator::setStep(const double &step) {
	m_step = step;
}

void TicksCalculator::setLowerLimit(const double &limit) {
	m_lowerLimit = limit;
}

void TicksCalculator::setUpperLimit(const double &limit) {
	m_upperLimit = limit;
}

void TicksCalculator::setLimits(const double &lower, const double &upper) {
	setLowerLimit(lower);
	setUpperLimit(upper);
}

} // namespace Private
} // namespace WPlot
