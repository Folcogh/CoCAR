#include "DlgSettings.hpp"
#include "ui_DlgSettings.h"

DlgSettings::DlgSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSettings)
{
    ui->setupUi(this);
}

DlgSettings::~DlgSettings()
{
    delete ui;
}
