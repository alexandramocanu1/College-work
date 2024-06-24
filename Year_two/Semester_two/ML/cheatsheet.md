### Cheatsheet ###

#### Soluția bazată pe programare dinamică (grafuri mici) sau aproximare (grafuri mari)

**Scop:**
- Selectarea acțiunilor pentru a maximiza recompensa totală finală
- Acțiunile pot avea consecințe pe termen lung
- Sacrificarea unei recompense imediate poate conduce la câștiguri mai mari pe termen lung

#### Conceptul de Eroare / Pierdere

**Cum măsurăm performanța?**

1. **Regresie:**
   - Media pătratelor erorilor (MSE)
   - Media erorilor în valoare absolută (MAE)

2. **Clasificare:**
   - Numărul de clasificări greșite (misclassification error)

   **Pentru clasificare binară:**
   - True Positive (TP), False Positive (FP), True Negative (TN), False Negative (FN)

   **Pentru clasificare în mai multe clase:**
   - Matricea de confuzie

**Erori**

1. **Eroare de modelare:**
   - Am încercat să modelăm realitatea cu un spațiu de ipoteze

2. **Eroare de estimare:**
   - Am încercat să antrenăm un model cu o mulțime finită de date

3. **Eroare de optimizare:**
   - Nu am reușit să optimizăm funcția până în punctul optim

**Bias-Variance Trade-off**

1. **Bias:**
   - Eroare sistematică care provine din inabilitatea modelului de a învăța adevărata relație dintre trăsături și etichete (underfitting)
   - Poate fi corectată prin creșterea complexității modelului

2. **Variance:**
   - Eroare aleatoare care provine din sensibilitatea ridicată la mici fluctuații din date, cauzată de faptul că modelul a învățat și zgomotul din datele de antrenare (overfitting)
   - Poate fi corectată prin adăugarea de exemple de antrenare sau prin scăderea complexității modelului

**De ce nu este suficient să împărțim datele în train și test?**
- Utilizarea repetată a unei împărțiri atunci când încercăm diverși hiperparametrii poate să “uzeze” setul de test.
- Facem overfitting în spațiul hiperparametrilor!
- Obținem o estimare mai bună a erorii dacă tunăm hiperparametrii pe un set diferit, anume setul de validare.

#### Formulele TPR și FPR

- **TPR (True Positive Rate):** TPR = TP / (TP + FN)
- **FPR (False Positive Rate):** FPR = FP / (FP + TN)

### Ilustrații Vizuale

#### Descompunerea Erorii

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/e9d35aac-8d34-4413-9e3a-94cfc59302b8)


- **Eroare de modelare:** Reprezentată ca distanța dintre modelul antrenat și realitate.
- **Eroare de estimare:** Distanța dintre modelul teoretic și modelul real antrenat.
- **Eroare de optimizare:** Distanța dintre modelul ideal în spațiul de ipoteze și modelul final obținut.

#### Bias-Variance Trade-off

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/588ae97a-f677-461d-a317-e113dd84e1e3)

- **Low Bias, Low Variance:** Modele ideale care generalizează bine.
- **High Bias, Low Variance:** Modele care nu se potrivesc bine pe datele de antrenament (underfitting).
- **Low Bias, High Variance:** Modele care se potrivesc prea bine pe datele de antrenament (overfitting).
- **High Bias, High Variance:** Modele care nu performează bine nici pe datele de antrenament, nici pe cele de testare.

### Explicație Simplificată

Un **Proces de Decizie Markov** (MDP) este un model matematic folosit pentru luarea deciziilor unde rezultatele sunt parțial aleatorii și parțial sub controlul unui decident. Scopul este de a selecta acțiunile care maximizează recompensa totală în timp. 

Rețelele neuronale și alte modele de învățare automată sunt antrenate folosind date și diverse funcții de eroare pentru a măsura performanța. Eroarea poate fi descompusă în:
- **Eroare de modelare:** Diferența dintre realitate și modelul nostru.
- **Eroare de estimare:** Diferența datorată faptului că avem un set finit de date.
- **Eroare de optimizare:** Diferența cauzată de faptul că nu putem optimiza perfect funcția noastră.

În contextul regresiei și clasificării, bias-ul și varianța sunt două tipuri de erori care trebuie gestionate pentru a obține modele bune:
- **Bias:** Erori sistematice care fac modelul să nu se potrivească bine pe date (underfitting).
- **Variance:** Erori datorate suprapotrivirii pe datele de antrenament (overfitting).

Utilizarea corectă a seturilor de antrenament, validare și test ajută la evitarea suprapotrivirii hiperparametrilor și obținerea unei estimări mai precise a erorii modelului.





