#ifndef KIWIXAPP_H
#define KIWIXAPP_H

#include "library.h"
#include "contentmanager.h"
#include "mainwindow.h"
#include "kiwix/downloader.h"
#include "tabbar.h"
#include "tocsidebar.h"
#include "urlschemehandler.h"

#include <QApplication>
#include <QErrorMessage>
#include <QTranslator>


class KiwixApp : public QApplication
{
    Q_OBJECT
public:
    enum Actions {
        KiwixServeAction,
        RandomArticleAction,
        PrintAction,
        NewTabAction,
        CloseTabAction,
        ReopenClosedTabAction,
        BrowseLibraryAction,
        OpenFileAction,
        OpenRecentAction,
        SavePageAsAction,
        SearchArticleAction,
        SearchLibraryAction,
        FindInPageAction,
        ToggleFullscreenAction,
        ToggleTOCAction,
        ToggleReadingListAction,
        ZoomInAction,
        ZoomOutAction,
        ZoomResetAction,
        HelpAction,
        FeedbackAction,
        ReportBugAction,
        RequestFeatureAction,
        AboutAction,
        SettingAction,
        DonateAction,
        ExitAction,
        MAX_ACTION
    };
    enum SideBarType {
        SEARCH_BAR,
        CONTENTMANAGER_BAR,
        READINGLIST_BAR,
        NONE
    };

    KiwixApp(int& argc, char *argv[]);
    virtual ~KiwixApp();
    static KiwixApp* instance();

    void openRandomUrl(bool newTab=true);

    void showMessage(const QString& message);

    UrlSchemeHandler* getSchemeHandler() { return &m_schemeHandler; }
    Library* getLibrary() { return &m_library; }
    MainWindow* getMainWindow() { return mp_mainWindow; }
    kiwix::Downloader* getDownloader() { return mp_downloader; }
    TabBar* getTabWidget() { return mp_tabWidget; }
    QAction* getAction(Actions action);

    bool isCurrentArticleBookmarked();

signals:
    void currentTitleChanged(const QString& title);

public slots:
    void openZimFile(const QString& zimfile="");
    void openUrl(const QString& url, bool newTab=true);
    void openUrl(const QUrl& url, bool newTab=true);
    void setSideBar(SideBarType type);
    void printPage();

protected:
    void createAction();
    void postInit();

private:
    QTranslator m_qtTranslator, m_appTranslator;
    UrlSchemeHandler m_schemeHandler;
    Library m_library;
    kiwix::Downloader* mp_downloader;
    ContentManager m_manager;
    MainWindow* mp_mainWindow;
    TabBar* mp_tabWidget;
    QWidget* mp_currentSideBar;
    QErrorMessage* mp_errorDialog;

    QAction*     mpa_actions[MAX_ACTION];
};

#endif // KIWIXAPP_H
