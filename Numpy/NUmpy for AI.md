<style>
  body, p, ul, ol, li {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-size: 12pt;
    line-height: 1.6;
  }
  h1, h2, h3, h4, h5, h6 {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-weight: bold;
  }
</style>

# សៀវភៅសិក្សា៖ NumPy for AI Training

## មាតិកាសរុប (Table of Contents)
* **ជំពូកទី ១៖** សេចក្តីផ្តើមទៅកាន់ NumPy និង Google Colab សម្រាប់ AI
* **ជំពូកទី ២៖** មូលដ្ឋានគ្រឹះនៃ NDArray (Creation, Datatypes, Memory Layout)
* **ជំពូកទី ៣៖** ប្រតិបត្តិការគណិតវិទ្យា និង Broadcasting ក្នុង AI
* **ជំពូកទី ៤៖** ការរៀបចំទិន្នន័យ និង Data Preprocessing (Normalization, Standardization)
* **ជំពូកទី ៥៖** ពិជគណិតលីនេអ៊ែរ (Linear Algebra) ជាមួយ NumPy សម្រាប់ Machine Learning
* **ជំពូកទី ៦៖** ការទាញយកលក្ខណៈពិសេសទិន្នន័យ (Data Slicing, Indexing & Masking) សម្រាប់កសាង Training/Testing Sets
* **ជំពូកទី ៧៖** Vectorization - ការបង្កើនល្បឿនកូដ (ជំនួសការប្រើ For Loop) ក្នុង AI
* **ជំពូកទី ៨៖** ការអនុវត្តន៍ជាក់ស្តែងទី១៖ ការសរសេរ Forward Propagation នៃ Neural Network ជាមួយ NumPy
* **ជំពូកទី ៩៖** ការអនុវត្តន៍ជាក់ស្តែងទី២៖ ការគណនា Loss Function និង Backpropagation ជាមួយ NumPy
* **ជំពូកទី ១០៖** ការរក្សាទុកទិន្នន័យ (Saving & Loading Models/Arrays) និងគម្រោងចុងបញ្ចប់ (Final Project)

---

## ជំពូកទី ១៖ សេចក្តីផ្តើមទៅកាន់ NumPy និង Google Colab សម្រាប់ AI

### ១.១ តើអ្វីទៅជា NumPy?

**NumPy** មកពីពាក្យថា *Numerical Python* គឺជាបណ្ណាល័យ (Library) មូលដ្ឋានដ៏មានឥទ្ធិពលបំផុតសម្រាប់ការគណនាបែបវិទ្យាសាស្ត្រក្នុងភាសា Python។ នៅក្នុងវិស័យ AI និង Machine Learning, NumPy ត្រូវបានប្រើប្រាស់សម្រាប់៖
* ការគ្រប់គ្រងទិន្នន័យក្នុងទម្រង់ជាតារាងពហុវិមាត្រ (Multidimensional Arrays)
* ប្រតិបត្តិការពិជគណិតលីនេអ៊ែរ (Linear Algebra)
* ការគណនាបែប Vectorization ដើម្បីបង្កើនល្បឿន

### ១.២ ហេតុអ្វីប្រើ Google Colab?

Google Colab គឺជាបរិស្ថានដែលផ្តល់លទ្ធភាពឲ្យយើងសរសេរ និងដំណើរការកូដ Python តាមរយៈ Browser ដោយមិនចាំបាច់ដំឡើងកម្មវិធីក្នុងកុំព្យូទ័រផ្ទាល់ខ្លួនឡើយ។ វារួមបញ្ចូលស្រាប់នូវបណ្ណាល័យសំខាន់ៗដូចជា NumPy, Pandas និង Matplotlib។

### ១.៣ ការដំឡើង និងការនាំចូល NumPy (Importing NumPy)

ជាដំបូង យើងត្រូវនាំចូល NumPy មកប្រើប្រាស់ក្នុង Notebook របស់យើង។
``` py
import numpy as np

# ពិនិត្យមើលកំណែ (Version) របស់ NumPy
print(f"NumPy Version: {np.__version__}")
```

**Result**
``` py
NumPy Version: 2.0.2
```

### ១.៤ ការបង្កើត Array ដំបូងរបស់អ្នក

នៅក្នុង AI, រាល់ទិន្នន័យ (រូបភាព, សំឡេង, ឬអត្ថបទ) ត្រូវបានបំប្លែងទៅជាលេខដែលមានទម្រង់ជា Array។ ចូរក្រឡេកមើលរបៀបបង្កើត Array កម្រិត ១ វិមាត្រ (1D Array) និង ២ វិមាត្រ (2D Array)។

``` py
# បង្កើត 1D Array (Vector)
vector = np.array([1.5, 2.0, 3.7])
print("Vector:\n", vector)

# បង្កើត 2D Array (Matrix) តំណាងឲ្យទិន្នន័យ input
# ឧទាហរណ៍៖ ជួរដេកនីមួយៗគឺជា Sample, ជួរឈរនីមួយៗគឺជា Feature
matrix = np.array([[1, 2, 3], [4, 5, 6]])
print("\nMatrix:\n", matrix)

# ពិនិត្យរូបរាង (Shape) នៃ Array
print("\nShape of matrix:", matrix.shape)
```

**Result**
```py
Vector:
 [1.5 2.  3.7]

Matrix:
 [[1 2 3]
 [4 5 6]]

Shape of matrix: (2, 3)
```

### ១.៥ សារៈសំខាន់នៃ NumPy ក្នុងការបង្វឹក AI

នៅក្នុងដំណើរការបង្វឹក Neural Network ជំហានដំបូងគឺការកំណត់តម្លៃដំបូងនៃ Weights (Initializing Weights)។ ជាទូទៅ យើងមិនកំណត់ weights ឲ្យស្មើ ០ ទាំងអស់នោះទេ ប៉ុន្តែយើងប្រើលេខចៃដន្យ (Random numbers)។
```py
# បង្កើត Weight matrix ទំហំ 3x2 ដោយប្រើលេខចៃដន្យ
weights = np.random.rand(3, 2)
print("Initial Weights:\n", weights)
```

