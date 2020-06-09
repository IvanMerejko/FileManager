#pragma once
#include "TypesFMD.h"

enum class FileData
{
    FileName = 0,
    FileCreatedTime,
};

class File
{
public:
    File(FileName fileName, FileCreatedTime fileCreatedTime)
        : m_fileName{std::move(fileName)}
        , m_createdTime{std::move(fileCreatedTime)}
    {}
    template <size_t I>
    auto& get() &
    {
        if constexpr (I == 0)
        {
            return m_fileName;
        }
        else if constexpr (I == 1)
        {
        return m_createdTime;
        }
    }

    template <size_t I>
    auto const& get() const&
    {
        if constexpr (I == 0)
        {
            return m_fileName;
        }
        else if constexpr (I == 1)
        {
            return m_createdTime;
        }
     }
private:
    FileName m_fileName;
    FileCreatedTime m_createdTime;
};

namespace std {
    template <> struct tuple_size<File> : std::integral_constant<size_t, 2> { };

    template <> struct tuple_element<0,File> { using type = FileName; };
    template <> struct tuple_element<1,File> { using type = FileCreatedTime; };
}


using FilesVector = QVector<File>;
