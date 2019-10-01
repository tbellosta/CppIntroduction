# 3) Finite Differences
This folder contains the code that was written during the third exercise lecture.
To compile and run the code:
```
$ make
$ ./finDiff
```
## gnuplot
[gunplot](http://www.gnuplot.info) can be installed form you package manager. For Debian/Ubuntu:
```
$ sudo apt-get install gnuplot
```
On macOS:
```
$ brew install gnuplot
```
For Windows a binary installer with instructions is available at [www.gnuplot.info](http://www.gnuplot.info) .

To plot a column file (i.e. data.txt):
```
$ gnuplot
$ plot "data.txt" u 1:2 w l
```
which plots the content of the first comlumn on the abscissa and that of the second one one the y axis.
If the file has three columns, the command:
```
$ gnuplot
$ plot "data.txt" u 1:2 w l, '' u 1:3 w l
```
plots two curves; the first as the example above, the second curve has the first column as abscissa and the third as ordinate.
To plot the same curves in logarithmic scale:
```
$ gnuplot
$ set logscale xy
$ plot "data.txt" u 1:2 w l, '' u 1:3 w l
```
