#ifndef TOCSIDEBAR_H
#define TOCSIDEBAR_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class TocSideBar;
}

class TocSideBar : public QWidget
{
    Q_OBJECT

public:
    explicit TocSideBar(QWidget *parent = 0);
    ~TocSideBar();

    void postInit();

public slots:
    void findNext();
    void findPrevious();

private:
    Ui::TocSideBar *mp_ui;
    QLineEdit      *mp_findLineEdit;
};

#endif // TOCSIDEBAR_H
