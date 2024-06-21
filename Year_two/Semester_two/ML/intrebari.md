# Intrebari


1. **Pentru ce se folosește ReLU?**
- Funcția de activare ReLU este folosită pentru a introduce non-linearitate într-o rețea neurală,
ajutând la reducerea problemei gradientului care dispare în timpul antrenamentului modelelor de învățare automată
și permițând rețelelor neuronale să învețe relații mai complexe în date.

2. **Ce înseamnă Dense?**
   - Straturile Dense sunt straturi neuronale fully connected (complet conectate) din rețelele neuronale.
   - Fiecare neuron dintr-un strat Dense primește input de la toți neuronii stratului anterior.
   - Aceste straturi sunt utilizate pentru a efectua clasificări sau regresii pe baza caracteristicilor extrase din straturile anterioare.

3. **Ce înseamnă Dropout?**
   - Dropout este o tehnică de regularizare utilizată pentru a preveni overfitting-ul în rețelele neuronale.
   - Ea funcționează prin "renunțarea" la un procent de neuroni în timpul antrenamentului, forțând rețeaua să învețe caracteristici mai robuste și independente.

4. **Ce faceți cu etichetele de validare care nu sunt prezente în setul de antrenament (filtered_validation_labels)?**
   - Etichetele de validare care nu sunt prezente în setul de antrenament sunt filtrate pentru a elimina eventualele discrepanțe
     între etichetele de antrenament și cele de validare.
   - Acest lucru este important pentru a asigura că modelul este evaluat corect pe date care au același spațiu de etichete ca și datele de antrenament.

5. **De ce ai folosit layers.MaxPooling2D() după fiecare strat Conv2D?**
   - MaxPooling2D este folosit pentru a reduce dimensiunea spațială a reprezentării de ieșire,
     ceea ce ajută la reducerea numărului de parametri și la controlul overfitting-ului.
   - Aceasta este o tehnică comună în CNN pentru a păstra caracteristicile importante și a reduce suprapunerea.

6. **Ce e ăla un filtru (la CNN)?**
   - Un filtru în contextul rețelelor neuronale convoluționale (CNN) este un șablon mic de dimensiuni (de exemplu, 3x3 sau 5x5)
     care se deplasează peste imaginea de intrare pentru a extrage caracteristici locale, cum ar fi marginile sau texturile.

7. **De ce ai folosit Rescaling(1./255) în primul strat al modelului?**
   - Rescaling(1./255) este folosit pentru a normaliza valorile pixelilor imaginilor de intrare.
   - Prin împărțirea fiecărui pixel cu 255, valorile acestora sunt aduse în intervalul [0, 1],
     ceea ce ajută la convergența mai rapidă a modelului în timpul antrenamentului.

8. **Ce înseamnă tf.data.Dataset.from_tensor_slices((X_train, y_train)) și de ce ai folosit această metodă pentru a crea setul de date de antrenament?**
   - Această metodă crează un obiect Dataset TensorFlow din tensori (array-uri numpy) X_train și y_train.
   - Este utilă pentru a gestiona seturile de date mari eficient în TensorFlow, permitând iterații rapide și manipularea ușoară a datelor pentru antrenament.

9. **Cum arată graficul de convergență al modelului tău?**
   - Graficul de convergență al modelului arată evoluția metricilor de antrenament și validare (de exemplu, acuratețe și loss)
     pe măsură ce antrenarea progresează pe parcursul epocilor.
   - Acesta poate fi vizualizat folosind biblioteca matplotlib sau alte instrumente de vizualizare.
