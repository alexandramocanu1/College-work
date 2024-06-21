# Image Classification Pipeline

Acest repository conține un pipeline complet pentru antrenarea, evaluarea și îmbunătățirea unui model de clasificare a imaginilor utilizând TensorFlow și Keras. Pipeline-ul este conceput pentru a gestiona un set de date organizat în directoare pentru antrenament, validare și testare.

# Pașii Pipeline-ului

# 0. Configurarea Mediului

Codul utilizează diverse biblioteci Python pentru algebră liniară, procesarea datelor și învățare automată. Se configurează mediul pentru a încărca aceste biblioteci:

```python
import numpy as np  # algebra liniară
import pandas as pd  # procesarea datelor
import os  # operațiuni cu fișiere și directoare
from PIL import Image  # procesarea imaginilor
from sklearn.preprocessing import LabelEncoder  # codificarea etichetelor
from tensorflow.keras.utils import load_img, img_to_array  # încărcarea și conversia imaginilor
import tensorflow as tf  # cadru pentru învățare profundă
from tensorflow.keras import layers  # construirea straturilor de rețea neuronală
from tensorflow.keras.models import Sequential  # model secvențial pentru rețele neuronale
```


# 1. Citirea Datelor fin fisier

Codul listează recursiv toate fișierele din directorul specificat pentru a verifica dacă setul de date este corect plasat:

```python
# Pas 1: citirea datelor din fisier:

# Definim calea către directoarele cu imagini
train_dir = '/kaggle/input/dataset/train'
test_dir = '/kaggle/input/dataset/test'
validation_dir = '/kaggle/input/dataset/validation'

# Funcție pentru a încărca imaginile și a le transforma în array-uri
def load_images_from_folder(folder, image_size=(128, 128)):
    images = []
    for filename in os.listdir(folder):
        img_path = os.path.join(folder, filename)
        img = Image.open(img_path).resize(image_size)
        img_array = np.array(img)
        # Verifică dacă imaginea are dimensiunea corectă
        if img_array.shape == (image_size[0], image_size[1], 3):
            images.append(img_array)
    return np.array(images)

# Încărcăm imaginile de antrenament, test și validare
X_train = load_images_from_folder(train_dir)
X_test = load_images_from_folder(test_dir)
X_validation = load_images_from_folder(validation_dir)

# Verificăm forma array-urilor de imagini
print(f"Train images shape: {X_train.shape}")
print(f"Test images shape: {X_test.shape}")
print(f"Validation images shape: {X_validation.shape}")
# numar inmagini, inaltime X latime, RGB (~3, adica Rosu, Verge, Albastu)
```

# Output

Train images shape: (10495, 128, 128, 3)
Test images shape: (4499, 128, 128, 3)
Validation images shape: (2999, 128, 128, 3)

# 2. Procesarea Datelor

Imaginile și etichetele sunt procesate. Etichetele sunt extrase din numele fișierelor și codificate. Setul de date de validare este filtrat pentru a se asigura că sunt considerate doar etichetele prezente în setul de date de antrenament:

```python
# Pas 2: prelucrarea datelor din fisier

# Functie pentru citirea și redimensionarea imaginilor
def load_and_preprocess_images(folder, img_height, img_width):
    images = []
    labels = []
    for filename in os.listdir(folder):
        img_path = os.path.join(folder, filename)
        if img_path.endswith('.png'):
            label = filename.split('_')[0]
            img = load_img(img_path, target_size=(img_height, img_width))
            img_array = img_to_array(img)
            images.append(img_array)
            labels.append(label)
    return np.array(images), np.array(labels)

# Căile către directoarele de date
train_dir = '/kaggle/input/dataset/train'  
validation_dir = '/kaggle/input/dataset/validation' 

# Dimensiunile imaginilor
img_height = 128
img_width = 128

# Citim și preprocesăm imaginile
X_train, train_labels = load_and_preprocess_images(train_dir, img_height, img_width)
X_validation, validation_labels = load_and_preprocess_images(validation_dir, img_height, img_width)

# Codificăm etichetele
label_encoder = LabelEncoder()
y_train = label_encoder.fit_transform(train_labels)

# Filtrăm etichetele de validare pentru a se asigura că toate etichetele sunt prezente în setul de antrenament
filtered_validation_labels = [label for label in validation_labels if label in train_labels]
filtered_validation_images = [img for img, label in zip(X_validation, validation_labels) if label in train_labels]

# Transformăm doar etichetele de validare care sunt prezente în setul de antrenament
y_validation = label_encoder.transform(filtered_validation_labels)

# Convertim în array pentru TensorFlow
X_validation = np.array(filtered_validation_images)

# Verificăm dimensiunile array-urilor
print(f"Dimensiune X_train: {X_train.shape}, y_train: {y_train.shape}")
print(f"Dimensiune X_validation: {X_validation.shape}, y_validation: {y_validation.shape}")
```

