#include "FilesCache.h"
#include <filesystem>
#include <chrono>
#include <QDebug>
void FilesCache::Load(QStringView path)
{
    m_filesVector.clear();
    for(const auto& fileName : std::filesystem::directory_iterator(path.toString().toStdString()))
    {
        qDebug() << fileName.path().string().c_str();
    }
}

FilesVector& FilesCache::GetFilesVector() & noexcept
{
    return m_filesVector;
}

const FilesVector& FilesCache::GetFilesVector() const& noexcept
{
    return m_filesVector;
}
