#include "animationpreviewer.h"

#include <QtCore>
#include <qdebug.h>

AnimationPreviewer::AnimationPreviewer(QWidget *parent) :
    QLabel(parent),
    interval_(33),
    index_(0)
{
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer_->start(interval_);
    updateDisplay();
}

void AnimationPreviewer::setFiles(QStringList files)
{
    files_ = files;
    index_ = 0;
    updateDisplay();
}

void AnimationPreviewer::setInterval(int interval)
{
    interval_ = interval;
}

void AnimationPreviewer::updateDisplay()
{
    if(files_.size() > 0)
    {
        setPixmap(QPixmap(files_.at(index_ % files_.size())));
        show();
    }
}

QString AnimationPreviewer::firstFile()
{
    if(files_.empty())
    {
        return "";
    }
    else
    {
        return files_.front();
    }
}

void AnimationPreviewer::onTimer()
{
    ++index_;
    updateDisplay();
}

void AnimationPreviewer::setAnimationRate(int rate)
{
    interval_ = 1000 / rate;
    timer_->setInterval(interval_);
}
