#ifndef WPLOT_TICKS2D_H_
#define WPLOT_TICKS2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include <QColor>
#include <QFont>
#include <QPen>
#include <QTextOption>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT Ticks2D : public Layer2D
{
public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<Ticks2D> Ptr;

	typedef enum {
		FORMAT_INTEGER,
		FORMAT_FLOAT,
		FORMAT_DATE,
		FORMAT_TIME,
		FORMAT_DATETIME
	} FormatType;

public:

	Ticks2D();
	virtual ~Ticks2D() = default;
	void setXPrimaryStep(const double &step);
	void setXSecondaryStep(const double &step);
	void setYPrimaryStep(const double &step);
	void setYSecondaryStep(const double &step);
	void setPrimaryStep(const double &step);
	void setSecondaryStep(const double &step);
	void setXPrimaryTickLength(const double &length);
	void setXSecondaryTickLength(const double &length);
	void setPrimaryTickLength(const double &length);
	void setYPrimaryTickLength(const double &length);
	void setYSecondaryTickLength(const double &length);
	void setSecondaryTickLength(const double &length);
	void setXPrimaryTickWidth(const double &width);
	void setXSecondaryTickWidth(const double &width);
	void setXTickWidth(const double &width);
	void setYPrimaryTickWidth(const double &width);
	void setYSecondaryTickWidth(const double &width);
	void setYTickWidth(const double &width);
	void setPrimaryTickWidth(const double &width);
	void setSecondaryTickWidth(const double &width);
	void setTickWidth(const double &width);
	void setXPrimaryTickColor(const QColor &color);
	void setYPrimaryTickColor(const QColor &color);
	void setPrimaryTickColor(const QColor &color);
	void setXSecondaryTickColor(const QColor &color);
	void setYSecondaryTickColor(const QColor &color);
	void setSecondaryTickColor(const QColor &color);
	void setXSecondaryTickStyle(const Qt::PenStyle &style);
	void setYSecondaryTickStyle(const Qt::PenStyle &style);
	void setSecondaryTickStyle(const Qt::PenStyle &style);
	void setXPrimaryTickStyle(const Qt::PenStyle &style);
	void setYPrimaryTickStyle(const Qt::PenStyle &style);
	void setPrimaryTickStyle(const Qt::PenStyle &style);
	void setXTickStyle(const Qt::PenStyle &style);
	void setYTickStyle(const Qt::PenStyle &style);
	void setTickStyle(const Qt::PenStyle &style);
	void setXLabelFormatType(const FormatType &type);
	void setYLabelFormatType(const FormatType &type);
	void setLabelFormatType(const FormatType &type);
	void setXLabelFont(const QFont &font);
	void setYLabelFont(const QFont &font);
	void setLabelFont(const QFont &font);
	void setXLabelDistanceFromAxis(const double &distance);
	void setYLabelDistanceFromAxis(const double &distance);
	void setLabelDistanceFromAxis(const double &distance);
	void setEnableLabels(const bool &flag);
	void setOrigin(const QPointF &origin);
	void setOrigin(const double &x, const double &y);

public:

	virtual void draw(Plot2D *plot) Q_DECL_OVERRIDE;

private:

	void drawAxisXTicks(Plot2D *plot);
	void drawAxisYTicks(Plot2D *plot);
	void drawAxisXLabels(Plot2D *plot);
	void drawAxisYLabels(Plot2D *plot);
	QString getLabelText(const double &value) const;

private:

	double m_axisXPrimaryStep;
	double m_axisXSecondaryStep;
	double m_axisYPrimaryStep;
	double m_axisYSecondaryStep;
	double m_axisXWidth;
	double m_axisYWidth;
	double m_axisXPrimaryTickLength;
	double m_axisXSecondaryTickLength;
	double m_axisYPrimaryTickLength;
	double m_axisYSecondaryTickLength;
	double m_axisXPrimaryTickWidth;
	double m_axisXSecondaryTickWidth;
	double m_axisYPrimaryTickWidth;
	double m_axisYSecondaryTickWidth;
	double m_axisXLabelDistance;
	double m_axisYLabelDistance;
	Qt::PenStyle m_axisXPrimaryTickStyle;
	Qt::PenStyle m_axisXSecondaryTickStyle;
	Qt::PenStyle m_axisYPrimaryTickStyle;
	Qt::PenStyle m_axisYSecondaryTickStyle;
	QColor m_axisXPrimaryTickColor;
	QColor m_axisXSecondaryTickColor;
	QColor m_axisYPrimaryTickColor;
	QColor m_axisYSecondaryTickColor;
	QFont m_axisXFont;
	QFont m_axisYFont;
	QTextOption m_axisXTextOptions;
	QTextOption m_axisYTextOptions;
	FormatType m_axisXFormatType;
	FormatType m_axisYFormatType;
	bool m_labelEnabled;
	QPointF m_origin;
	QPen m_axisXPrimaryTickPen;
	QPen m_axisXSecondaryTickPen;
	QPen m_axisYPrimaryTickPen;
	QPen m_axisYSecondaryTickPen;
};

} // namespace WPlot

#endif // WPLOT_TICKS2D_H_

/**
 * @class WPlot::Ticks2D
 *
 * This class allows to draw a 2D ticks inside the plot.
 */
