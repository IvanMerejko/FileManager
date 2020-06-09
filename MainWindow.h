#pragma once
#include <QQmlApplicationEngine>
#include <QStringView>
#include "FilesCache.h"
#include "FilesModel.h"
class MainWindow : QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit MainWindow(QStringView);
    void LoadFilesForFolder(QStringView);
private:
    void initializeRootContext();
private:
    FilesCachePtr m_filesCache;
    FilesModel* m_filesModel;
};

