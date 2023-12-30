#include "Customer.h"
#include <QDebug>
Customer::Customer(QString username, QString password) : Account(username, password)
{

}


void Customer::addToDatabase(QSqlDatabase mydb)
{
    mydb.open();
    QSqlQuery query;
    query.prepare("INSERT INTO accounts(username, password, accessLevel) VALUES(?, ?, ?)");
    query.addBindValue(getUsername());
    query.addBindValue(getPassword());
    query.addBindValue(accessLevel); // Assuming accessLevel is a member variable

    QMessageBox msgBox;
    if (query.exec()) {
        msgBox.setText("Account created successfully");
        msgBox.exec();
    } else {
        msgBox.setText("Failed to create account. " + query.lastError().text());
        qDebug() << query.lastError().text();
        msgBox.exec();
    }
    mydb.close();
}
