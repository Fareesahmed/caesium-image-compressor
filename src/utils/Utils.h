#ifndef UTILS_H
#define UTILS_H

#include <QImage>
#include <QMap>
#include <QSize>
#include <QString>
#include <QStringList>

#include "../vendor/caesium.h"

enum class CImageStatus {
    UNCOMPRESSED,
    COMPRESSING,
    COMPRESSED,
    ERROR
};

enum CImageColumns
{
    NAME = 0,
    SIZE = 1,
    RESOLUTION = 2,
    RATIO = 3
};

enum ResizeMode
{
    NO_RESIZE = 0,
    DIMENSIONS = 1,
    PERCENTAGE = 2,
    SHORT_EDGE = 3,
    LONG_EDGE = 4
};

typedef struct CompressionOptions
{
    QString outputPath;
    QString basePath;
    QString suffix;
    int compressionLevel;
    bool lossless;
    bool keepMetadata;
    bool keepStructure;
    bool resize;
    int fitTo;
    int width;
    int height;
    int size;
    bool doNotEnlarge;
    bool sameFolderAsInput;
    bool advancedMode;
    cs_jpeg_pars advancedJPEGPars;
    cs_png_pars advancedPNGPars;

} CompressionOptions;

//Utilities
QString toHumanSize(size_t size);
QStringList scanDirectory(QString directory);
cs_image_pars getCompressionParametersFromLevel(int level, bool lossless, bool keepMetadata);
QString getRootFolder(QMap<QString, int> folderMap);
QImage cResize(QImage image, int fitTo, int width, int height, int size, bool doNotEnlarge);
bool copyMetadata(const char* input, const char* output);
#endif // UTILS_H