**Result**
```py
Initial Weights:
 [[0.64470734 0.96388419]
 [0.495518   0.12152579]
 [0.33017646 0.31492391]]
 ```

---
## ជំពូកទី ២៖ មូលដ្ឋានគ្រឹះនៃ NDArray (Creation, Datatypes, Memory Layout)

នៅក្នុង NumPy, សារធាតុស្នូលបំផុតគឺ `ndarray` (N-dimensional array)។ វាគឺជាតារាងនៃធាតុដែលមានប្រភេទដូចគ្នា (Homogeneous items)។

### ២.១ ការបង្កើត Array តាមវិធីផ្សេងៗ (Array Creation Routines)

ក្រៅពីការប្រើ `np.array()`, NumPy ផ្តល់មុខងារជាច្រើនទៀតសម្រាប់បង្កើត Array ដែលមានប្រយោជន៍ខ្លាំងក្នុងការរៀបចំ Neural Network Layers។

*   `np.zeros()`: បង្កើត Array ដែលមានលេខ ០ ទាំងអស់ (ប្រើសម្រាប់ Biases ក្នុង AI)
*   `np.ones()`: បង្កើត Array ដែលមានលេខ ១ ទាំងអស់
*   `np.eye()`: បង្កើត Identity Matrix (មានលេខ ១ នៅអង្កត់ទ្រូង - Diagonal)
*   `np.arange()`: បង្កើតលំដាប់លេខ (ដូច range ក្នុង Python)

```py
# បង្កើត Bias vector ដែលមានតម្លៃ ០ ចំនួន ៥
biases = np.zeros(5)
print("Zero Biases:", biases)

# បង្កើត Matrix ទំហំ 2x3 ដែលមានលេខ ១ ទាំងអស់
ones_arr = np.ones((2, 3))
print("\nOnes Matrix:\n", ones_arr)

# បង្កើត Identity Matrix ទំហំ 3x3
identity = np.eye(3)
print("\nIdentity Matrix:\n", identity)
```

**Result**
```py
Zero Biases: [0. 0. 0. 0. 0.]

Ones Matrix:
 [[1. 1. 1.]
 [1. 1. 1.]]

Identity Matrix:
 [[1. 0. 0.]
 [0. 1. 0.]
 [0. 0. 1.]]
 ```

### ២.២ ប្រភេទទិន្នន័យ (Data Types - dtype)

ក្នុងវិទ្យាសាស្ត្រទិន្នន័យ ការគ្រប់គ្រងអង្គចងចាំ (Memory) គឺសំខាន់ណាស់។ ប្រសិនបើទិន្នន័យរបស់អ្នកជាលេខរៀង (Integers) ប៉ុន្តែអ្នកប្រើ Float 64-bit វានឹងស៊ីអង្គចងចាំទ្វេដង។

ប្រភេទ dtype សំខាន់ៗ៖
*   `np.float32`: ប្រើច្រើនបំផុតក្នុង Deep Learning ព្រោះវាមានល្បឿនលឿន និងស៊ី Memory តិចជាង float64។
*   `np.int64`: ប្រើសម្រាប់ Index ឬ Label នៃទិន្នន័យ។

```py 
# បង្កើត array ជាមួយ dtype ជាក់លាក់
float_arr = np.array([1, 2, 3], dtype=np.float32)
print(f"Array: {float_arr}, Dtype: {float_arr.dtype}")

# ការបំប្លែងប្រភេទទិន្នន័យ (Casting)
int_arr = float_arr.astype(np.int64)
print(f"Converted Array: {int_arr}, Dtype: {int_arr.dtype}")
```

**Result**
```py
Array: [1. 2. 3.], Dtype: float32
Converted Array: [1 2 3], Dtype: int64
```

### ២.៣ ការរៀបចំក្នុងអង្គចងចាំ (Memory Layout)

NumPy Array រក្សាទុកទិន្នន័យក្នុងប្លុកបន្តបន្ទាប់គ្នា (Contiguous block) ក្នុង Memory។ នេះជាមូលហេតុដែលវាលឿនជាង Python List។

*   **Attributes សំខាន់ៗ៖**
    *   `ndim`: ចំនួនវិមាត្រ
    *   `size`: ចំនួនធាតុសរុប
    *   `itemsize`: ទំហំធាតុនីមួយៗជា Byte

``` py 
example = np.array([[1, 2], [3, 4], [5, 6]])

print(f"Number of dimensions: {example.ndim}")
print(f"Total elements: {example.size}")
print(f"Size of each element: {example.itemsize} bytes")
print(f"Total memory consumed: {example.nbytes} bytes")
```
**Result**
``` Py
Number of dimensions: 2
Total elements: 6
Size of each element: 8 bytes
Total memory consumed: 48 bytes
```
## ជំពូកទី ៣៖ ប្រតិបត្តិការគណិតវិទ្យា និង Broadcasting ក្នុង AI

នៅក្នុង AI យើងកម្រប្រើ `for loop` ដើម្បីគណនាលើទិន្នន័យនីមួយៗណាស់ ព្រោះវាមានល្បឿនយឺត។ NumPy អនុញ្ញាតឱ្យយើងធ្វើប្រតិបត្តិការលើ Array ទាំងមូលក្នុងពេលតែមួយ។

### ៣.១ ប្រតិបត្តិការតាមធាតុនីមួយៗ (Element-wise Operations)

រាល់ប្រតិបត្តិការគណិតវិទ្យាមូលដ្ឋានដូចជា បូក (+), ដក (-), គុណ (*), ចែក (/) ត្រូវបានអនុវត្តទៅលើធាតុដែលមានទីតាំងដូចគ្នានៃ Array។

``` py
import numpy as np

x = np.array([1, 2, 3])
y = np.array([4, 5, 6])

print("Addition (x + y):", x + y)
print("Multiplication (x * y):", x * y)
print("Power (x^2):", x ** 2)
```
**Result**
``` py
Addition (x + y): [5 7 9]
Multiplication (x * y): [ 4 10 18]
Power (x^2): [1 4 9]
```
### ៣.២ Broadcasting ក្នុង AI