# Output

Dimensiune X_train: (10500, 128, 128, 3), y_train: (10500,)
Dimensiune X_validation: (0,), y_validation: (0,)


# Procesarea datelor corectat

```python
import os
import numpy as np
from PIL import Image
from sklearn.preprocessing import LabelEncoder

# Definim calea către directoarele cu imagini
train_dir = '/kaggle/input/dataset/train'
validation_dir = '/kaggle/input/dataset/validation'

# Funcție pentru a încărca imaginile și a le transforma în array-uri și pentru a extrage etichetele
def load_images_and_labels_from_folder(folder, image_size=(128, 128)):
    images = []
    labels = []
    filenames = []
    for filename in os.listdir(folder):
        img_path = os.path.join(folder, filename)
        if img_path.endswith('.png'):
            # Extragem eticheta din numele fișierului (presupunem că primul caracter este eticheta)
            label = filename[0]  # Prima literă din numele fișierului este eticheta
            img = Image.open(img_path).resize(image_size)
            img_array = np.array(img)
            # Verifică dacă imaginea are dimensiunea corectă
            if img_array.shape == (image_size[0], image_size[1], 3):
                images.append(img_array)
                labels.append(label)
                filenames.append(filename)
    return np.array(images), np.array(labels), np.array(filenames)

# Încărcăm imaginile și etichetele pentru antrenament și validare
X_train, train_labels, train_filenames = load_images_and_labels_from_folder(train_dir)
X_validation, validation_labels, validation_filenames = load_images_and_labels_from_folder(validation_dir)

# Codificăm etichetele
label_encoder = LabelEncoder()
y_train = label_encoder.fit_transform(train_labels)

# Debugging information
print(f"Unique labels in training set: {np.unique(train_labels)}")
print(f"Unique labels in validation set: {np.unique(validation_labels)}")

# Filtrăm etichetele de validare pentru a se asigura că toate etichetele sunt prezente în setul de antrenament
filtered_validation_labels = [label for label in validation_labels if label in train_labels]
filtered_validation_images = [img for img, label in zip(X_validation, validation_labels) if label in train_labels]
filtered_validation_filenames = [filename for filename, label in zip(validation_filenames, validation_labels) if label in train_labels]

# Transformăm doar etichetele de validare care sunt prezente în setul de antrenament
if filtered_validation_labels:
    y_validation = label_encoder.transform(filtered_validation_labels)
    X_validation = np.array(filtered_validation_images)
else:
    y_validation = np.array([])
    X_validation = np.array([])

# Verificăm dimensiunile array-urilor
print(f"Dimensiune X_train: {X_train.shape}, y_train: {y_train.shape}")
print(f"Dimensiune X_validation: {X_validation.shape}, y_validation: {y_validation.shape}")

# Print lengths of filtered validation labels and images for debugging
print(f"Length of filtered validation labels: {len(filtered_validation_labels)}")
print(f"Length of filtered validation images: {len(filtered_validation_images)}")
```
Iimaginile sunt încărcate și prelucrate folosind biblioteca PIL (Pillow), iar etichetele sunt extrase din primele caractere ale numelor fișierelor.

# 3. Construirea pipeline-ului de inceput

