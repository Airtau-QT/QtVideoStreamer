#include "VideoTransmitter.h"

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    QObject{ parent },
    _host{ host },
    _port{ port }
{
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );
}

void VideoTransmitter::setQuality( const int quality ) {
    _quality = quality;
}

void VideoTransmitter::host( const QString &host ) {
    _host = host;
}

void VideoTransmitter::port( const quint16 port ) {
    _port = port;
}

void VideoTransmitter::sendFrameData( const QByteArray &imgData ) {
    int totalPack = 1 + ( imgData.size( ) - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );
    int i{ 0 };
    while ( i < totalPack ) {
        QByteArray bytes{ imgData.mid( i*PACKET_SIZE, PACKET_SIZE ) };
        _socket.writeDatagram( bytes , _host, _port );
        i++;
    }
}

void VideoTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    QString strError =
        "Error: " + ( errorMessage == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     errorMessage == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     errorMessage == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString( _socket.errorString( ) )
                    );
    emit onError( strError );
    qDebug( ) << "error:" << strError;
}

void VideoTransmitter::sendPacketsCount( const int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    _socket.writeDatagram( array, _host, _port );
}
