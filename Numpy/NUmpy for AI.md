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
### ១.៥ សារៈសំខាន់នៃ NumPy ក្នុងការបង្វឹក AI

នៅក្នុងដំណើរការបង្វឹក Neural Network ជំហានដំបូងគឺការកំណត់តម្លៃដំបូងនៃ Weights (Initializing Weights)។ ជាទូទៅ យើងមិនកំណត់ weights ឲ្យស្មើ ០ ទាំងអស់នោះទេ ប៉ុន្តែយើងប្រើលេខចៃដន្យ (Random numbers)។
```py
# បង្កើត Weight matrix ទំហំ 3x2 ដោយប្រើលេខចៃដន្យ
weights = np.random.rand(3, 2)
print("Initial Weights:\n", weights)
```

---
---
---
## ជំពូកទី ២៖ មូលដ្ឋានគ្រឹះនៃ NDArray (Creation, Datatypes, Memory Layout)

នៅក្នុង NumPy, សារធាតុស្នូលបំផុតគឺ `ndarray` (N-dimensional array)។ វាគឺជាតារាងនៃធាតុដែលមានប្រភេទដូចគ្នា (Homogeneous items)។

### ២.១ ការបង្កើត Array តាមវិធីផ្សេងៗ (Array Creation Routines)

ក្រៅពីការប្រើ `np.array()`, NumPy ផ្តល់មុខងារជាច្រើនទៀតសម្រាប់បង្កើត Array ដែលមានប្រយោជន៍ខ្លាំងក្នុងការរៀបចំ Neural Network Layers។

*   `np.zeros()`: បង្កើត Array ដែលមានលេខ ០ ទាំងអស់ (ប្រើសម្រាប់ Biases ក្នុង AI)
*   `np.ones()`: បង្កើត Array ដែលមានលេខ ១ ទាំងអស់
*   `np.eye()`: បង្កើត Identity Matrix (មានលេខ ១ នៅអង្កត់ទ្រូង - Diagonal)
*   `np.arange()`: បង្កើតលំដាប់លេខ (ដូច range ក្នុង Python)