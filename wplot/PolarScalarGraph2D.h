#ifndef WPLOT_POLARSCALARGRAPH2D_H_
#define WPLOT_POLARSCALARGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/PolarGraph2D.h"
#include <QPolygonF>
#include <memory>
#include <functional>

namespace WPlot {

class WPLOTSHARED_EXPORT PolarScalarGraph2D : public PolarGraph2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<PolarScalarGraph2D> Ptr;

public:

	PolarScalarGraph2D();
	virtual ~PolarScalarGraph2D() = default;
	void setData(const QPolygonF &data);
	void appendPoint(const double &angle, const double &radius);
	void insertPoint(const int &index, const double &angle, const double &radius);
	void setColorFunction(const std::function<QColor(const double&, const double&)> &colorFunction);

public:

	virtual void clear();

protected:

	QPolygonF m_data;
	std::function<QColor(const double&, const double&)> m_colorFunction;
	bool m_colorFunctionDefined;
};

} // namespace WPlot

#endif // WPLOT_POLARSCALARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::PolarScalarGraph2D
 *
 * This class is a base class for all plots that must be set with scalar values.
 *
 * A scalar value is a single \f$\left(x,y\right)\f$ coordinate.
 */
