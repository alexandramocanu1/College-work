<?php
ob_start(); // Începe buffering-ul

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['parola'];

    // Conectare la baza de date
    $link = mysqli_connect("localhost", "root", "", "concursuri_sportive");

    if (!$link) {
        echo "Error: Unable to connect to MySQL.";
        exit;
    }

    // Utilizare declaratie pregatita pentru a evita SQL injection
    $stmt = mysqli_prepare($link, "SELECT * FROM conturi WHERE username = ? AND parola = ?");
    mysqli_stmt_bind_param($stmt, "ss", $username, $password);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_store_result($stmt);

    if (mysqli_stmt_num_rows($stmt) > 0) {
        // Autentificare reusita
        $_SESSION['username'] = $username;
        header("Location: competitii.php");
        exit();
    } else {
        echo json_encode(["status" => "autentificare_esuata", "message" => "Autentificare eșuată. Verifică numele de utilizator și parola.", "errorCode" => 1], JSON_UNESCAPED_UNICODE);

    }

    // Inchide declaratia pregatita si conexiunea la baza de date
    mysqli_stmt_close($stmt);
    mysqli_close($link);
}

ob_end_flush(); // Elibereaza output-ul catre browser
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Proiect</title>
    <style>
        body {
            background-color: #333;
            color: #fff;
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        form {
            background-color: #555;
            border-radius: 10px;
            padding: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);
            max-width: 400px;
            width: 100%;
        }

        table {
            width: 100%;
        }

        input {
            width: calc(100% - 20px);
            padding: 15px;
            margin: 10px 0;
            border: none;
            border-radius: 8px;
        }

        input[type="password"],
        input[type="text"] {
            width: calc(80% - 20px);
        }

        input[type="reset"],
        input[type="submit"],
        input[type="button"],
        a.button {
            background-color: #3498db;
            color: #fff;
            cursor: pointer;
            padding: 10px;
            border-radius: 5px;
            width: 100%;
            display: block;
            text-align: center;
            text-decoration: none;
        }

        input[type="reset"]:hover,
        input[type="submit"]:hover,
        input[type="button"]:hover,
        a.button:hover {
            background-color: #2980b9;
        }

        .show-parola-btn {
            background-color: #555;
            color: #fff;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            padding: 10px;
            width: calc(20% - 20px);
            margin: 10px 0;
        }
    </style>
    <script src="https://code.jquery.com/jquery-3.6.4.min.js"></script>
    <!-- Adauga aceasta linie pentru a incarca jQuery -->
    <script>


        function openCompetitiiPage() {
            // Obtine datele din formular
            var username = document.querySelector('input[name="username"]').value;
            var parola = document.querySelector('input[name="parola"]').value;

            // Trimite cererea AJAX catre server pentru a verifica autentificarea
            $.ajax({
                type: "POST",
                url: "connect.php",
                data: {
                    username: username,
                    parola: parola
                },
                success: function (response) {
                    try {
                        var jsonResponse = JSON.parse(response);
                        handleLoginResponse(jsonResponse);
                    } catch (error) {
                        console.error("Eroare la parsarea răspunsului JSON:", error);
                        alert("Eroare necunoscută. Verifică consola pentru detalii.");
                    }
                },


                error: function (jqXHR, textStatus, errorThrown) {
                    // Poți trata aici erorile de cerere AJAX
                    console.error("Eroare AJAX:", textStatus, errorThrown);
                    alert("Eroare la verificarea autentificării. Verifică consola pentru detalii.");
                }
            });

            // Returneaza false pentru a opri trimiterea formularului în acest punct
            return false;
        }

        // Functie pentru a gestiona raspunsul de la server
        function handleLoginResponse(response) {
            if (response.status === "autentificare_reusita") {
                // Redirecționează către pagina "competitii.php" dacă autentificarea este reușită
                window.location.href = "competitii.php";
            } else if (response.status === "autentificare_esuata") {
                // Afișează fereastra modală cu mesajul de eroare
                showErrorModal(response.message);
            } else if (response.status === "eroare_interogare") {
                // Afișează un mesaj pentru erori la interogare
                alert("Eroare la verificarea autentificării.");
            } else {
                // Afișează un mesaj pentru orice alt răspuns necunoscut
                alert("Eroare necunoscută. Răspunsul serverului: " + JSON.stringify(response));
            }
        }

        function showErrorModal(errorMessage) {
            // Creează un element modal
            var modal = document.createElement('div');
            modal.className = 'modal';
            modal.innerHTML = '<div class="modal-content">' + errorMessage + '</div>';

            // Adaugă modalul la corpul documentului
            document.body.appendChild(modal);

            // Așteaptă 3 secunde și apoi elimină modalul
            setTimeout(function () {
                document.body.removeChild(modal);
            }, 3000);
        }



        // Funcția pentru a comuta vizibilitatea parolei
        function toggleParolaVisibility() {
            var parolaInput = document.getElementById('parola');
            var parolaVisibleInput = document.getElementById('parola_visible');
            var showParolaBtn = document.querySelector('.show-parola-btn');

            if (parolaInput.type === 'password') {
                parolaInput.type = 'text';
                parolaVisibleInput.type = 'password';
                showParolaBtn.value = 'Hide';
            } else {
                parolaInput.type = 'password';
                parolaVisibleInput.type = 'text';
                showParolaBtn.value = 'Show';
            }
        }



        function openCompetitiiPage() {
            // Obtine datele din formular
            var username = document.querySelector('input[name="username"]').value;
            var parola = document.querySelector('input[name="parola"]').value;

            // Trimite cererea AJAX catre server pentru a verifica autentificarea
            $.ajax({
                type: "POST",
                url: "connect.php",
                data: {
                    username: username,
                    parola: parola
                },
                success: function (response) {
                    try {
                        var jsonResponse = JSON.parse(response);
                        if (jsonResponse.status === "autentificare_reusita") {
                            // Redirecționează către pagina "competitii.php" dacă autentificarea este reușită
                            window.location.href = "competitii.php";
                        } else if (jsonResponse.status === "autentificare_esuata") {
                            // Afișează un mesaj pentru autentificarea eșuată
                            alert(jsonResponse.message);
                        } else if (jsonResponse.status === "eroare_interogare") {
                            // Afișează un mesaj pentru erori la interogare
                            alert("Eroare la verificarea autentificării.");
                        } else {
                            // Afișează un mesaj pentru orice alt răspuns necunoscut
                            alert("Eroare necunoscută. Răspunsul serverului: " + response);
                        }
                    } catch (error) {
                        console.error("Eroare la parsarea răspunsului JSON:", error);
                        alert("Eroare necunoscută. Verifică consola pentru detalii.");
                    }
                },

                error: function (jqXHR, textStatus, errorThrown) {
                    // Poți trata aici erorile de cerere AJAX
                    console.error("Eroare AJAX:", textStatus, errorThrown);
                    alert("Eroare la verificarea autentificării. Verifică consola pentru detalii.");
                }

            // Returneaza false pentru a opri trimiterea formularului în acest punct
            return false;
            }

        // Functia pentru a comuta vizibilitatea parolei
        function toggleParolaVisibility() {
                    var parolaInput = document.getElementById('parola');
                    var parolaVisibleInput = document.getElementById('parola_visible');
                    var showParolaBtn = document.querySelector('.show-parola-btn');

                    if (parolaInput.type === 'password') {
                        parolaInput.type = 'text';
                        parolaVisibleInput.type = 'password';
                        showParolaBtn.value = 'Hide';
                    } else {
                        parolaInput.type = 'password';
                        parolaVisibleInput.type = 'text';
                        showParolaBtn.value = 'Show';
                    }
                }
    </script>
</head>

<body>
    <form method="POST" action="login.php" onsubmit="return openCompetitiiPage()">
        <table>
            <tr>
                <td width="30%">Username :</td>
                <td><input type="text" name="username"></td>
            </tr>
            <tr>
                <td>Parola :</td>
                <td>
                    <input type="password" name="parola" id="parola">
                    <input type="text" name="parola_visible" id="parola_visible" style="display:none;">
                    <input type="button" class="show-parola-btn" value="Show" onclick="toggleParolaVisibility()">
                </td>
            </tr>
            <tr>
                <td><input type="submit" value="Log In"></td>
                <td><a href="register.php" class="button">Creeaza un cont</a></td>
            </tr>
        </table>
    </form>
</body>

</html>