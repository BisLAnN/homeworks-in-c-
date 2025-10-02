# Geometry Area Calculator

A C++ program that calculates the area of triangles and parallelograms with robust input validation and error handling.

## Features

- **Area Calculations**:
  - Triangle area: `0.5 * base * height`
  - Parallelogram area: `base * height`
- **Input Validation**:
  - Handles both dot (.) and comma (,) as decimal separators
  - Validates numeric input and prevents multiple decimal points
  - Ensures positive values greater than zero
  - Detects potential overflow in calculations
- **User-Friendly Interface**:
  - Clear menu-driven interface
  - Precise output with 2 decimal places
  - Comprehensive error messages

## Code Structure

### Functions

- `parallelogramArea(double base, double height)`: Calculates parallelogram area
- `triangleArea(double base, double height)`: Calculates triangle area using a constant coefficient
- `getPositiveInput(const string& prompt, double& value)`: Handles user input with validation

### Key Features

- **Constants**: `TRIANGLE_COEFF` for maintainability
- **Error Handling**: Comprehensive input validation and overflow detection
- **Localization Support**: Accepts both '.' and ',' as decimal separators
- **Memory Safe**: Proper stream handling and bounds checking

### Usage
**Choose a figure to calculate area:**
- 1 - Triangle
- 2 - Parallelogram
- 0 - Exit


### Input
- Enter your choice: 1
- Enter base: 5,5
- Enter height: 3.2


### Output
**Area of Triangle = 8.80**
