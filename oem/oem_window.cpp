// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "oem/oem_window.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QSplitter>
#include <QStringListModel>
#include <QVBoxLayout>

#include "oem/models/oem_settings_model.h"

namespace installer {

OemWindow::OemWindow(QWidget* parent) : QFrame(parent) {
  this->setObjectName("oem_window");

  this->initUI();
  this->initConnections();

  // TODO(xushaohua): catch exceptions.
  if (!model_->load()) {
    qCritical() << "model->load() failed";
  }
}

void OemWindow::initConnections() {
}

void OemWindow::initUI() {

  model_ = new OemSettingsModel();

  QSplitter* splitter = new QSplitter(this);
  splitter->setContentsMargins(0, 0, 0, 0);

  QHBoxLayout* layout = new QHBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addWidget(splitter);

  this->setContentsMargins(0, 0, 0, 0);
  this->setLayout(layout);
  this->resize(640, 480);
}

void OemWindow::onDefaultLocaleIndexChanged(int index) {
  Q_UNUSED(index);
}

}  // namespace installer