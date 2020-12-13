#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString imagepath=QFileDialog::getOpenFileName(this,
                                                   tr("选择文件"),
                                                   "/",
                                                   tr("images(*.png *jpeg *bmp);;All files(*.*)"));
    ui->lineEdit->setText(imagepath);
    QPixmap pix(imagepath);
    QPixmap dest=pix.scaled(ui->label_2->size(),Qt::KeepAspectRatio);
    ui->label_2->setPixmap(dest);

}
