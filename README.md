# csv2xlsx

[![Build](https://github.com/maryo/csv2xlsx/actions/workflows/build.yml/badge.svg)](https://github.com/maryo/csv2xlsx/actions/workflows/build.yml)

Convert CSV files to Excel without worrying auto data format converter.

## License

GPL version 3 or later

## Features

* Convert CSV, TSV to Excel file
* Combine multiple 
* Configurable automatic format converter

## Usage

```
Usage: csv2xlsx-c-fork [-htHadnbpfu] <file> [<file>]... <file> [-D <string>] [-r <int>] [-P <string>] [-s <string>]... [-c <string>]... [-F <string>]... [-T <string>]
  <file>                        Input TSV or CSV files
  <file>                        Output XLSX file
  -h, --help                    Display this help and exit
  -D, --delimiter=<string>      Configure delimiter used in the CSV file, defaults to ','
  -t, --table                   Enable table (do not enable this option to reduce memory usage)
  -H, --header                  Enable header (a shorthand to passing --header-rows=1)
  -r, --header-rows=<int>       Enable header and set number of header rows.
  -a, --auto-filter             Enable AutoFilter
  -P, --freeze-panes=<string>   Split and freeze a worksheet into panes in format 'row' or 'row,column'
  -s, --sheet-name=<string>     Configure excel sheet names
  -c, --column=<string>         Configure columns in format like '0=type: string' or '1=type: number; number-format: #,##0.00; color: #FF0000', definitions without column number are treated as defaults
  -F, --header-column=<string>  Configure header column format in format like '0=background-color: #33333333; color: #FFFFFF', definitions without column number are treated as defaults
  -d, --convert-digit           Enable automatic conversion to integer
  -n, --convert-number          Enable automatic convert to floating number
  -b, --convert-bool            Enable automatic convert to boolean
  -p, --convert-percent         Enable automatic convert to percent
  -f, --convert-formula         Enable automatic convert to formula
  -u, --convert-url             Enable automatic convert to url
  -T, --temp-directory=<string> Configure alternative temporary files location to override system default
```
