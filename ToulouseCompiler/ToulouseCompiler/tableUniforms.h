#pragma once
#include "Log.h"
#include <QWidget>
#include "addDialog.h"
#include <QTableWidget>
#include <QPoint>
#include <QComboBox>
#include <vector>
#include <QDebug>
#include <QEvent>
#include <QVector>
#include <QTranslator>

namespace Ui { class tableUniforms; };

class tableUniforms : public QDialog
{
	Q_OBJECT

public:


	tableUniforms(QWidget* parent = Q_NULLPTR);
	~tableUniforms();



private:
	Ui::tableUniforms* ui;


	/********************UNIFORMS TABLE DATA********************/

	QTableWidget* table;
	QPushButton* addUniform;//Pointer to the button for add uniforms
	addDialog* addForm;

	std::vector<dataForUniform> uniforms;

	enum column {
		name, type, value, deleteRow
	};


	/********************END UNIFORMS TABLE DATA********************/

	QPushButton* help;
	QPushButton* accept;


	bool checkUniform(dataForUniform data);
	void wrongUniform();
	void changeUniform();

private slots:


	void handleButtonAboutUniform();
	void handleButtonAccept();
	void handleButtonAddUniform();

	//Manage the data send for the ui that add uniforms
	void handleData(const dataForUniform& data);

	//Manage the data that is edit
	void editSlot(int row, int col);
	void cell_onClicked();
	void cell_comboBoxChanged(const QString& newValue);


signals:
	void addUniforms(const QVector<dataForUniform>& data);


};
