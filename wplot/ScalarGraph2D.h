#ifndef WPLOT_SCALARGRAPH2D_H_
#define WPLOT_SCALARGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Graph2D.h"
#include <QPolygonF>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT ScalarGraph2D : public Graph2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<ScalarGraph2D> Ptr;

public:

	ScalarGraph2D();
	virtual ~ScalarGraph2D() = default;
	void setData(const QPolygonF &data);
	void appendPoint(const QPointF &point);
	void appendPoint(const double &x, const double &y);
	void insertPoint(const int &index, const QPointF &point);
	void insertPoint(const int &index, const double &x, const double &y);

public:

	virtual void clear();

protected:

	QPolygonF m_data;
};

} // namespace WPlot

#endif // WPLOT_SCALARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::ScalarGraph2D
 *
 * This class is a base class for all plots that must be set with scalar values.
 *
 * A scalar value is a single \f$\left(x,y\right)\f$ coordinate.
 */
