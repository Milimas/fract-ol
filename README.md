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
[Plotting algorithms for the Mandelbrot set](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)<br/>
[2018-2019-JonckheereLSde](https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf)<br/>
[mandelbrot_compute](https://github.com/Talndir/fractal-z/blob/master/Fractal%20Z/shaders/mandelbrot/mandelbrot_compute.glsl)<br/>
[high_level_design](https://people.ece.cornell.edu/land/courses/ece5760/FinalProjects/s2022/sjz38_dap263/sjz38_dap263/high_level_design.html)<br/>
[Mandelbrot set web optimizing](https://www.capitalone.com/tech/software-engineering/optimizing-graphing-performance-on-the-web-mandelbrot-project/)<br/>
[Mandelbrot set performance](https://martin-ueding.de/posts/performance-in-mandelbrot-set-computation/)<br/>
[increase performance creating mandelbrot set in python](https://codereview.stackexchange.com/questions/216235/increase-performance-creating-mandelbrot-set-in-python)<br/>
[optimising rendering the mandelbrot set](https://blog.kazitor.com/2018/07/optimising-rendering-the-mandelbrot-set/)<br/>
[Fract-ol](https://github.com/VBrazhnik/Fract-ol)<br/>
[Fabien fractol](https://git.42l.fr/Fabien/fractol/src/branch/master)<br/>
[Fractals are typically not self-similar](https://www.youtube.com/watch?v=gB9n2gHsHN4)<br/>
[p5.js julia set](https://editor.p5js.org/codingtrain/sketches/G6qbMmaI)<br/>

z<sup>2</sup> = (x + iy)(x + iy) = x<sup>2</sup> + xyi + xyi - y<sup>2</sup> = x<sup>2</sup> - y<sup>2</sup> + 2xyi

```
while iter < max_iter
  x = x<sup>2</sup> - y<sup>2</sup>
  y = 2xyi
  if x<sup>2</sup> + y<sup>2</sup> > 2
    break
color = iter/max_iter
```

Mandelbrot JavaScript implementation with p5.js:

```javascript
var minval = -0.5;
var maxval = 0.5;

var minSlider;
var maxSlider;

function setup() {
  createCanvas(400, 400);
  pixelDensity(1);
  
  minSlider = createSlider(-2.5, 0, -2.5, 0.01);
  maxSlider = createSlider(0, 2.5, 2.5, 0.01);
}

function draw()
{
  var max_iter = 50;
  loadPixels();
  for (var x = 0; x < width; x++)
  {
    for (var y = 0; y < height; y++)
    {
      var a = map(x, 0, width, minSlider.value(), maxSlider.value());
      var b = map(y, 0, height, minSlider.value(), maxSlider.value());
      
      var ca = a;
      var cb = b;
      
      var n = 0;
      
      while (n < max_iter)
      {
        var aa = a*a - b*b;
        var bb = 2 * a * b;
        a = aa + ca;
        b = bb + cb;
        if (abs(a + b) > 16)
        {
          break;
        }
        n++;
      }
      
      var bright = map(n, 0, max_iter, 0, 1);
      bright = map(sqrt(bright), 0, 1, 0, 255);
      if (n == max_iter)
      {
          bright = 0;
      }
      
      var pix = (x + y * width) * 4;
      pixels[pix + 0] = bright;
      pixels[pix + 1] = bright;
      pixels[pix + 2] = bright;
      pixels[pix + 3] = 255;
    }
  }
  updatePixels();
}
```
for the julia set just modify the lines from
```javascript
...
        a = aa + ca;
        b = bb + cb;
...
```
to
```javascript
...
        a = aa -0.70176;
        b = bb -0.3842;
...
```

Julia set from mouse position mapped to x[-2, 2] y[-2, 2]:
```javascript
var minval = -0.5;
var maxval = 0.5;

var minSlider;
var maxSlider;

function setup() {
  createCanvas(400, 400);
  pixelDensity(1);
  
  minSlider = createSlider(-2, 0, -2, 0.01);
  maxSlider = createSlider(0, 2, 2, 0.01);
}

function draw()
{
  var max_iter = 50;
  loadPixels();
  for (var x = 0; x < width; x++)
  {
    for (var y = 0; y < height; y++)
    {
      var a = map(x, 0, width, minSlider.value(), maxSlider.value());
      var b = map(y, 0, height, minSlider.value(), maxSlider.value());
      
      var ca = map(mouseX, 0, width, -2, 2);
      var cb = map(mouseY, 0, height, -2, 2);
      
      var n = 0;
      
      while (n < max_iter)
      {
        var aa = a*a;
        var bb = b*b;
        if (aa + bb > 4)
        {
          break;
        }
        var twoab = 2.0 * a * b;
        a = aa - bb + ca;
        b = twoab + cb;
        n++;
      }
      
      var bright = map(n, 0, max_iter, 0, 1);
      bright = map(sqrt(bright), 0, 1, 0, 255);
      if (n == max_iter)
      {
          bright = 0;
      }
      
      var pix = (x + y * width) * 4;
      pixels[pix + 0] = bright;
      pixels[pix + 1] = bright;
      pixels[pix + 2] = bright;
      pixels[pix + 3] = 255;
    }
  }
  updatePixels();
}
```

