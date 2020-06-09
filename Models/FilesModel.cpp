#define _CRT_SECURE_NO_WARNINGS
#include "FilesModel.h"
#include <chrono>
#include <ctime>

namespace
{
    QString TimeToString(const FileCreatedTime& time)
    {
        auto tmp = std::chrono::system_clock::to_time_t(time);
        return std::ctime(&tmp);
    }
}

FilesModel::FilesModel(QObject* parent)
    : QAbstractItemModel{parent}
{

}

int FilesModel::rowCount(const QModelIndex&) const
{
    return m_files.count();
}
int FilesModel::columnCount(const QModelIndex &) const
{
    return FilesTableColumnCount;
}
QVariant FilesModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
       return QVariant();
    }
    const auto& [fileName, fileCreatedTime] = m_files.at(index.row());
    switch(static_cast<FileData>(role))
    {
       case FileData::FileName:
          return fileName;
       case FileData::FileCreatedTime:
          return TimeToString(fileCreatedTime);
    }
    return QVariant{};

}
QHash<int , QByteArray> FilesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(FileData::FileName)] = FileNameStr;
    roles[static_cast<int>(FileData::FileCreatedTime)] = FileCreatedTimeStr;
    return roles;
}

QModelIndex FilesModel::parent(const QModelIndex&) const
{
    return QModelIndex{};
}

QModelIndex FilesModel::index(int, int, const QModelIndex &) const
{
    return QModelIndex{};
}

void FilesModel::SetNewFiles(const FilesCachePtr&)
{

}