Retele neuronale
![image](https://github.com/alexandramocanu1/College-work/assets/119112644/284fabbd-738e-47ed-917b-c7f258c075e2)

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/4bb2f4b5-8bb2-4410-a29d-a6286526e90e)


![image](https://github.com/alexandramocanu1/College-work/assets/119112644/26fdad63-bd08-4cc9-a538-b6e0a4697eb4)

Max Pooling:
![image](https://github.com/alexandramocanu1/College-work/assets/119112644/80522f2c-a830-4ab2-a5a4-7963836e8862)







### Analiza și Continuarea Subiectelor

#### Clasificatorul bazat pe memorie (k-NN)

**1. Funcție de distanță**
- **Distanța Euclidiană**:
  Formula: \( d(x, y) = \sqrt{\sum_{i=1}^{n} (x_i - y_i)^2} \)
  Utilizată frecvent pentru probleme de clasificare și regresie.

- **Distanța Manhattan (L1)**:
  Formula: \( d_{L1}(x, y) = \sum_{i=1}^{n} |x_i - y_i| \)
  Această distanță este adecvată pentru seturi de date sparse sau pentru probleme unde diferențele sunt aditive.

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/d4409013-c9bc-46e2-9863-739751d2d39a)

- **Distanța Minkowski (Lp)**:
  Formula generalizată pentru diverse valori ale \( p \): \( d_{Lp}(x, y) = \left( \sum_{i=1}^{n} |x_i - y_i|^p \right)^{1/p} \)
  Include atât distanța Euclidiană (p = 2) cât și distanța Manhattan (p = 1).

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/d1ad336e-e990-4ad9-a71e-2113a4d5859b)

- **Distanța Hamming**:
  Utilizată pentru date categorice sau secvențe ADN. Numără câte trăsături diferă între doi vectori.
  Exemplu: \( d_{Hamming}(x, y) = \sum_{i=1}^{n} [x_i \neq y_i] \)

