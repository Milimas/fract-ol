# fract-ol

## Equations

The Mandelbrot and Julia set is calculated by iterating the equation

z<sub>n+1</sub> = z<sub>n</sub><sup>2</sup> + c

where i = √-1 and x and y are the horizontal and vertical position of the location within the fractal whose color you wish to calculate.

The calculation is repeated until |z<sub>n</sub>| > 2, and colors are assigned to each location depending on the number of iterations required until this condition is met.

A maximum number of iterations needs to be specified, because in some parts of the fractal, the iteration sequence above will never end. This is true in the 'lake' area in the center of the fractal.

### Mandelbrot Set

The starting conditions are

Z<sub>0</sub> = 0

and

c = x + iy

### Julia Set

The starting conditions are

Z<sub>0</sub> = x + iy

and

c = x<sub>0</sub> + iy<sub>0</sub>

x<sub>0</sub> and y<sub>0</sub> are two numerical constants which define a two-dimensional set of different Julia sets.

## Coordinates

left:   -3.834738617201<br/>
right:   3.834738617201<br/>
top:    -2.000000000000<br/>
botton:  2.000000000000<br/>



## Sources
[Julia Set](https://sciencedemos.org.uk/julia.php)<br/>
[Mandelbrot Set](https://sciencedemos.org.uk/mandelbrot.php)<br/>
[From Simple to Complex](https://fractalfoundation.org/OFC/OFC-4-1.html)<br/>
[The mandelbrot Fractal Explained](https://www.youtube.com/watch?v=6IWXkV82oyY)<br/>
[mandelbrot online viewer](https://mandel.gart.nz/)<br/>
[optimize mandelbrot set](https://stackoverflow.com/questions/44354589/optimizing-mandelbrot-fractal)<br/>

z<sup>2</sup> = (x + iy)(x + iy) = x<sup>2</sup> + xyi + xyi - y<sup>2</sup> = x<sup>2</sup> - y<sup>2</sup> + 2xyi

```
while iter < max_iter
  x = x<sup>2</sup> - y<sup>2</sup>
  y = 2xyi
  if x<sup>2</sup> + y<sup>2</sup> > 2
    break
color = iter/max_iter
