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
train_dir = '/kaggle/input/dataset/train'  # Înlocuiește cu calea ta reală
validation_dir = '/kaggle/input/dataset/validation'  # Înlocuiește cu calea ta reală

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
