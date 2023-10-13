#ifndef SEARCHTAB_H
#define SEARCHTAB_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QPixmap>
#include <QLabel>
#include <QTabWidget>
#include "networkrequestmanager.h"

class SearchTab : public QWidget
{
    Q_OBJECT
public:
    SearchTab(QWidget *parent = nullptr);
    ~SearchTab(){}

private slots:
    void handleSearchResult(const QByteArray& result);
    void handleSearchError(const QString& error);
    void handleDetailsResult(const QByteArray& result);
    void handleCoverResult(const QByteArray& result);
    void handleImageDownloaded(QNetworkReply* reply);
    void handlePlatformsResult(const QByteArray& result);
    void handleCompaniesResult(const QByteArray& result);
    void handleGenresResult(const QByteArray& result);
    void executeSearch();
    void requestGameDetails(const QString& gameId);

private:
    QLineEdit* searchLineEdit;
    QListWidget* resultListWidget;
    QTextBrowser* textBrowserWidget;
    NetworkRequestManager requestManager;

    QLabel* imageLabel{};
    QString platforms{};
    QString companies{};
    QString genres{};
};

#endif // SEARCHTAB_H