```python
# Seturile de date TensorFlow

batch_size = 32

train_ds = tf.data.Dataset.from_tensor_slices((X_train, y_train)).batch(batch_size).cache().shuffle(1000).prefetch(buffer_size=tf.data.AUTOTUNE)
val_ds = tf.data.Dataset.from_tensor_slices((X_validation, y_validation)).batch(batch_size).cache().prefetch(buffer_size=tf.data.AUTOTUNE)
```

# 4. Construirea si antrenarea modeluli

```python
# Definim modelul
num_classes = len(label_encoder.classes_)

model = Sequential([
    layers.Rescaling(1./255, input_shape=(img_height, img_width, 3)),
    layers.Conv2D(16, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(32, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(64, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Flatten(),
    layers.Dense(128, activation='relu'),
    layers.Dense(num_classes)
])

# Compilarea modelului
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# Antrenarea modelului
epochs = 10
history = model.fit(
  train_ds,
  validation_data=val_ds,
  epochs=epochs)
```

# Output

```
Epoch 1/10
/opt/conda/lib/python3.10/site-packages/keras/src/layers/preprocessing/tf_data_layer.py:18: UserWarning: Do not pass an `input_shape`/`input_dim` argument to a layer. When using Sequential models, prefer using an `Input(shape)` object as the first layer in the model instead.
  super().__init__(**kwargs)
 22/328 ━━━━━━━━━━━━━━━━━━━━ 2s 8ms/step - accuracy: 0.0676 - loss: 2.8580
WARNING: All log messages before absl::InitializeLog() is called are written to STDERR
I0000 00:00:1718970142.449656     115 device_compiler.h:186] Compiled cluster using XLA!  This line is logged at most once for the lifetime of the process.
W0000 00:00:1718970142.472925     115 graph_launch.cc:671] Fallback to op-by-op mode because memset node breaks graph update
322/328 ━━━━━━━━━━━━━━━━━━━━ 0s 19ms/step - accuracy: 0.0609 - loss: 2.7855
W0000 00:00:1718970149.122299     118 graph_launch.cc:671] Fallback to op-by-op mode because memset node breaks graph update
328/328 ━━━━━━━━━━━━━━━━━━━━ 16s 24ms/step - accuracy: 0.0610 - loss: 2.7853 - val_accuracy: 0.0637 - val_loss: 2.7730
Epoch 2/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.0681 - loss: 2.7728 - val_accuracy: 0.0567 - val_loss: 2.7733
Epoch 3/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.0718 - loss: 2.7654 - val_accuracy: 0.0630 - val_loss: 2.7787
Epoch 4/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.1202 - loss: 2.6849 - val_accuracy: 0.0627 - val_loss: 2.8329
Epoch 5/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.2419 - loss: 2.3607 - val_accuracy: 0.0684 - val_loss: 3.1771
Epoch 6/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.4417 - loss: 1.7706 - val_accuracy: 0.0574 - val_loss: 4.1890
Epoch 7/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.6340 - loss: 1.1798 - val_accuracy: 0.0677 - val_loss: 6.3157
Epoch 8/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.7586 - loss: 0.7874 - val_accuracy: 0.0574 - val_loss: 8.3343
Epoch 9/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.8212 - loss: 0.6176 - val_accuracy: 0.0637 - val_loss: 9.8657
Epoch 10/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.8652 - loss: 0.4824 - val_accuracy: 0.0497 - val_loss: 12.0474
```

  

# 5. Evaluarea si validarea modelului:

```python

# Definim modelul
num_classes = len(label_encoder.classes_)

model = Sequential([
    layers.Input(shape=(img_height, img_width, 3)),  # Folosim un strat Input separat
    layers.Rescaling(1./255),
    layers.Conv2D(16, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(32, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(64, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Flatten(),
    layers.Dense(128, activation='relu'),
    layers.Dense(num_classes)
])

# Compilăm modelul
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# Antrenăm modelul
epochs = 10
history = model.fit(
  train_ds,
  validation_data=val_ds,
  epochs=epochs
)
```