**Broadcasting** គឺជាសមត្ថភាពរបស់ NumPy ក្នុងការធ្វើប្រតិបត្តិការរវាង Array ដែលមានរូបរាង (Shape) ខុសគ្នា។ នេះមានសារៈសំខាន់ខ្លាំងនៅពេលយើងចង់បូកតម្លៃ Bias ទៅកាន់គ្រប់ Sample ក្នុង Dataset។

**ច្បាប់នៃ Broadcasting:**
១. ប្រសិនបើ Array ទាំងពីរមានចំនួនវិមាត្រខុសគ្នា Array ដែលមានវិមាត្រតិចជាង នឹងត្រូវបានបន្ថែមវិមាត្រ ១ នៅខាងឆ្វេង។
២. ប្រសិនបើរូបរាងមិនដូចគ្នា វិមាត្រដែលមានទំហំ ១ នឹងត្រូវបានពន្លាតឱ្យស្មើនឹងទំហំនៃ Array ម្ខាងទៀត។


``` py
# ឧទាហរណ៍៖ បូក Bias ទៅកាន់ Input Data
# Data: 3 samples, 2 features
data = np.array([[10, 20], [30, 40], [50, 60]])
# Bias: 1 value សម្រាប់ feature នីមួយៗ
bias = np.array([1, 2])

# ការបូកនេះនឹងប្រើ Broadcasting
result = data + bias

print("Original Data:\n", data)
print("\nBias:", bias)
print("\nResult (Data + Bias):\n", result)
```
**Result**
``` py
Original Data:
 [[10 20]
 [30 40]
 [50 60]]

Bias: [1 2]

Result (Data + Bias):
 [[11 22]
 [31 42]
 [51 62]]
 ```

### ៣.៣ អនុគមន៍គណិតវិទ្យាសម្រាប់ AI (Universal Functions)

NumPy ផ្តល់នូវអនុគមន៍ដូចជា `np.exp()` (ប្រើក្នុង Activation Functions ដូចជា Sigmoid) និង `np.log()` (ប្រើក្នុង Loss Functions)។

``` py
z = np.array([0, 1, 2])

# គណនា Exponential e^z
exp_z = np.exp(z)
print("Exponential:", exp_z)

# ឧទាហរណ៍៖ Sigmoid Activation Function
# formula: 1 / (1 + e^-z)
sigmoid = 1 / (1 + np.exp(-z))
print("\nSigmoid values:", sigmoid)
```
**Result**
```py
Exponential: [1.         2.71828183 7.3890561 ]

Sigmoid values: [0.5        0.73105858 0.88079708]
```

## ជំពូកទី ៤៖ ការរៀបចំទិន្នន័យ និង Data Preprocessing (Normalization, Standardization)

មុននឹងបញ្ចូលទិន្នន័យទៅក្នុង AI Model យើងត្រូវធ្វើការបំប្លែងវាឱ្យស្ថិតក្នុងមាត្រដ្ឋាន (Scale) មួយដែលសមស្រប ដើម្បីឱ្យ Model ឆាប់រៀនចេះ (Converge)។

### ៤.១ ការធ្វើ Normalization (Min-Max Scaling)

Normalization គឺជាការបំប្លែងតម្លៃទិន្នន័យឱ្យស្ថិតនៅចន្លោះ $[0, 1]$។

**រូបមន្ត LaTeX:**
$$X_{norm} = \frac{X - X_{min}}{X_{max} - X_{min}}$$

វាមានប្រយោជន៍ខ្លាំងសម្រាប់រូបភាព (Image processing) ដែល Pixel មានតម្លៃពី ០ ដល់ ២៥៥។

```py
# ឧទាហរណ៍៖ ទិន្នន័យ Pixel នៃរូបភាព
pixels = np.array([0, 64, 128, 255])

# រកតម្លៃអប្បបរមា និងអតិបរមា
p_min = pixels.min()
p_max = pixels.max()

# គណនា Normalization
normalized_pixels = (pixels - p_min) / (p_max - p_min)

print(f"Original Pixels: {pixels}")
print(f"Normalized Pixels: {normalized_pixels}")
```
**Result**
``` py
Original Pixels: [  0  64 128 255]
Normalized Pixels: [0.         0.25098039 0.50196078 1.        ]
```
### ៤.២ ការធ្វើ Standardization (Z-score Normalization)

Standardization បំប្លែងទិន្នន័យឱ្យមានមធ្យមភាគ (Mean) ស្មើ ០ និងគម្លាតស្តង់ដារ (Standard Deviation) ស្មើ ១។

**រូបមន្ត LaTeX:**
$$X_{std} = \frac{X - \mu}{\sigma}$$

ដែល $\mu$ គឺជា Mean និង $\sigma$ គឺជា Standard Deviation។

``` py
# ទិន្នន័យ Input (ឧទាហរណ៍៖ កម្ពស់មនុស្សជាសង់ទីម៉ែត្រ)
heights = np.array([150, 160, 170, 180, 190])

mean = np.mean(heights)
std = np.std(heights)

# គណនា Standardization
standardized_heights = (heights - mean) / std

print(f"Mean: {mean}, Std: {std:.2f}")
print(f"Standardized Heights: {standardized_heights}")
print(f"New Mean: {np.mean(standardized_heights):.1f}")
print(f"New Std: {np.std(standardized_heights):.1f}")
```
**Result**
``` py
Mean: 170.0, Std: 14.14
Standardized Heights: [-1.41421356 -0.70710678  0.          0.70710678  1.41421356]
New Mean: 0.0
New Std: 1.0
```
## ជំពូកទី ៥៖ ពិជគណិតលីនេអ៊ែរ (Linear Algebra) ជាមួយ NumPy សម្រាប់ Machine Learning

នៅក្នុង Machine Learning, ប្រតិបត្តិការដែលប្រើញឹកញាប់បំផុតគឺការគុណម៉ាទ្រីស (Matrix Multiplication) ដើម្បីគណនាទិន្នផលនៃស្រទាប់នីមួយៗក្នុង Neural Network។

### ៥.១ ផលគុណស្កាលែ (Dot Product)

Dot Product រវាង Vector ពីរ គឺជាផលបូកនៃផលគុណរវាងធាតុដែលមានសន្ទស្សន៍ (Index) ដូចគ្នា។

