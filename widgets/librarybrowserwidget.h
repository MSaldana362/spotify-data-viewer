#ifndef LIBRARYBROWSERWIDGET_H
#define LIBRARYBROWSERWIDGET_H

#include <QWidget>

#include "../widgets/librarytracksmodel.h"

namespace Ui {
class LibraryBrowserWidget;
}

class LibraryBrowserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryBrowserWidget(QWidget *parent = nullptr);
    ~LibraryBrowserWidget();

private:
    Ui::LibraryBrowserWidget *ui;

    LibraryTracksModel* _tracksModel;
};

#endif // LIBRARYBROWSERWIDGET_H