# Output

``` Epoch 1/10
 16/328 ━━━━━━━━━━━━━━━━━━━━ 3s 12ms/step - accuracy: 0.0735 - loss: 2.8384
W0000 00:00:1718970288.199135     116 graph_launch.cc:671] Fallback to op-by-op mode because memset node breaks graph update
325/328 ━━━━━━━━━━━━━━━━━━━━ 0s 13ms/step - accuracy: 0.0596 - loss: 2.7814
W0000 00:00:1718970292.862466     116 graph_launch.cc:671] Fallback to op-by-op mode because memset node breaks graph update
328/328 ━━━━━━━━━━━━━━━━━━━━ 8s 16ms/step - accuracy: 0.0596 - loss: 2.7813 - val_accuracy: 0.0564 - val_loss: 2.7731
Epoch 2/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.0662 - loss: 2.7728 - val_accuracy: 0.0564 - val_loss: 2.7732
Epoch 3/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.0678 - loss: 2.7718 - val_accuracy: 0.0557 - val_loss: 2.7737
Epoch 4/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.0678 - loss: 2.7667 - val_accuracy: 0.0614 - val_loss: 2.7872
Epoch 5/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.1091 - loss: 2.6939 - val_accuracy: 0.0580 - val_loss: 2.8514
Epoch 6/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.2046 - loss: 2.4557 - val_accuracy: 0.0570 - val_loss: 3.1721
Epoch 7/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.3378 - loss: 2.0493 - val_accuracy: 0.0577 - val_loss: 4.0257
Epoch 8/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.4546 - loss: 1.6881 - val_accuracy: 0.0600 - val_loss: 5.1599
Epoch 9/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.5680 - loss: 1.3724 - val_accuracy: 0.0597 - val_loss: 7.3925
Epoch 10/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 3s 8ms/step - accuracy: 0.6376 - loss: 1.1584 - val_accuracy: 0.0620 - val_loss: 9.2532
```

# 6. Imbunatatirea modelului:

```python
# Augmentarea datelor
data_augmentation = keras.Sequential(
  [
    layers.RandomFlip("horizontal", input_shape=(img_height, img_width, 3)),
    layers.RandomRotation(0.1),
    layers.RandomZoom(0.1),
  ]
)

# Redefinim modelul cu augmentarea datelor și dropout
model = Sequential([
    data_augmentation,
    layers.Rescaling(1./255),
    layers.Conv2D(16, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(32, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(64, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Dropout(0.2),
    layers.Flatten(),
    layers.Dense(128, activation='relu'),
    layers.Dense(num_classes)
])

# Compilăm și antrenăm modelul din nou
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

history = model.fit(
  train_ds,
  validation_data=val_ds,
  epochs=epochs
)

# Evaluăm modelul pe setul de test
test_loss, test_acc = model.evaluate(test_ds, verbose=2)
print(f"\nTest accuracy: {test_acc}")

# Vizualizăm din nou rezultatele antrenării
acc = history.history['accuracy']
val_acc = history.history['val_accuracy']

loss = history.history['loss']
val_loss = history.history['val_loss']

plt.figure(figsize=(8, 8))
plt.subplot(1, 2, 1)
plt.plot(epochs_range, acc, label='Training Accuracy')
plt.plot(epochs_range, val_acc, label='Validation Accuracy')
plt.legend(loc='lower right')
plt.title('Training and Validation Accuracy')

plt.subplot(1, 2, 2)
plt.plot(epochs_range, loss, label='Training Loss')
plt.plot(epochs_range, val_loss, label='Validation Loss')
plt.legend(loc='upper right')
plt.title('Training and Validation Loss')
plt.show()
```
# Updated