**រូបមន្ត LaTeX:**
$$a \cdot b = \sum_{i=1}^{n} a_i b_i$$

ក្នុង NumPy យើងប្រើ `np.dot()` ឬ operator `@`។

``` py
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

# វិធីទី១៖ ប្រើ np.dot()
dot_product = np.dot(a, b)

# វិធីទី២៖ ប្រើ @ operator
dot_product_alt = a @ b

print(f"Vector a: {a}")
print(f"Vector b: {b}")
print(f"Dot Product: {dot_product}")
```
**Result**
``` py
Vector a: [1 2 3]
Vector b: [4 5 6]
Dot Product: 32
```
### ៥.២ ការគុណម៉ាទ្រីស (Matrix Multiplication)

នេះគឺជាប្រតិបត្តិការគ្រឹះសម្រាប់ Forward Propagation។ ប្រសិនបើយើងមាន Input $X$ និង Weights $W$, ទិន្នផល $Z$ ត្រូវបានគណនាដោយ $Z = X \cdot W$។

**លក្ខខណ្ឌ៖** ចំនួនជួរឈរ (Columns) នៃម៉ាទ្រីសទី១ ត្រូវតែស្មើនឹងចំនួនជួរដេក (Rows) នៃម៉ាទ្រីសទី២។
```py
# Input X: 2 samples, 3 features
X = np.array([[1, 2, 3],
              [4, 5, 6]])

# Weights W: 3 inputs, 2 neurons (outputs)
W = np.array([[0.1, 0.2],
              [0.3, 0.4],
              [0.5, 0.6]])

# ការគុណម៉ាទ្រីស (Matrix Multiplication)
Z = np.matmul(X, W)
# ឬ Z = X @ W

print("Input X (2x3):\n", X)
print("\nWeights W (3x2):\n", W)
print("\nOutput Z (2x2):\n", Z)
```
**Result**
```py
Input X (2x3):
 [[1 2 3]
 [4 5 6]]

Weights W (3x2):
 [[0.1 0.2]
 [0.3 0.4]
 [0.5 0.6]]

Output Z (2x2):
 [[2.2 2.8]
 [4.9 6.4]]
 ```
**Result**
``` py
Original (2x3):
 [[1 2 3]
 [4 5 6]]

Transposed (3x2):
 [[1 4]
 [2 5]
 [3 6]]
 ```

### ៥.៣ ការត្រឡប់ម៉ាទ្រីស (Matrix Transpose)

Transpose គឺជាការប្តូរជួរដេកទៅជាជួរឈរ និងជួរឈរទៅជាជួរដេកវិញ។ វាមានសារៈសំខាន់ខ្លាំងក្នុងដំណាក់កាល Backpropagation ដើម្បីឱ្យទំហំម៉ាទ្រីសត្រូវគ្នាសម្រាប់ការគុណ។

```py
original = np.array([[1, 2, 3], [4, 5, 6]])
transposed = original.T

print("Original (2x3):\n", original)
print("\nTransposed (3x2):\n", transposed)
```
## ជំពូកទី ៦៖ ការទាញយកលក្ខណៈពិសេសទិន្នន័យ (Data Slicing, Indexing & Masking) សម្រាប់កសាង Training/Testing Sets

ការរៀបចំទិន្នន័យសម្រាប់ AI តម្រូវឱ្យយើងចេះបំបែកទិន្នន័យ (Slicing) និងជ្រើសរើសទិន្នន័យតាមលក្ខខណ្ឌ (Masking)។

### ៦.១ ការធ្វើ Slicing លើ Array

យើងប្រើ syntax `[start:stop:step]` ដើម្បីទាញយកផ្នែកណាមួយនៃ Array។ ក្នុង AI វាតែងត្រូវបានប្រើដើម្បីបំបែក Labels ចេញពី Features។

```py
import numpy as np

# ឧបមាថាមានទិន្នន័យ ៥ ជួរ (Samples) និង ៤ ជួរឈរ (Features + Label)
dataset = np.array([
    [1.2, 0.5, 0.1, 0],
    [0.9, 0.1, 0.8, 1],
    [2.1, 1.1, 0.2, 0],
    [1.5, 0.4, 0.9, 1],
    [3.0, 1.5, 0.3, 0]
])

# ទាញយកគ្រប់ជួរដេក ប៉ុន្តែយកតែ ៣ ជួរឈរដំបូង (Features)
X = dataset[:, :3]

# ទាញយកគ្រប់ជួរដេក ប៉ុន្តែយកតែជួរឈរចុងក្រោយ (Label)
y = dataset[:, -1]

print("Features (X):\n", X)
print("\nLabels (y):", y)
```

**Result**
```py
Features (X):
 [[1.2 0.5 0.1]
 [0.9 0.1 0.8]
 [2.1 1.1 0.2]
 [1.5 0.4 0.9]
 [3.  1.5 0.3]]

Labels (y): [0. 1. 0. 1. 0.]
```

### ៦.២ Boolean Indexing (Masking)

Masking អនុញ្ញាតឱ្យយើងជ្រើសរើសធាតុដែលផ្ទៀងផ្ទាត់លក្ខខណ្ឌណាមួយ។ នេះមានប្រយោជន៍ពេលយើងចង់ច្រោះ (Filter) ទិន្នន័យមិនល្អចេញ ឬបំបែកថ្នាក់ (Classes) នៃទិន្នន័យ។

``` py
scores = np.array([0.85, 0.42, 0.91, 0.55, 0.38])

# បង្កើត Mask សម្រាប់ពិន្ទុដែលធំជាង ០.៥
mask = (scores > 0.5)

filtered_scores = scores[mask]

print("Original Scores:", scores)
print("Mask:", mask)
print("Filtered Scores ( > 0.5):", filtered_scores)
```

**Result**
``` py
Original Scores: [0.85 0.42 0.91 0.55 0.38]
Mask: [ True False  True  True False]
Filtered Scores ( > 0.5): [0.85 0.91 0.55]
```

### ៦.៣ ការបែងចែក Training/Testing Sets ដោយប្រើ Shuffle

