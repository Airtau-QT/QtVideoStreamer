#include "ImageSerialization.h"
#include <QImageWriter>
#include <QImageReader>

#define IMG_EXT "JPG"

QByteArray ImageSerialization::serialize( QImage img ) {
    QBuffer buffer;
    QImageWriter writer( &buffer, IMG_EXT );
    writer.write( img );
    QByteArray data;
    data.append( buffer.data( ) );
    return data;
}

QImage ImageSerialization::deserialize( QByteArray imgData ) {
    QBuffer buffer( &imgData );
    QImageReader reader( &buffer, IMG_EXT );
    QImage img( reader.read( ) );
    return img;
}