```python
# Importuri corecte pentru TensorFlow 2.x
from tensorflow.keras import layers
from tensorflow.keras.models import Sequential
import matplotlib.pyplot as plt

# Definirea parametrilor modelului și datelor
num_classes = len(label_encoder.classes_)
img_height, img_width = 128, 128  # Dimensiunile imaginilor

# Definirea augmentării datelor
data_augmentation = Sequential(
    [
        layers.RandomFlip("horizontal", input_shape=(img_height, img_width, 3)),
        layers.RandomRotation(0.1),
        layers.RandomZoom(0.1),
    ]
)

# Redefinirea modelului cu augmentarea datelor și dropout
model = Sequential([
    data_augmentation,
    layers.Rescaling(1./255),
    layers.Conv2D(16, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(32, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Conv2D(64, 3, padding='same', activation='relu'),
    layers.MaxPooling2D(),
    layers.Dropout(0.2),
    layers.Flatten(),
    layers.Dense(128, activation='relu'),
    layers.Dense(num_classes)
])

# Compilarea și antrenarea modelului
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

epochs = 10

history = model.fit(
    train_ds,
    validation_data=val_ds,
    epochs=epochs
)
test_ds = tf.keras.preprocessing.image_dataset_from_directory(
    test_data_dir,
    image_size=(img_height, img_width),
    batch_size=batch_size
)


# Evaluarea modelului pe setul de test
test_loss, test_acc = model.evaluate(test_ds, verbose=2)
print(f"\nTest accuracy: {test_acc}")

# Vizualizarea rezultatelor antrenamentului
epochs_range = range(1, epochs + 1)
acc = history.history['accuracy']
val_acc = history.history['val_accuracy']

loss = history.history['loss']
val_loss = history.history['val_loss']

plt.figure(figsize=(8, 8))
plt.subplot(1, 2, 1)
plt.plot(epochs_range, acc, label='Training Accuracy')
plt.plot(epochs_range, val_acc, label='Validation Accuracy')
plt.legend(loc='lower right')
plt.title('Training and Validation Accuracy')

plt.subplot(1, 2, 2)
plt.plot(epochs_range, loss, label='Training Loss')
plt.plot(epochs_range, val_loss, label='Validation Loss')
plt.legend(loc='upper right')
plt.title('Training and Validation Loss')
plt.show()
```

# Output

```Epoch 1/10
  1/328 ━━━━━━━━━━━━━━━━━━━━ 10:40 2s/step - accuracy: 0.0625 - loss: 2.7537
2024-06-21 11:49:32.410393: E tensorflow/core/grappler/optimizers/meta_optimizer.cc:961] layout failed: INVALID_ARGUMENT: Size of values 0 does not match size of permutation 4 @ fanin shape inStatefulPartitionedCall/sequential_5_1/dropout_1_1/stateless_dropout/SelectV2-2-TransposeNHWCToNCHW-LayoutOptimizer
328/328 ━━━━━━━━━━━━━━━━━━━━ 7s 15ms/step - accuracy: 0.0662 - loss: 2.7802 - val_accuracy: 0.0560 - val_loss: 2.7730
Epoch 2/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0667 - loss: 2.7724 - val_accuracy: 0.0567 - val_loss: 2.7733
Epoch 3/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 15ms/step - accuracy: 0.0687 - loss: 2.7723 - val_accuracy: 0.0564 - val_loss: 2.7734
Epoch 4/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 15ms/step - accuracy: 0.0664 - loss: 2.7723 - val_accuracy: 0.0564 - val_loss: 2.7735
Epoch 5/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0678 - loss: 2.7725 - val_accuracy: 0.0564 - val_loss: 2.7736
Epoch 6/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0621 - loss: 2.7727 - val_accuracy: 0.0564 - val_loss: 2.7736
Epoch 7/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0735 - loss: 2.7719 - val_accuracy: 0.0567 - val_loss: 2.7735
Epoch 8/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0677 - loss: 2.7724 - val_accuracy: 0.0557 - val_loss: 2.7735
Epoch 9/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 14ms/step - accuracy: 0.0634 - loss: 2.7716 - val_accuracy: 0.0564 - val_loss: 2.7737
Epoch 10/10
328/328 ━━━━━━━━━━━━━━━━━━━━ 5s 15ms/step - accuracy: 0.0718 - loss: 2.7702 - val_accuracy: 0.0607 - val_loss: 2.7743
```
