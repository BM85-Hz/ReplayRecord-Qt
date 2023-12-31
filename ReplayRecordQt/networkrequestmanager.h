#ifndef NETWORKREQUESTMANAGER_H
#define NETWORKREQUESTMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class NetworkRequestManager : public QObject
{
    Q_OBJECT

public:
    explicit NetworkRequestManager(QObject* parent = nullptr);
    QList<int> gameIds;
    QNetworkRequest request;

public slots:
    void sendSearchRequest(const QString& search);
    void sendGameDetailsRequest(const QString& requestString);
    void handleCovers(qint64 cover_ID);
    void handlePlatforms(QJsonArray platform_IDs);
    void handleInvolvedCompanies(QJsonArray company_IDs);
    void handleCompanies();
    void handleGenres(QJsonArray genre_IDs);

private slots:
    void handleSearchReply();
    void handleDetailsReply();
    void handleCoverReply();
    void handlePlatformReply();
    void handleCompanyReply();
    void handleGenreReply();

signals:
    void searchResult(const QByteArray& result);
    void searchError(const QString& error);
    void gameDetailsResult(const QByteArray& result);
    void gameDetailsError(const QString& error);
    void coverResult(const QByteArray& result);
    void platformResult(const QByteArray& result);
    void companyResult(const QByteArray& result);
    void genreResult(const QByteArray& result);

private:
    QNetworkAccessManager manager;
    int platformRequests{};
    int completedPlatformRequests{};
};

#endif // NETWORKREQUESTMANAGER_H
