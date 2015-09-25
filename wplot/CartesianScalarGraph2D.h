#ifndef WPLOT_CARTESIANSCALARGRAPH2D_H_
#define WPLOT_CARTESIANSCALARGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/CartesianGraph2D.h"
#include <QPolygonF>
#include <memory>
#include <functional>

namespace WPlot {

class WPLOTSHARED_EXPORT CartesianScalarGraph2D : public CartesianGraph2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<CartesianScalarGraph2D> Ptr;

public:

	CartesianScalarGraph2D();
	virtual ~CartesianScalarGraph2D() = default;
	void setData(const QPolygonF &data);
	void appendPoint(const QPointF &point);
	void appendPoint(const double &x, const double &y);
	void insertPoint(const int &index, const QPointF &point);
	void insertPoint(const int &index, const double &x, const double &y);
	void setColorFunction(const std::function<QColor(QPointF)> &colorFunction);

public:

	virtual void clear();

protected:

	QPolygonF m_data;
	std::function<QColor(QPointF)> m_colorFunction;
	bool m_colorFunctionDefined;
};

} // namespace WPlot

#endif // WPLOT_CARTESIANSCALARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CartesianScalarGraph2D
 *
 * This class is a base class for all plots that must be set with scalar values.
 *
 * A scalar value is a single \f$\left(x,y\right)\f$ coordinate.
 */