![image](https://github.com/alexandramocanu1/College-work/assets/119112644/8251e8f0-8b83-4409-a768-e94da40fb60c)

**2. Câți vecini să luăm în considerare?**
- În cazul **1-NN**, se consideră doar cel mai apropiat vecin.
- În cazul **k-NN**, se consideră \( k \) vecini cei mai apropiați și se utilizează un vot majoritar pentru clasificare sau media valorilor pentru regresie.

**3. Avantaje și proprietăți ale modelului k-NN**
- Model simplu, ușor de înțeles și implementat.
- Poate fi aplicat pentru probleme cu multiple clase.
- Suprafața de decizie este neliniară și se adaptează bine la seturi de date diverse.
- Performanța crește odată cu mărirea setului de date de antrenare.
- Parametrul \( k \) permite ajustarea nivelului de regularizare.

**4. Dezavantaje ale modelului k-NN**
- Definirea distanței adecvate poate fi complicată.
- Cost computațional ridicat din cauza necesității de a parcurge întreg setul de antrenare pentru fiecare predicție.
- Sensibil la dimensiunea datelor, necesitând tehnici de reducere a dimensionalității sau hashing local pentru eficiență.

#### Soluții alternative și metode kernel

**1. Soluții pentru reducerea costului computațional**
- **Partiționarea spațiului folosind arbori k-d**
- **Locality sensitive hashing**

**2. Metode kernel**
- **Funcția kernel** permite transformarea datelor într-un spațiu de dimensiuni mai mari, facilitând identificarea relațiilor liniare în acest spațiu.
  Exemple:
  - **Funcția kernel polinomială**: \( k(x, y) = (x \cdot y + c)^d \)
  - **Funcția kernel Gaussinana**: \( k(x, y) = \exp(-\frac{\|x - y\|^2}{2\sigma^2}) \)


**3. Clasificatorul Softmax**
- Utilizat pentru clasificarea multi-clasă.
- Folosește funcția softmax pentru a transforma scorurile de clasă în probabilități.

**4. Algoritm: Coborârea pe gradient**
- **Gradientul numeric**: Aproximare prin diferențe finite.
- **Gradientul analitic**: Derivare exactă folosind analiza matematică.


### Funcții de activare

Funcțiile de activare sunt esențiale în rețelele neuronale, deoarece ele introduc neliniarități care permit rețelei să învețe și să modeleze relații complexe între datele de intrare și cele de ieșire. Iată câteva dintre cele mai utilizate funcții de activare și caracteristicile lor:

#### Sigmoidă
- **Formula:** \( \sigma(x) = \frac{1}{1 + e^{-x}} \)
- **Caracteristici:** Transformă intrările într-un interval de valori între 0 și 1.
- **Probleme:** 
  - Saturarea: La valori foarte mari sau foarte mici ale lui \( x \), derivata se apropie de zero, ceea ce face ca gradientul să fie aproape zero și antrenarea rețelei să devină foarte lentă.
  - Output necentrat: Media valorilor de ieșire nu este zero, ceea ce poate duce la convergență mai lentă.

#### Tanh
- **Formula:** \( \text{tanh}(x) \)
- **Caracteristici:** Transformă intrările într-un interval de valori între -1 și 1.
- **Beneficii:** Media valorilor de ieșire este zero, ceea ce poate accelera convergența comparativ cu sigmoid.
- **Probleme:** De asemenea, suferă de problema saturării la valori foarte mari sau foarte mici ale lui \( x \).

#### ReLU (Rectified Linear Unit)
- **Formula:** \( \text{ReLU}(x) = \max(0, x) \)
- **Caracteristici:** Introduce neliniaritate păstrând doar valorile pozitive. 
- **Beneficii:** 
  - Nu suferă de problema saturării în intervalul pozitiv.
  - Convergenta este mai rapidă datorită derivatelor constante pentru \( x > 0 \).
- **Probleme:** 
  - Neuronii morți: Dacă intrările sunt negative pentru totdeauna, gradientul devine zero și neuronul încetează să mai învețe.

#### Leaky ReLU
- **Formula:** \( \text{Leaky ReLU}(x) = \max(0.1x, x) \)
- **Caracteristici:** Similar cu ReLU, dar permite trecerea unor valori negative mici.
- **Beneficii:** Reduce problema neuronilor morți.

#### ELU (Exponential Linear Unit)
- **Formula:** 
  \[
  \text{ELU}(x) = 
  \begin{cases} 
  x & \text{dacă } x > 0 \\
  \alpha (e^x - 1) & \text{dacă } x \leq 0 
  \end{cases}
  \]
- **Caracteristici:** Similar cu ReLU pentru valori pozitive, dar netedă și continuă pentru valori negative.
- **Beneficii:** Output-ul este aproape de zero, ceea ce ajută la centrare și accelerare a convergenței.

#### Maxout
- **Formula:** \( \text{max}(w_1^T x + b_1, w_2^T x + b_2) \)
- **Caracteristici:** Selectează maximum dintre două funcții liniare.
- **Beneficii:** Poate învăța o funcție de activare optimă din date.

### Practici comune în preprocesarea datelor și inițializarea rețelelor

1. **Preprocesarea datelor (imagini)**:
   - **CIFAR-10**: Scădem imaginea medie pentru fiecare pixel.
   - **Scăderea mediei pe fiecare canal**: Scădem media pixelilor pe canalele RGB.

2. **Inițializarea ponderilor**:
   - **Inițializarea Xavier**: Ponderile sunt inițializate astfel încât să prevină disiparea sau explozia gradientului.

3. **Batch Normalization**:
   - Normalizează activările intermediare în timpul antrenării pentru a accelera convergența și a stabiliza rețeaua.

### Regularizarea folosind Dropout

Dropout este o tehnică de regularizare care presupune "deconectarea" unor neuroni în mod aleator în timpul antrenării:
- La fiecare iterație de antrenare, un subset aleatoriu de neuroni este ignorat.
- Acest lucru previne suprainvățarea (overfitting) și ajută rețeaua să generalizeze mai bine.

### Stratul convoluțional și dimensiunea spațială a unei activări

#### Formula pentru mărimea activării
\[
(N - F) / \text{stride} + 1
\]

### Exemple de calcul pentru dimensiunea volumului de output și numărul de parametri

1. **Volum de input: 32x32x3**
   - **10 filtre de 5x5 cu stride 1, bordură 2**
   - **Mărimea volumului de output**:
     \[
     (32 + 2 \times 2 - 5) / 1 + 1 = 32
     \]
     Deci volumul este 32x32x10.

2. **Numărul de parametri pentru stratul convoluțional**:
   - Fiecare filtru are \( 5 \times 5 \times 3 + 1 = 76 \) parametri (inclusiv bias).
   - Pentru 10 filtre:
     \[
     76 \times 10 = 760 \text{ parametri}
     \]

### Concluzii

- **ConvNets**: Folosim straturi CONV, POOL, FC.
- **Tendințe**:
  - Filtre mai mici și arhitecturi mai adânci.
  - Eliminarea straturilor POOL/FC în favoarea straturilor CONV.
  - Arhitecturi recente precum ResNet și GoogLeNet pun sub semnul întrebării paradigmele tradiționale.

### Arhitectura tipică

\[
[(\text{CONV-RELU})^N-\text{POOL?}]^M-(\text{FC-RELU})^K, \text{SOFTMAX}
\]

unde:
- \( N \) este de obicei în jur de 5.
- \( M \) este mare.
- \( 0 \leq K \leq 2 \).

Dacă ai nevoie de alte detalii sau clarificări, te rog să îmi spui!
