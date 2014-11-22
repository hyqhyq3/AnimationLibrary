#ifndef ANIMATIONLIBRARY_H
#define ANIMATIONLIBRARY_H
#include <QtCore>

class AnimationLibrary :
        public QAbstractListModel
{
    Q_OBJECT
    QString path_;
    QStringList list_;
public:
    AnimationLibrary(QObject* parent);

    void rebuild(const QString& path);

    bool doPath(const QDir& path);

    bool doFile(const QDir& path);

    const QString& path();


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // ANIMATIONLIBRARY_H
