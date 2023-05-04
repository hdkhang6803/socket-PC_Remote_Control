#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <vector>
using std::vector;

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QTreeView>


#include "client.h"
#include "connectDialog.h"
#include "featureButton.h"

//QT_BEGIN_NAMESPACE
//class QLabel;
//class QLineEdit;
//class QPushButton;
//class QHBoxLayout;
//class QFormLayout;
//class QVBoxLayout;
//class QGroupBox;
//QT_END_NAMESPACE

//namespace Ui {
//class ClientWindow;
//}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

    typedef void (ClientWindow::*featBtnFuncPointer)();
public:
    explicit ClientWindow(QWidget *parent = nullptr);
//    ~ClientWindow();

private:
//    Ui::ClientWindow *ui;

private slots:
    void receivedServerInfo(const QString &serverIp, int port);

    void updateServerMsg(const QString &msg);
    void updateImage(const QPixmap &image);
    void updateFileStruct(const QFileSystemModel &model);

private:
    QString featureNames[3] = {
        tr("keyboard track"),
        tr("list processes"),
        tr("take screenshot")
    };

    Client *client = nullptr;
    ConnectDialog *connectDialog = nullptr;

    QHBoxLayout *overallLayout = nullptr;
    QWidget *leftPanelWidget = nullptr;
    QWidget *rightPanelWidget = nullptr;

    QVBoxLayout *leftPanelLayout = nullptr;
    QGroupBox *serverInfoBox = nullptr;
    QFormLayout *serverInfoLayout = nullptr;
    QLabel *ipLabel = nullptr;
    QLabel *portLabel = nullptr;
    QLabel *ipBox = nullptr;
    QLabel *portBox = nullptr;
    QWidget *featureWidget = nullptr;
    QVBoxLayout *featureLayout = nullptr;
    vector<FeatureButton*> *featureButtons = nullptr;
    QPushButton *exitButton = nullptr;

    QVBoxLayout *rightPanelLayout = nullptr;
    QLineEdit *serverMsgBox = nullptr;


    QWidget *centralWidget = nullptr;

private slots:
    void on_pushButton_clicked(int num);
//    void on_pushButton_3_clicked();
};



#endif // CLIENTWINDOW_H

