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

	virtual QVector<double> getTicks() const = 0;

protected:

	double m_step;
	double m_lowerLimit;
	double m_upperLimit;
};

} // namespace Private
} // namespace WPlot

#endif // !WPLOT_PRIVATE_TICKSCALCULATOR_H_