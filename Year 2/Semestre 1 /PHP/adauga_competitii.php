<?php
session_start();

// Verifică dacă utilizatorul este autentificat
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit();
}

// Conectare la baza de date
$link = mysqli_connect("localhost", "root", "", "concursuri_sportive");

if (!$link) {
    die("Error: Unable to connect to MySQL.");
}

// Utilizare declarație pregătită pentru a evita SQL injection
$stmt = mysqli_prepare($link, "SELECT * FROM competitii WHERE id_utilizator = (SELECT id FROM conturi WHERE username = ?)");
mysqli_stmt_bind_param($stmt, "s", $_SESSION['username']);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);

// Afișează competițiile
while ($row = mysqli_fetch_assoc($result)) {
    echo "<p>" . $row['nume_competitie'] . "</p>";
}

// Închide declarația pregătită și conexiunea la baza de date
mysqli_stmt_close($stmt);
mysqli_close($link);
?>
