﻿/*
 * An example of creating an Excel pie chart using the libxlsxwriter library.
 *
 * Copyright 2014-2016, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

/*
 * Write some data to the worksheet.
 */
void write_worksheet_data(lxw_worksheet *worksheet, lxw_format *bold) {

    worksheet_write_string(worksheet, CELL("A1"), "Category", bold);
    worksheet_write_string(worksheet, CELL("A2"), "Apple",    NULL);
    worksheet_write_string(worksheet, CELL("A3"), "Cherry",   NULL);
    worksheet_write_string(worksheet, CELL("A4"), "Pecan",    NULL);

    worksheet_write_string(worksheet, CELL("B1"), "Values",   bold);
    worksheet_write_number(worksheet, CELL("B2"), 60,         NULL);
    worksheet_write_number(worksheet, CELL("B3"), 30,         NULL);
    worksheet_write_number(worksheet, CELL("B4"), 10,         NULL);
}

/*
 * Create a worksheet with examples charts.
 */
int main() {

    lxw_workbook     *workbook  = new_workbook("chart_pie.xlsx");
    lxw_worksheet    *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_chart_series *series;

    /* Add a bold format to use to highlight the header cells. */
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);

    /* Write some data for the chart. */
    write_worksheet_data(worksheet, bold);


    /*
     * Create a pie chart.
     */
    lxw_chart *chart = workbook_add_chart(workbook, LXW_CHART_PIE);

    /* Add the first series to the chart. */
    series = chart_add_series(chart, "=Sheet1!$A$2:$A$4", "=Sheet1!$B$2:$B$4");

    /* Set the name for the series instead of the default "Series 1". */
    chart_series_set_name(series, "Pie sales data");

    /* Add a chart title. */
    chart_title_set_name(chart, "Popular Pie Types");

    /* Set an Excel chart style. */
    chart_set_style(chart, 10);

    /* Insert the chart into the worksheet. */
    worksheet_insert_chart(worksheet, CELL("D2"), chart);


    return workbook_close(workbook);
}
