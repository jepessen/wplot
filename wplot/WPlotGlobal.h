#ifndef WPLOT_GLOBAL_H_
#define WPLOT_GLOBAL_H_

#include <QtCore/qglobal.h>

#if defined(WPLOT_LIBRARY)
#  define WPLOTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WPLOTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WPLOT_GLOBAL_H_
