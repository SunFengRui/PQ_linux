#ifndef PQ_LINUX_H
#define PQ_LINUX_H

#include <QWidget>
#include "qtimer.h"

#include <QtCharts/QtCharts>
#include <QStandardItemModel>

namespace Ui {
class pq_linux;
}

class pq_linux : public QWidget
{
    Q_OBJECT

public:
    explicit pq_linux(QWidget *parent = 0);
    ~pq_linux();

private:
    Ui::pq_linux *ui;
    QTimer * timer1;
    QTimer * timer2;

    double x_min = 0;
    double x_max = 50.0;
    double y_min = 1.0;
    double y_max = 2.0;

    double x2_min = 0;
    double x2_max = 25.0;
    double y2_min = 1.0;
    double y2_max = 2.0;

    double x3_min = 0;
    double x3_max = 30.0;
    double y3_min = 1.0;
    double y3_max = 2.0;

    double x4_min = 0;
    double x4_max = 5.0;
    double y4_min = 1.0;
    double y4_max = 2.0;

    QList<double>  data_A_rms;
    QList<double>  data_B_rms;
    QList<double>  data_C_rms;
    QList<double>  data2;
    QList<double>  data3;
    QList<double>  data4;

    QSplineSeries *series_A_rms;
    QSplineSeries *series_B_rms;
    QSplineSeries *series_C_rms;
    QLineSeries *series2;
    QSplineSeries *series3;
    QSplineSeries *series4;
    QChart *chart1;
    QChart *chart2;
    QChart *chart3;
    QChart *chart4;
    QChartView *chartView1;
    QChartView *chartView2;
    QChartView *chartView3;
    QChartView *chartView4;
    QStandardItemModel *data_view;
    int count = 0;
private slots:
    void update(void);
    void shuaxin(void);
    void curve(void);
    void A_flicker_shuaxin(void);
    void B_flicker_shuaxin(void);
    void C_flicker_shuaxin(void);
    void fuwei(void);
    void calculate(void);
};
extern int A_flicker_open, A_voltage_dipswellinterrupt_open;
extern int B_flicker_open, B_voltage_dipswellinterrupt_open;
extern int C_flicker_open, C_voltage_dipswellinterrupt_open;
#endif // PQ_LINUX_H
