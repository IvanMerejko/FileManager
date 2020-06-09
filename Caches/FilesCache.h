#ifndef FILESCACHE_H
#define FILESCACHE_H
#include <File.h>

class FilesCache
{
public:
    FilesCache() = default;
    void Load(QStringView);
    FilesVector& GetFilesVector() & noexcept;
    const FilesVector& GetFilesVector() const& noexcept;
private:
    FilesVector m_filesVector;
};

#endif // FILESCACHE_H
