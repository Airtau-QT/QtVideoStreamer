# QtVideoStreamer
Стриминг видеопотока с камеры по сети ( UDP ).
----------------------------------------------
ImageSerialization - статическая библиотека сериализации и десереализации QImage и cv::Mat
VideoCapture       - статическая библиотека захвата изображения с камеры
VideoTransmitter   - статическая библиотека передачи изображения с камеры приложению-приемнику по сети
VideoReceiver      - статическая библиотека приема изображения по сети от приложения-передатчика

TransmitterTest    - тестовое приложение-передатчик изображения с камеры
ReceiverTest       - тестовое приложение-приемник изображения с камеры

Системные требования:
1. ОС: Windows, Linux( Ubuntu 16.04, Raspbian );
2. Qt 5.5.1 или более новая версия;
3. OpenCV 2.4$
4. Компилятор с поддержкой c++ 11;
5. Веб-камера.

Сборка на Windows:
1. Склонировать репозиторий;
2. В файле config.pri прописать при необходимости путь до директории библиотек opencv, имя библиотек и путь до заголовочных файлов
(по умолчанию в config.pri идет ссылка на каталог dependencies проекта с бинарниками opencv2 VC14 x64);
3. Собрать проект.

Сборка на Linux(Ubuntu 16.04, Raspbian)
1. Склонировать репозиторий;
2. Запустить терминал и выполнить команду sudo apt-get install libopencv-dev.
3. Собрать проект.