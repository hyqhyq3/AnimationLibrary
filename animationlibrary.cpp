#include "animationlibrary.h"
#include "qdebug.h"

AnimationLibrary::AnimationLibrary(QObject *parent)
    : QAbstractListModel(parent)
{
}

void AnimationLibrary::rebuild(const QString &path)
{
    beginRemoveRows(QModelIndex(), 0, list_.size());
    list_.clear();
    endRemoveRows();

    path_ = path;
    QDir dir(path_);
    if(!doPath(dir))
    {
        doFile(dir);
    }
    qDebug() << list_;
    beginInsertRows(QModelIndex(), 0, list_.size());
    endInsertRows();
}

bool AnimationLibrary::doPath(const QDir &path)
{
    auto dirs = path.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    if(dirs.size() == 0)
    {
        return false;
    }
    for(auto dir : dirs)
    {
        auto p = path;
        p.cd(dir);
        if(!doPath(p))
        {
            doFile(p);
        }
    }
    return true;
}

bool AnimationLibrary::doFile(const QDir &path)
{
    QStringList nameFilters;
    nameFilters << "*.png";
    auto files = path.entryList(nameFilters);
    if(files.size() > 0)
    {
        list_ << path.path();
        return true;
    }
    return false;
}

const QString &AnimationLibrary::path()
{
    return path_;
}

int AnimationLibrary::rowCount(const QModelIndex &parent) const
{
    return list_.size();
}

QVariant AnimationLibrary::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole && index.row() < list_.size() && index.isValid())
    {
        return list_.at(index.row());
    }
    else
    {
        return QVariant();
    }
}
