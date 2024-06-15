# Image Classification Pipeline

This repository contains a complete pipeline for training, evaluating, and improving an image classification model using TensorFlow and Keras. The pipeline is designed to handle a dataset organized into training, validation, and test directories.

## Pipeline Steps

### 1. Environment Setup

The code utilizes various Python libraries for linear algebra, data processing, and machine learning. It sets up the environment to load these libraries:

```python
import numpy as np  # linear algebra
import pandas as pd  # data processing
import os
```

### 2. Data Loading

The code recursively lists all files in the specified input directory, helping to verify that the dataset is correctly placed:

```python
for dirname, _, filenames in os.walk('/kaggle/input/competitie'):
    for filename in filenames:
        print(os.path.join(dirname, filename))
```

### 3. Image Loading and Preprocessing

Images are loaded from the training, validation, and test directories, resized to a consistent shape, and converted into NumPy arrays. This ensures all images are of the correct dimensions for model input:

```python
from PIL import Image
from sklearn.preprocessing import LabelEncoder

# Define directories
train_dir = '/kaggle/input/dataset/train'
test_dir = '/kaggle/input/dataset/test'
validation_dir = '/kaggle/input/dataset/validation'

# Function to load and resize images
def load_images_from_folder(folder, image_size=(128, 128)):
    images = []
    for filename in os.listdir(folder):
        img_path = os.path.join(folder, filename)
        img = Image.open(img_path).resize(image_size)
        img_array = np.array(img)
        if img_array.shape == (image_size[0], image_size[1], 3):
            images.append(img_array)
    return np.array(images)

# Load images
X_train = load_images_from_folder(train_dir)
X_test = load_images_from_folder(test_dir)
X_validation = load_images_from_folder(validation_dir)

print(f"Train images shape: {X_train.shape}")
print(f"Test images shape: {X_test.shape}")
print(f"Validation images shape: {X_validation.shape}")
```

### 4. Data Processing

Images and labels are further processed. Labels are extracted from filenames and encoded. The validation dataset is filtered to ensure only labels present in the training dataset are considered:

```python
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

# Load and preprocess images
X_train, train_labels = load_and_preprocess_images(train_dir, img_height, img_width)
X_validation, validation_labels = load_and_preprocess_images(validation_dir, img_height, img_width)

# Encode labels
label_encoder = LabelEncoder()
y_train = label_encoder.fit_transform(train_labels)

# Filter validation labels
filtered_validation_labels = [label for label in validation_labels if label in train_labels]
filtered_validation_images = [img for img, label in zip(X_validation, validation_labels) if label in train_labels]
y_validation = label_encoder.transform(filtered_validation_labels)
X_validation = np.array(filtered_validation_images)

print(f"Dimensiune X_train: {X_train.shape}, y_train: {y_train.shape}")
print(f"Dimensiune X_validation: {X_validation.shape}, y_validation: {y_validation.shape}")
```

### 5. Creating TensorFlow Datasets

The training and validation datasets are converted into TensorFlow datasets for efficient processing during model training:

```python
batch_size = 32
train_ds = tf.data.Dataset.from_tensor_slices((X_train, y_train)).batch(batch_size).cache().shuffle(1000).prefetch(buffer_size=tf.data.AUTOTUNE)
val_ds = tf.data.Dataset.from_tensor_slices((X_validation, y_validation)).batch(batch_size).cache().prefetch(buffer_size=tf.data.AUTOTUNE)
```

### 6. Model Building and Training

A convolutional neural network (CNN) model is built using Keras. The model is compiled with the Adam optimizer and trained on the training dataset, with validation performed on the validation dataset:

```python
from tensorflow.keras import layers
from tensorflow.keras.models import Sequential

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

model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

history = model.fit(
  train_ds,
  validation_data=val_ds,
  epochs=10
)
```

### 7. Evaluation and Validation

The model is evaluated on the validation dataset to check its performance:

```python
test_loss, test_acc = model.evaluate(test_ds, verbose=2)
print(f"\nTest accuracy: {test_acc}")
```

### 8. Improvements

Data augmentation techniques such as random flipping, rotation, and zoom are applied to the dataset to improve the model's robustness. The model is then retrained with these augmented data:

```python
data_augmentation = tf.keras.Sequential([
    layers.RandomFlip("horizontal", input_shape=(img_height, img_width, 3)),
    layers.RandomRotation(0.1),
    layers.RandomZoom(0.1),
])

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

model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

history = model.fit(
  train_ds,
  validation_data=val_ds,
  epochs=10
)
```

## Results

The performance of the model, including training and validation accuracy and loss, is visualized to assess the improvements made by data augmentation and other techniques:

```python
acc = history.history['accuracy']
val_acc = history.history['val_accuracy']

loss = history.history['loss']
val_loss = history.history['val_loss']

import matplotlib.pyplot as plt

plt.figure(figsize=(8, 8))
plt.subplot(1, 2, 1)
plt.plot(epochs, acc, label='Training Accuracy')
plt.plot(epochs, val_acc, label='Validation Accuracy')
plt.legend(loc='lower right')
plt.title('Training and Validation Accuracy')

plt.subplot(1, 2, 2)
plt.plot(epochs, loss, label='Training Loss')
plt.plot(epochs, val_loss, label='Validation Loss')
plt.legend(loc='upper right')
plt.title('Training and Validation Loss')
plt.show()
```
