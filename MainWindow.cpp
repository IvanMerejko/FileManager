#include "MainWindow.h"
#include <QQmlContext>
#include <QSharedPointer>
namespace
{
    constexpr auto FilesModelStr = "filesModel";
    constexpr auto MainWindowStr = "mainWindow";
}

MainWindow::MainWindow(QStringView file)
    : QQmlApplicationEngine{}
    , m_filesCache{FilesCachePtr::create()}
    , m_filesModel{new FilesModel(this)}
{
    load(file.toString());
    LoadFilesForFolder(QStringLiteral("X:\\QTProjects\\Manager"));
}


void MainWindow::LoadFilesForFolder(QStringView path)
{
    m_filesCache->Load(path);
    m_filesModel->SetNewFiles(m_filesCache);
}

void MainWindow::initializeRootContext()
{
    rootContext()->setContextProperty(FilesModelStr , m_filesModel);
    rootContext()->setContextProperty(MainWindowStr , this);
}
