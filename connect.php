<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Conectare la baza de date
    $link = mysqli_connect("localhost", "root", "", "concursuri_sportive");

    if (!$link) {
        echo "Error: Unable to connect to MySQL.";
        exit;
    }

    // Evită SQL injection
    $username = mysqli_real_escape_string($link, $username);
    $password = mysqli_real_escape_string($link, $password);

    // Utilizare declarație pregătită pentru verificarea unicității username-ului
    $checkQuery = "SELECT * FROM conturi WHERE username = ?";
    $checkStmt = mysqli_prepare($link, $checkQuery);
    mysqli_stmt_bind_param($checkStmt, "s", $username);
    mysqli_stmt_execute($checkStmt);
    mysqli_stmt_store_result($checkStmt);

    if (mysqli_stmt_num_rows($checkStmt) > 0) {
        // Username-ul există deja, poți afișa un mesaj sau face altceva în consecință
        echo "Username-ul există deja. Te rugăm să alegi altul.";
    } else {
        // Username-ul este unic, poți continua cu adăugarea în baza de date
        // Utilizare declarație pregătită pentru inserare
        $insertQuery = "INSERT INTO conturi (username, parola) VALUES (?, ?)";
        $insertStmt = mysqli_prepare($link, $insertQuery);
        mysqli_stmt_bind_param($insertStmt, "ss", $username, $password);

        if (mysqli_stmt_execute($insertStmt)) {
            // Verificare autentificare reușită
            $_SESSION['username'] = $username;
            echo "autentificare_reusita";
            exit();
        } else {
            echo "Error: " . $insertQuery . "<br>" . mysqli_error($link);
        }

        // Închide declarațiile pregătite pentru verificare și inserare
        mysqli_stmt_close($checkStmt);
        mysqli_stmt_close($insertStmt);
    }

    // Închide conexiunea la baza de date
    mysqli_close($link);
}
?>