ដើម្បីកុំឱ្យ Model ចងចាំលំដាប់ទិន្នន័យ យើងត្រូវធ្វើការ Shuffle (ច្របល់) មុននឹងបែងចែក។

``` py
# ច្របល់ Index
indices = np.arange(dataset.shape[0])
np.random.shuffle(indices)

shuffled_dataset = dataset[indices]

# បែងចែក ៨០% សម្រាប់បង្វឹក និង ២០% សម្រាប់តេស្ត
train_size = int(0.8 * len(shuffled_dataset))

train_data = shuffled_dataset[:train_size]
test_data = shuffled_dataset[train_size:]

print(f"Total samples: {len(dataset)}")
print(f"Training samples: {len(train_data)}")
print(f"Testing samples: {len(test_data)}")
```

**Result**
``` py
Total samples: 5
Training samples: 4
Testing samples: 1
```

## ជំពូកទី ៧៖ Vectorization - ការបង្កើនល្បឿនកូដ (ជំនួសការប្រើ For Loop) ក្នុង AI

**Vectorization** គឺជាសមត្ថភាពរបស់ NumPy ក្នុងការអនុវត្តប្រតិបត្តិការលើ Array ទាំងមូលដោយប្រើកូដ C ដែលបានធ្វើ Optimization រួចជាស្រេចនៅខាងក្រោម (Under the hood)។

### ៧.១ ការប្រៀបធៀបល្បឿនរវាង For Loop និង Vectorization

ឧបមាថាយើងមានទិន្នន័យ ១ លានលេខ ហើយយើងចង់បូកលេខទាំងនោះជាមួយលេខ ៥។

``` py
import time
import numpy as np

# បង្កើតទិន្នន័យ ១ លានលេខ
n = 1000000
data_list = list(range(n))
data_array = np.arange(n)

# ១. ការប្រើ For Loop (Python List)
start_time = time.time()
result_list = [x + 5 for x in data_list]
end_time = time.time()
print(f"For Loop Time: {end_time - start_time:.5f} វិនាទី")

# ២. ការប្រើ Vectorization (NumPy Array)
start_time = time.time()
result_array = data_array + 5
end_time = time.time()
print(f"Vectorization Time: {end_time - start_time:.5f} វិនាទី")
```
**Result**
``` py
For Loop Time: 0.08640 វិនាទី
Vectorization Time: 0.00546 វិនាទី
```
### ៧.២ ការអនុវត្ត Vectorization ក្នុង AI

នៅពេលគណនា Activation Function ដូចជា ReLU ($max(0, x)$) សម្រាប់គ្រប់ Neuron ក្នុងស្រទាប់មួយ យើងប្រើ Vectorization ដើម្បីបញ្ចប់វាក្នុងពេលតែមួយ។

```py
# ឧបមាថា Z គឺជា output មកពី Linear Layer (មុន Activation)
Z = np.array([-2.5, 1.2, -0.1, 4.8, 0.0])

# ប្រើ Vectorization ដើម្បីអនុវត្ត ReLU
# ReLU(x) = max(0, x)
activation = np.maximum(0, Z)

print("Linear Output (Z):", Z)
print("ReLU Activation:", activation)
```
**Result**
```py
Linear Output (Z): [-2.5  1.2 -0.1  4.8  0. ]
ReLU Activation: [0.  1.2 0.  4.8 0. ]
```

## ជំពូកទី ៨៖ ការអនុវត្តន៍ជាក់ស្តែងទី១៖ ការសរសេរ Forward Propagation នៃ Neural Network ជាមួយ NumPy

នៅក្នុងជំពូកនេះ យើងនឹងបង្កើត Neural Network ដ៏សាមញ្ញមួយដែលមាន Layer ចំនួនពីរ (Input Layer, Hidden Layer, និង Output Layer)។

### ៨.១ ទ្រឹស្តីនៃ Forward Propagation

សម្រាប់ស្រទាប់នីមួយៗក្នុងបណ្តាញប្រសាទ ដំណើរការគណនាមានពីរជំហាន៖
1.  **Linear Transformation:** $Z = X \cdot W + b$
2.  **Activation Function:** $A = \sigma(Z)$ (យើងនឹងប្រើ Sigmoid សម្រាប់ Hidden Layer និង Output)

ដែល $X$ ជា Input, $W$ ជា Weights, $b$ ជា Bias, និង $\sigma$ ជាអនុគមន៍សកម្ម។

```py
import numpy as np

# ១. កំណត់អនុគមន៍ Sigmoid
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# ២. រៀបចំទិន្នន័យ Input (ឧទាហរណ៍៖ ៣ ករណី, ករណីនីមួយៗមាន ៤ features)
np.random.seed(42)
X = np.random.randn(3, 4)

# ៣. កំណត់ Weights និង Biases សម្រាប់ Hidden Layer (មាន ៥ neurons)
W1 = np.random.randn(4, 5)
b1 = np.zeros((1, 5))

# ៤. កំណត់ Weights និង Biases សម្រាប់ Output Layer (មាន ១ neuron)
W2 = np.random.randn(5, 1)
b2 = np.zeros((1, 1))

print("Input Shape:", X.shape)
print("Weights 1 Shape:", W1.shape)
print("Weights 2 Shape:", W2.shape)
```
**Result**
``` py
Input Shape: (3, 4)
Weights 1 Shape: (4, 5)
Weights 2 Shape: (5, 1)
```

### ៨.២ ការគណនា Forward Pass

ឥឡូវយើងអនុវត្តការគណនាជាបន្តបន្ទាប់ពីស្រទាប់មួយទៅស្រទាប់មួយទៀត។
```py
# ជំហានទី ១៖ គណនា Hidden Layer
Z1 = np.dot(X, W1) + b1
A1 = sigmoid(Z1)

# ជំហានទី ២៖ គណនា Output Layer
Z2 = np.dot(A1, W2) + b2
A2 = sigmoid(Z2)

print("Hidden Layer Output (A1) Shape:", A1.shape)
print("\nFinal Prediction (A2):\n", A2)
```
**Result**
```py
Hidden Layer Output (A1) Shape: (3, 5)

Final Prediction (A2):
 [[0.49876734]
 [0.46242694]
 [0.23183298]]
 ```

 ## ជំពូកទី ៩៖ ការអនុវត្តន៍ជាក់ស្តែងទី២៖ ការគណនា Loss Function និង Backpropagation ជាមួយ NumPy

