## Cheatsheet de Geometrie Computațională

### 1. Puncte, Vectori și Segment
- **Vector între două puncte**: \(\overrightarrow{AB} = (B_x - A_x, B_y - A_y)\)
- **Produs scalar**: \(\overrightarrow{A} \cdot \overrightarrow{B} = A_x \cdot B_x + A_y \cdot B_y\)
- **Produs vectorial (2D)**: \(\overrightarrow{A} \times \overrightarrow{B} = A_x \cdot B_y - A_y \cdot B_x\)
- **Mărime vector**: \(|\overrightarrow{A}| = \sqrt{A_x^2 + A_y^2}\)

### 2. Test de Coliniaritate
- **Determinant pentru coliniaritate**:
  \[
  \text{det}\begin{pmatrix}
  x_2 - x_1 & x_3 - x_1 \\
  y_2 - y_1 & y_3 - y_1
  \end{pmatrix} = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)
  \]
  - Punctele sunt coliniare dacă determinantul este 0.

### 3. Test de Orientare (Pentru a determina dacă un punct se află la stânga sau la dreapta unei linii)
- **Determinantul orientării**:
  \[
  \text{orientation}(A, B, C) = \text{det}\begin{pmatrix}
  B_x - A_x & C_x - A_x \\
  B_y - A_y & C_y - A_y
  \end{pmatrix}
  \]
  - Rezultatul > 0: \(C\) este la stânga de \(\overrightarrow{AB}\)
  - Rezultatul < 0: \(C\) este la dreapta de \(\overrightarrow{AB}\)
  - Rezultatul = 0: Punctele sunt coliniare

### 4. Intersecția Segmentelor
- **Condiții necesare**:
  - Folosind orientarea: Două segmente \((P1, Q1)\) și \((P2, Q2)\) se intersectează dacă și numai dacă:
    \[
    \text{orientation}(P1, Q1, P2) \neq \text{orientation}(P1, Q1, Q2) \text{ și } \text{orientation}(P2, Q2, P1) \neq \text{orientation}(P2, Q2, Q1)
    \]

### 5. Încadrare Punct într-un Poligon
- **Metoda razei**:
  - Trasează o rază de la punct către exteriorul poligonului și numără de câte ori intersectează marginile poligonului.
  - Dacă numărul de intersecții este impar, punctul este în interior; dacă este par, este în exterior.

### 6. Distanța de la un Punct la o Linie
- **Formula pentru distanță**:
  \[
  \text{distanța} = \frac{|Ax + By + C|}{\sqrt{A^2 + B^2}}
  \]
  - Pentru linia dată de ecuația \(Ax + By + C = 0\)

### 7. Convex Hull (Envelopa convexă)
- **Algoritmul Graham Scan**:
  1. Alege cel mai jos punct (sau cel mai stâng în caz de egalitate).
  2. Sortează punctele după unghiul polar față de punctul ales.
  3. Folosește un stack pentru a construi envelopa, eliminând punctele care nu mențin convexitatea.

### 8. Aria unui Poligon
- **Formula ariilor semiplanelor**:
  \[
  \text{Aria} = \frac{1}{2} \left| \sum_{i=1}^{n-1} (x_i y_{i+1} - y_i x_{i+1}) \right|
  \]
  
