#ifndef WPLOT_TEXT2D_H_
#define WPLOT_TEXT2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QSizeF>
#include <QPen>
#include <QFont>
#include <QString>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT Text2D : public Item2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<Text2D> Ptr;

public:

	Text2D();
	virtual ~Text2D() = default;
	void setText(const QString &text);
	void setFont(const QFont &font);
	void setFontSize(const double &size);
	void setColor(const QColor &color);

public:

	virtual void draw(Plot2D *plot);

private:

	double m_fontSize;
	QFont m_font;
	QColor m_color;
	QString m_text;
	QPen m_pen;
};

} // namespace WPlot

#endif // WPLOT_TEXT2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Text
 *
 * This allows to draw a text in the plot.
 */
