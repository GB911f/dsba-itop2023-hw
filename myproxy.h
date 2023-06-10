#ifndef PROXY_H
#define PROXY_H

#include <QSortFilterProxyModel>

class MyProxy : public QSortFilterProxyModel
{
public:
    explicit MyProxy(QObject *parent = nullptr);
};

#endif // PROXY_H
