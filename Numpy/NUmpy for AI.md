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
