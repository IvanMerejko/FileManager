#ifndef FILESMODEL_H
#define FILESMODEL_H
#include <QAbstractTableModel>
#include "FilesCache.h"
#include "TypesFMD.h"
class FilesModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit FilesModel(QObject* parent = nullptr);
    void SetNewFiles(const FilesCachePtr&);
protected:
   int rowCount(const QModelIndex& = QModelIndex()) const override;
   int columnCount(const QModelIndex & = QModelIndex()) const override;
   QVariant data(const QModelIndex&, int= Qt::DisplayRole) const override;
   QHash<int , QByteArray> roleNames() const override;
   QModelIndex parent(const QModelIndex & index) const override;
   QModelIndex index(int row, int column, const QModelIndex & = QModelIndex()) const override;
private:
    FilesVector m_files;
};

#endif // FILESMODEL_H
