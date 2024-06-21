1. **Pentru ce se folosește ReLU?**
   - ReLU este o funcție care ajută rețelele neuronale să învețe lucruri mai complicate și să se antreneze mai bine.

2. **Ce înseamnă Dense?**
   - Un strat Dense este un strat unde fiecare neuron este conectat la toți neuronii din stratul anterior. Aceste straturi ajută rețeaua să ia decizii sau să facă predicții.

3. **Ce înseamnă Dropout?**
   - Dropout este o metodă de a face rețeaua neurală mai robustă, "oprind" aleatoriu unii neuroni în timpul antrenamentului pentru a preveni overfitting-ul (când modelul învață prea bine pe datele de antrenament și nu generalizează bine pe date noi).

4. **Ce faceți cu etichetele de validare care nu sunt prezente în setul de antrenament (filtered_validation_labels)?**
   - Dacă găsim etichete în setul de validare care nu există în setul de antrenament, le eliminăm pentru a ne asigura că modelul este evaluat corect.

5. **De ce ai folosit layers.MaxPooling2D() după fiecare strat Conv2D?**
   - MaxPooling2D reduce dimensiunea imaginii rezultate de la stratul Conv2D, ceea ce face modelul mai eficient și reduce riscul de overfitting.

6. **Ce e ăla un filtru (la CNN)?**
   - Un filtru este un mic șablon care "scanază" imaginea pentru a găsi caracteristici importante, cum ar fi margini sau texturi.

7. **De ce ai folosit Rescaling(1./255) în primul strat al modelului?**
   - Rescaling(1./255) normalizează valorile pixelilor imaginilor astfel încât să fie între 0 și 1, ceea ce ajută modelul să învețe mai repede.

8. **Ce înseamnă tf.data.Dataset.from_tensor_slices((X_train, y_train)) și de ce ai folosit această metodă pentru a crea setul de date de antrenament?**
   - Aceasta creează un set de date TensorFlow din imaginile și etichetele noastre, ceea ce face mai ușoară manipularea și antrenarea modelului cu date mari.

9. **Cum arată graficul de convergență al modelului tău?**
   - Graficul de convergență arată cum s-a îmbunătățit performanța modelului pe măsură ce a fost antrenat. Acesta poate arăta atât precizia, cât și pierderea (loss) pe parcursul epocilor de antrenament.

### Întrebări și răspunsuri suplimentare

10. **Ce este o epocă în contextul antrenării unui model?**
    - O epocă este o trecere completă prin toate datele de antrenament. Antrenarea unui model implică de obicei mai multe epoci pentru a îmbunătăți performanța.

11. **De ce folosim metode de augmentare a datelor?**
    - Augmentarea datelor creează versiuni modificate ale imaginilor din setul de date pentru a ajuta modelul să fie mai robust și să se generalizeze mai bine la date noi.

12. **Ce înseamnă că un model se "antrenează"?**
    - Antrenarea unui model înseamnă ajustarea parametrilor acestuia pe baza datelor de antrenament pentru a îmbunătăți performanța la predicții.

13. **Ce este overfitting-ul?**
    - Overfitting-ul este atunci când un model învață prea bine detaliile din setul de antrenament, dar nu funcționează bine pe date noi.

14. **De ce folosim straturi convoluționale (Conv2D)?**
    - Straturile convoluționale (Conv2D) sunt folosite pentru a detecta caracteristici importante în imagini, cum ar fi marginile, texturile și alte tipare vizuale.

15. **Ce este o rețea neuronală?**
    - O rețea neuronală este un model de învățare automată inspirat de modul în care funcționează creierul uman, folosit pentru a rezolva probleme complexe prin învățarea de la date.
   
    O rețea neurală artificială este un grup interconectat de noduri, inspirat de o simplificare a neuronilor din creier. Fiecare nod reprezintă un neuron artificial și o săgeată reprezintă o conexiune de la ieșirea unui neuron artificial la intrarea altuia.