បន្ទាប់ពីទទួលបានលទ្ធផលពី Forward Pass យើងត្រូវដឹងថា តើលទ្ធផលនោះខុសគ្នាពីការពិត (Ground Truth) កម្រិតណា។

### ៩.១ ការគណនា Mean Squared Error (MSE)

MSE ត្រូវបានប្រើជាទូទៅសម្រាប់បញ្ហា Regression ដើម្បីវាស់ស្ទង់កំហុសមធ្យម។

**រូបមន្ត LaTeX:**
$$MSE = \frac{1}{n} \sum_{i=1}^{n} (y_{true} - y_{pred})^2$$
```py
# ឧបមាថា A2 មកពីជំពូកទី ៨ ជាការព្យាករណ៍ (y_pred)
y_true = np.array([[0.5], [0.8], [0.2]])

def mse_loss(y_true, y_pred):
    return np.mean((y_true - y_pred)**2)

loss = mse_loss(y_true, A2)
print(f"Prediction (A2):\n{A2}")
print(f"\nGround Truth (y_true):\n{y_true}")
print(f"\nMSE Loss: {loss:.5f}")
```
**Result**
```py
Prediction (A2):
[[0.49876734]
 [0.46242694]
 [0.23183298]]

Ground Truth (y_true):
[[0.5]
 [0.8]
 [0.2]]

MSE Loss: 0.03832
```
### ៩.២ មូលដ្ឋានគ្រឹះនៃ Backpropagation ជាមួយ NumPy

Backpropagation ប្រើច្បាប់ Chain Rule នៃដេរីវេ (Calculus) ដើម្បីរកមើលថាតើ Weights នីមួយៗរួមចំណែកដល់កំហុសប៉ុណ្ណា។

សម្រាប់ Sigmoid Layer, ដេរីវេនៃ $A$ ធៀបនឹង $Z$ គឺ៖
$$\frac{dA}{dZ} = A(1 - A)$$

យើងប្រើវាដើម្បីរក Gradient និងកែតម្រូវ Weights (Optimization)។

```py
# ១. គណនាកំហុសនៅ Output Layer (Error)
error = A2 - y_true

# ២. គណនា Gradient នៃ Output Layer
# dZ2 = error * sigmoid_derivative(Z2)
dZ2 = error * (A2 * (1 - A2))

# ៣. គណនា Gradient សម្រាប់ Weights (dW2)
dW2 = np.dot(A1.T, dZ2)

print("Gradient for W2 (dW2):\n", dW2)

# ៤. ការកែតម្រូវ Weights (Gradient Descent step)
learning_rate = 0.1
W2 -= learning_rate * dW2
print("\nWeights W2 after one update step:\n", W2)
```
**Result**
```py
Gradient for W2 (dW2):
 [[-0.04506219]
 [-0.00509039]
 [-0.03133154]
 [-0.02734062]
 [-0.03712211]]

Weights W2 after one update step:
 [[-0.00899101]
 [-1.05720189]
 [ 0.82567807]
 [-1.21810959]
 [ 0.21257581]]
 ```

 ## ជំពូកទី ១០៖ ការរក្សាទុកទិន្នន័យ និងគម្រោងចុងបញ្ចប់ (Final Project)

នៅក្នុងជំពូកចុងក្រោយនេះ យើងនឹងរៀនពីរបៀបរក្សាទុក Weights ដែលយើងបានបង្វឹក និងបង្កើតគម្រោងតូចមួយដើម្បីសរុបខ្លឹមសារមេរៀន។

### ១០.១ ការរក្សាទុក និងទាញយក Array (Saving & Loading)

បន្ទាប់ពីបង្វឹក AI រួច យើងត្រូវរក្សាទុកតម្លៃ Weights ទៅក្នុង File ដើម្បីប្រើប្រាស់នៅពេលក្រោយដោយមិនចាំបាច់បង្វឹកឡើងវិញ។ NumPy ប្រើប្រាស់ទម្រង់ `.npy` សម្រាប់ឯកសារទិន្នន័យលីនេអ៊ែរ។
```py
import numpy as np

# ឧបមាថា W2 គឺជា Weights ដែលបានបង្វឹកមករួចរាល់
# រក្សាទុកទៅក្នុង file
np.save('trained_weights_w2.npy', W2)

# ទាញយកមកប្រើប្រាស់វិញ
loaded_w2 = np.load('trained_weights_w2.npy')

print("Original W2 Shape:", W2.shape)
print("Loaded W2 Shape:", loaded_w2.shape)
print("Check equality:", np.allclose(W2, loaded_w2))
```
**Result**
``` py
Original W2 Shape: (5, 1)
Loaded W2 Shape: (5, 1)
Check equality: True
```
### ១០.២ គម្រោងចុងបញ្ចប់៖ សាងសង់ Simple Neural Network Trainer

ចូរប្រើប្រាស់ NumPy ដើម្បីសរសេរ Loop សម្រាប់បង្វឹក Network សាមញ្ញមួយឱ្យរៀនស្គាល់លំនាំទិន្នន័យ (Pattern Recognition)។

```py
def sigmoid(x): return 1 / (1 + np.exp(-x))
def sigmoid_derivative(x): return x * (1 - x)

# Dataset: XOR-like logic gate
X = np.array([[0,0], [0,1], [1,0], [1,1]])
y = np.array([[0], [1], [1], [0]])

# Initialize Weights
np.random.seed(1)
W_hidden = np.random.uniform(size=(2, 4))
W_output = np.random.uniform(size=(4, 1))

# Training Loop (1000 epochs)
for epoch in range(1000):
    # Forward Pass
    layer1 = sigmoid(np.dot(X, W_hidden))
    output = sigmoid(np.dot(layer1, W_output))

    # Backpropagation
    error = y - output
    d_output = error * sigmoid_derivative(output)

    error_hidden = d_output.dot(W_output.T)
    d_hidden = error_hidden * sigmoid_derivative(layer1)

    # Updating Weights
    W_output += layer1.T.dot(d_output) * 0.1
    W_hidden += X.T.dot(d_hidden) * 0.1

print("Final Predictions after training:")
print(output.round(2))
```
**Result**
```py
Final Predictions after training:
[[0.5]
 [0.5]
 [0.5]
 [0.5]]
 ```
 ## 📝 សេចក្តីសង្ខេបមេរៀន (Course Summary)

