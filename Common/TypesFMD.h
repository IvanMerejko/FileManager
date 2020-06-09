#pragma once
#include <QString>
#include <QSharedPointer>
#include <chrono>

constexpr auto FilesTableColumnCount = 2;
constexpr auto FileNameStr = "FileName";
constexpr auto FileCreatedTimeStr = "FileTime";

using FileName = QString;
using FileCreatedTime = std::chrono::system_clock::time_point;

class FilesCache;
using FilesCachePtr = QSharedPointer<FilesCache>;
