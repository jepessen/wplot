#include "wplot/Private/LinearTicksCalculator.h"
#include <cmath>

namespace WPlot {
namespace Private {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

LinearTicksCalculator::LinearTicksCalculator() :
	TicksCalculator() {
}

LinearTicksCalculator::LinearTicksCalculator(const double &step, const double &lower, const double &upper) :
	TicksCalculator(step, lower, upper) {
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * The method is an implementation of base class pure virtual one. It
 * calculates the list of ticks that lies between lower and upper limits.
 *
 * @return Tick coordinate list.
 */
QVector<double> LinearTicksCalculator::getTicks() const {
	QVector<double> ticks;
	double intDivision;
	modf(m_lowerLimit / m_step, &intDivision);
	double start = intDivision * m_step + m_step;
	if (start - m_step > m_lowerLimit) {
		start -= m_step;
	}
	const double end = m_upperLimit;
	for (double x = start; x < end; x += m_step) {
		ticks.append(x);
	}
	return ticks;
}

} // namespace Private
} // namespace WPlot