ឆ្លងកាត់ការសិក្សាទាំង ១០ ជំពូក អ្នកបានក្តាប់ជាប់នូវមូលដ្ឋានគ្រឹះបច្ចេកទេសសំខាន់ៗរួមមាន៖

1.  **NumPy Fundamentals:** ការយល់ដឹងពី `ndarray`, ប្រភេទទិន្នន័យ (`dtype`) និងការគ្រប់គ្រង Memory ដែលមានប្រសិទ្ធភាពជាង Python List។
2.  **Broadcasting & Vectorization:** បច្ចេកទេសសរសេរកូដឱ្យលឿនបំផុតដោយមិនប្រើ `for loop` ដែលជាបេះដូងនៃ High-performance AI computing។
3.  **Linear Algebra:** ការអនុវត្ត `Dot Product` និង `Matrix Multiplication` ដែលជាប្រតិបត្តិការចម្បងក្នុង Neural Networks។
4.  **Data Preprocessing:** របៀបបំប្លែងទិន្នន័យតាមរយៈ `Normalization` និង `Standardization` ដើម្បីឱ្យ Model ឆាប់រៀនចេះ។
5.  **Neural Network Logic:** ការបង្កើត `Forward Propagation` (ការទស្សន៍ទាយ) និង `Backpropagation` (ការរៀនពីកំហុស) ដោយប្រើ Calculus មូលដ្ឋាន។
6.  **Model Management:** ការរក្សាទុក និងទាញយក Weights មកប្រើប្រាស់ឡើងវិញតាមរយៈ `.npy` files។

**ជំហានបន្ទាប់:**
អ្នកអាចសាកល្បងអនុវត្តបន្ថែមលើ Dataset ធំៗ ឬឈានទៅសិក្សាបណ្ណាល័យ **Pandas** (សម្រាប់ Data Manipulation) និង **Matplotlib** (សម្រាប់ Data Visualization) ដើម្បីពង្រឹងសមត្ថភាពជា Data Scientist ពេញលេញ។

---
## សេចក្តីសន្និដ្ឋាន

អបអរសាទរ! អ្នកបានបញ្ចប់សៀវភៅសិក្សា **"NumPy for AI Training"**។ អ្នកបានរៀនតាំងពីមូលដ្ឋានគ្រឹះ NDArray រហូតដល់ការសរសេរ Backpropagation ទាំងស្រុងដោយប្រើ NumPy។ ចំណេះដឹងទាំងនេះគឺជាគ្រឹះដ៏រឹងមាំបំផុតសម្រាប់ឈានទៅសិក្សា Frameworks ធំៗដូចជា TensorFlow ឬ PyTorch នាពេលអនាគត។

**សូមអរគុណ!**

# 📝 វិញ្ញាសាតេស្តសមត្ថភាព (Competency Test)

សូមជ្រើសរើសចម្លើយដែលត្រឹមត្រូវបំផុតសម្រាប់សំនួរខាងក្រោម៖

### ផ្នែកទី ១៖ មូលដ្ឋានគ្រឹះ NumPy (ជំពូក ១-២)
1. **តើ NumPy មកពីពាក្យពេញថាអ្វី?**
   - ក. Number Python
   - ខ. Numerical Python
   - គ. Numeric Pi
2. **តើ command ណាដែលប្រើសម្រាប់ពិនិត្យមើល Version របស់ NumPy?**
3. **តើ `np.zeros((2, 3))` បង្កើត Array ដែលមានរូបរាង (Shape) បែបណា?**
4. **តើ dtype ណាដែលនិយមប្រើបំផុតក្នុង Deep Learning ដើម្បីសន្សំ Memory?**
5. **តើអ្វីទៅជា ndarray?**

### ផ្នែកទី ២៖ ប្រតិបត្តិការ និង Broadcasting (ជំពូក ៣-៥)
6. **តើអ្វីទៅជាអត្ថប្រយោជន៍ចម្បងនៃ Vectorization?**
7. **ប្រសិនបើ `A.shape = (3, 1)` និង `B.shape = (1, 5)` តើ `A + B` អាចធ្វើទៅបានដែរឬទេ? ព្រោះអ្វី?**
8. **ចូរប្រាប់រូបមន្ត Normalization (Min-Max Scaling)។**
9. **តើ `np.dot(a, b)` និង `a * b` ខុសគ្នាយ៉ាងដូចម្តេច?**
10. **តើការធ្វើ Transpose ម៉ាទ្រីស មានន័យដូចម្តេច?**

### ផ្នែកទី ៣៖ ការរៀបចំទិន្នន័យ (ជំពូក ៦-៧)
11. **តើ `arr[:, :2]` មានន័យដូចម្តេច?**
12. **តើ Boolean Indexing (Masking) ប្រើសម្រាប់អ្វី?**
13. **ហេតុអ្វីយើងត្រូវធ្វើ Shuffle ទិន្នន័យមុននឹងបែងចែក Train/Test sets?**
14. **តើ `np.reshape(arr, (-1, 1))` ធ្វើអ្វីខ្លះដល់ Array?**
15. **តើ `np.maximum(0, x)` គឺជាអនុគមន៍សកម្ម (Activation Function) ឈ្មោះអ្វី?**

