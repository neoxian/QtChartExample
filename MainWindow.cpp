
#include "MainWindow.h"


#include <QHBoxLayout>
#include <qpushbutton>
#include <QLabel>
#include <QLineSeries>
#include <QtCharts>

#include <iostream>



MainWindow::MainWindow(QWidget* parent) :
    QWidget(parent)
{
	auto layout = new QVBoxLayout();

	// Chart code

	QLineSeries* series = new QLineSeries();

	series->append(0, 6);
	series->append(2, 4);
	series->append(3, 8);
	series->append(7, 4);
	series->append(10, 5);

	QChart* chart = new QChart();

	chart->legend()->hide();
	chart->addSeries(series);
	chart->createDefaultAxes();
	chart->setTitle("Simple line chart example");

	QChartView* chartView = new QChartView(chart);



//	auto aWidget = new QWidget();
//	aWidget->setStyleSheet("background-color:yellow;");

	layout->addWidget(chartView);

	setLayout(layout);
}

void MainWindow::show()
{
	QWidget::show();
	
}
 

