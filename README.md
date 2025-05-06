# Fractol

## Introduction to Fractals

Fractals are complex geometric patterns that exhibit self-similarity at different scales. They are created through the repetitive application of mathematical formulas, resulting in infinitely complex patterns that can be zoomed into forever while revealing similar structures at every level.

## Key Characteristics of Fractals

1. **Self-Similarity**: Patterns repeat at different scales, showing the same or similar structures when magnified.
2. **Infinite Complexity**: No matter how much you zoom in, new details continue to emerge.
3. **Fractal Dimension**: Fractals often have non-integer dimensions, existing between traditional geometric dimensions.
4. **Iterative Process**: They are generated through the repetitive application of simple rules.

## Mathematical Foundation

### Complex Numbers

Fractals typically operate in the complex plane, where each point has:
- A real component (x-coordinate)
- An imaginary component (y-coordinate)

Each pixel on the screen represents a complex number:
```
c = x + yi
```

### Iterative Formulas

Fractal generation involves applying a mathematical formula repeatedly to each point in the complex plane. The most common types included in this project are:

#### 1. Mandelbrot Set

The Mandelbrot set uses the formula:
```
z₀ = 0
zₙ₊₁ = zₙ² + c
```

Where:
- c is the complex number corresponding to the pixel coordinates
- z₀ starts at 0
- The sequence is iterated until |z| > 2 or the maximum iteration count is reached

#### 2. Julia Set

Julia sets use a similar formula to the Mandelbrot set, but with a fixed complex parameter:
```
z₀ = pixel coordinates (x + yi)
zₙ₊₁ = zₙ² + k
```

Where:
- k is a constant complex number that defines the specific Julia set
- z₀ starts as the complex number corresponding to the pixel coordinates
- The sequence is iterated until |z| > 2 or the maximum iteration count is reached

#### 3. Burning Ship

The Burning Ship fractal uses the formula:
```
z₀ = 0
zₙ₊₁ = (|Re(zₙ)| + |Im(zₙ)|i)² + c
```

Where the real and imaginary components are made absolute before squaring.

## The Iteration Process

The core of fractal rendering involves these steps for each pixel:

1. **Convert Pixel to Complex Number**: Map screen coordinates to a section of the complex plane.
2. **Initialize**: Set up initial values (z₀ = 0 for Mandelbrot, z₀ = pixel coordinates for Julia).
3. **Iterate**: Apply the formula repeatedly, tracking the number of iterations.
4. **Determine Escape**: Check if the value has "escaped" (typically if |z| > 2).
5. **Assign Color**: Color the pixel based on the number of iterations before escape.

## Color Mapping

The beauty of fractals comes from how we color them. Common approaches include:

1. **Linear Coloring**: Directly mapping iteration count to a color palette
2. **Smooth Coloring**: Using logarithmic or other algorithms to create smooth transitions
3. **Histogram Coloring**: Distributing colors based on the frequency of iteration counts

## Zooming and Navigation

The infinite nature of fractals allows for endless exploration:

1. **Zooming**: Focusing on smaller regions of the complex plane
2. **Translation**: Moving to different areas of the fractal
3. **Parameter Adjustments**: Changing constants to explore variations

## Implementation Considerations

- **Optimization**: Fractal computation is highly parallelizable and benefits from GPU acceleration
- **Precision**: Floating-point precision limits how far you can zoom before artifacts appear
- **Interactivity**: Real-time interaction enhances the exploration experience

## Conclusion

Fractals represent the beautiful intersection of mathematics, art, and computer science. Their mesmerizing patterns emerge from simple rules applied repeatedly, demonstrating how complexity can arise from simplicity through iteration. The Fractol project provides a window into this fascinating world, allowing for interactive exploration of various fractal types.