### ផ្នែកទី ៤៖ Neural Network & Calculus (ជំពូក ៨-៩)
16. **ចូរប្រាប់រូបមន្ត Linear Transformation ក្នុង Neural Layer។**
17. **តើ Sigmoid Function ផ្តល់តម្លៃស្ថិតក្នុងចន្លោះលេខប៉ុន្មានទៅប៉ុន្មាន?**
18. **តើ Forward Propagation គឺជាអ្វី?**
19. **តើ MSE Loss វាស់ស្ទង់ពីអ្វី?**
20. **តើ Backpropagation ប្រើច្បាប់អ្វីក្នុង Calculus ដើម្បីគណនា Gradient?**
21. **តើ Learning Rate មានតួនាទីអ្វីក្នុង Gradient Descent?**
22. **ប្រសិនបើ Loss មិនថយចុះសោះ តើអ្នកគួរពិនិត្យចំណុចណាខ្លះ?**
23. **តើដេរីវេនៃ Sigmoid $A$ ស្មើនឹងអ្វី?**
24. **តើ Bias ជួយអ្វីខ្លះដល់ Model?**
25. **តើ Weights ត្រូវបានកំណត់តម្លៃដំបូងដោយរបៀបណាទើបល្អ?**

### ផ្នែកទី ៥៖ ការអនុវត្ត និងការរក្សាទុក (ជំពូក ១០)
26. **តើ extension file របស់ NumPy Array គឺអ្វី?**
27. **តើ `np.save()` និង `np.load()` ប្រើសម្រាប់អ្វី?**
28. **តើ `np.allclose(a, b)` ប្រើសម្រាប់ពិនិត្យអ្វី?**
29. **នៅក្នុង Project XOR តើ Hidden Layer មានតួនាទីអ្វី?**
30. **តើអ្វីទៅជា 'Epoch' ក្នុងការបង្វឹក Model?**

---
*ចំណាំ៖ អ្នកអាចសាកល្បងសរសេរកូដក្នុង Cell ខាងក្រោមដើម្បីផ្ទៀងផ្ទាត់ចម្លើយ!*

# 🔑 ចម្លើយសម្រាប់វិញ្ញាសាតេស្តសមត្ថភាព (Answer Key)

### ផ្នែកទី ១៖ មូលដ្ឋានគ្រឹះ NumPy
1.  **ខ. Numerical Python**
2.  `np.__version__`
3.  Array ២ វិមាត្រ ដែលមាន ២ ជួរដេក និង ៣ ជួរឈរ។
4.  `np.float32` (ព្រោះវាមានតុល្យភាពរវាងភាពច្បាស់លាស់ និងការប្រើ Memory)។
5.  គឺជា Multi-dimensional Array Object ដែលមានធាតុជាប្រភេទតែមួយ (Homogeneous)។

### ផ្នែកទី ២៖ ប្រតិបត្តិការ និង Broadcasting
6.  បង្កើនល្បឿនគណនាដោយប្រើ Parallel Processing ជំនួសឱ្យ Python Loops។
7.  **បាន** ព្រោះវាអនុលោមតាមច្បាប់ Broadcasting (វិមាត្រដែលមានទំហំ ១ នឹងត្រូវបានពង្រីក)។
8.  $X_{norm} = \frac{X - X_{min}}{X_{max} - X_{min}}$
9.  `np.dot(a, b)` គឺជា Matrix Multiplication (Dot Product) ចំណែក `a * b` គឺជា Element-wise multiplication (គុណតាមធាតុនីមួយៗ)។
10. ការប្តូរជួរឈរ (Columns) ទៅជាជួរដេក (Rows) និងច្រាសមកវិញ។

### ផ្នែកទី ៣៖ ការរៀបចំទិន្នន័យ
11. យកគ្រប់ជួរដេក ប៉ុន្តែយកតែ ២ ជួរឈរដំបូងប៉ុណ្ណោះ។
12. ប្រើសម្រាប់ជ្រើសរើសទិន្នន័យតាមរយៈលក្ខខណ្ឌ Logic (ឧទាហរណ៍៖ យកតែលេខ > 0)។
13. ដើម្បីកុំឱ្យ Model ចងចាំលំដាប់លំដោយទិន្នន័យ (Bias) និងឱ្យការបែងចែកមានលក្ខណៈចៃដន្យល្អ។
14. ប្តូរទម្រង់ Array ឱ្យទៅជាជួរឈរតែមួយ ដោយរក្សាចំនួនធាតុនៅដដែល។
15. ReLU (Rectified Linear Unit)។

### ផ្នែកទី ៤៖ Neural Network & Calculus
16. $Z = X \cdot W + b$
17. ចន្លោះពី 0 ដល់ 1។
18. ដំណើរការគណនាទិន្នន័យពី Input ឆ្លងកាត់ Layers ដើម្បីទទួលបានការព្យាករណ៍ (Prediction)។
19. វាស់ស្ទង់ពីគម្លាតមធ្យមរវាងតម្លៃពិត និងតម្លៃព្យាករណ៍ (Error)។
20. Chain Rule។
21. កំណត់ទំហំជំហាន (Step size) ក្នុងការកែតម្រូវ Weights ដើម្បីឆ្ពោះទៅរក Minimum Loss។
22. ពិនិត្យ Learning Rate (ប្រហែលតូចពេក), ការធ្វើ Normalization, ឬការកំណត់ Weights ដំបូង។
23. $A(1 - A)$
24. ជួយឱ្យ Model អាចបត់បែន (Shift) ការទស្សន៍ទាយបានប្រសើរជាងមុន។
25. កំណត់ដោយប្រើលេខចៃដន្យតូចៗ (Random Initialization) មិនមែន ០ ទាំងអស់ទេ។

### ផ្នែកទី ៥៖ ការអនុវត្ត និងការរក្សាទុក
26. `.npy`
27. `np.save()` ប្រើសម្រាប់រក្សាទុក Array ទៅក្នុង Disk និង `np.load()` ប្រើសម្រាប់ទាញយកមកវិញ។
28. ពិនិត្យមើលថាតើ Array ពីរមានតម្លៃស្មើគ្នាឬអត់ (ដោយអនុញ្ញាតឱ្យមានលំអៀងតូចបំផុត)។
29. ដើម្បីរៀនពីលក្ខណៈមិនមែនលីនេអ៊ែរ (Non-linear features) ដែល Input ធម្មតាមិនអាចបំបែកបាន។
30. ចំនួនដងដែល Model ហ្វឹកហាត់លើ Dataset ទាំងមូលបានចប់សព្វគ្រប់ ១ ជុំ។