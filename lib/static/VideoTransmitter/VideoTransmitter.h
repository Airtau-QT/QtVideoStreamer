#ifndef VIDEOTRANSMITTER_H
#define VIDEOTRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QImage>
#include <opencv2/core/core.hpp>
/**
 * @brief Передатчик видео стрима
 */
class VideoTransmitter : public QObject {
    Q_OBJECT
public:
    VideoTransmitter( QString host = "localhost", quint16 port = 10000, QObject *parent = nullptr );
    void setQuality( const int quality );
    void host( const QString &host );
    void port( const quint16 port );
signals:
    void onError( const QString & );
public slots:
    void sendNewFrame( const cv::Mat &mat );
private:
    QUdpSocket _socket;
    int _quality{ 55 };
    const int PACKET_SIZE{ 4096 };
    QHostAddress _host;
    quint16 _port;
    void sendPacketsCount( const int count );
    void sendFrameData( const QByteArray &&imgData );
private slots:
    void onError( QAbstractSocket::SocketError errorMessage );
};

#endif // VIDEOTRANSMITTER_H
