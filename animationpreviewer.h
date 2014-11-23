#ifndef ANIMATIONPREVIEWER_H
#define ANIMATIONPREVIEWER_H

#include <QLabel>

class QTimer;

class AnimationPreviewer : public QLabel
{
    Q_OBJECT
public:
    explicit AnimationPreviewer(QWidget *parent = 0);

    void setFiles(QStringList files);
    void setInterval(int interval);
    void updateDisplay();

    QString firstFile();
signals:

public slots:
    void onTimer();
    void setAnimationRate(int rate);
private:
    QStringList files_;
    int interval_;
    int index_;
    QTimer* timer_;
};

#endif // ANIMATIONPREVIEWER_H
