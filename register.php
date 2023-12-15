<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Proiect - Creeaza un cont</title>
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
        input[type="button"] {
            background-color: #3498db;
            color: #fff;
            cursor: pointer;
            padding: 10px;
            border-radius: 5px;
            width: 100%;
            display: block;
        }

        input[type="reset"]:hover,
        input[type="submit"]:hover,
        input[type="button"]:hover {
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
</head>


<body>
    <form method="POST" action="connect.php">
        <!-- Formular de creare cont -->
        <table>
            <tr>
                <td width="30%">Username :</td>
                <td><input type="text" name="username"></td>
            </tr>
            <tr>
                <td>Parola :</td>
                <td>
                    <input type="password" name="password" id="parola">
                    <input type="text" name="parola_visible" id="parola_visible" style="display:none;">
                    <input type="button" class="show-parola-btn" value="Show" onclick="toggleParolaVisibility()">
                </td>
            </tr>
            <tr>
                <td><input type="reset" value="Reset"></td>
                <td><input type="submit" value="Send"></td>
            </tr>
        </table>
    </form>

    <script>
        function toggleParolaVisibility() {
            var parolaInput = document.getElementById('parola');
            var visibleInput = document.getElementById('parola_visible');
            var showParolaBtn = document.querySelector('.show-parola-btn');

            if (parolaInput.type === 'password') {
                parolaInput.type = 'text';
                visibleInput.style.display = 'none';
                showParolaBtn.value = 'Hide';
            } else {
                parolaInput.type = 'password';
                visibleInput.style.display = 'none';
                showParolaBtn.value = 'Show';
            }
        }

        document.addEventListener('DOMContentLoaded', function () {
            var successMessage = "<?php echo isset($mesaj_succes) ? $mesaj_succes : ''; ?>";

            if (successMessage) {
                // Afișăm mesajul de succes
                alert(successMessage);

                setTimeout(function () {
                    window.close();
                }, 5000);
            }
        });
    </script>
</body>

</html>