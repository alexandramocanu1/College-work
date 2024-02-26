<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Competitii</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            flex-direction: column;
            align-items: center;
            background-color: #003333;
        }

        #header {
            width: 100%;
            height: 300px;
            overflow: hidden;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        #header img {
            width: auto;
            height: 100%;
        }

        #menuButton {
            background: none;
            border: none;
            cursor: pointer;
            position: absolute;
            top: 20px;
            left: 20px;
            z-index: 2;
            color: #fff;
        }

        form {
            background-color: #333;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(255, 255, 255, 0.1);
            margin-top: -50px;
            width: 80%;
            max-width: 400px;
            display: none;
            position: relative;
            z-index: 1;
        }

        form label {
            display: block;
            margin-bottom: 10px;
            color: #fff;
        }

        form input {
            width: 100%;
            padding: 10px;
            margin-bottom: 15px;
            border: none;
            border-radius: 5px;
        }

        form input[type="submit"] {
            background-color: #3498db;
            color: #fff;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        form input[type="submit"]:hover {
            background-color: #2980b9;
        }

        table {
            width: 80%;
            border-collapse: collapse;
            margin-top: 20px;
            background-color: #333;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(255, 255, 255, 0.1);
        }

        th,
        td {
            padding: 15px;
            text-align: left;
            border-bottom: 1px solid #555;
            color: #fff;
        }

        th {
            background-color: #555;
        }
    </style>
</head>

<body>
    <div id="header">
        <img src="https://scontent.fotp3-4.fna.fbcdn.net/v/t1.6435-9/72280803_2450952238480552_455764006552993792_n.jpg?stp=dst-jpg_s960x960&_nc_cat=108&ccb=1-7&_nc_sid=7f8c78&_nc_ohc=FWBuxdh15fMAX80NIMR&_nc_ht=scontent.fotp3-4.fna&oh=00_AfAq-uCtJNnMjJHZKCQjK8yHipr5Qor3IrBghJCyTMihnA&oe=65A2EF5C"
            alt="header-image">
        <button id="menuButton" onclick="toggleFormVisibility()">☰</button>
    </div>

    <form id="competitionForm" method="POST" action="adauga_competitii.php">
        <label for="locul">Locul:</label>
        <input type="text" name="locul" required>

        <label for="competitie">Competitie:</label>
        <input type="text" name="competitie" required>

        <label for="data">Data:</label>
        <input type="date" name="data" required>

        <label for="proba">Proba:</label>
        <input type="text" name="proba" required>

        <input type="hidden" name="caracter" value="1">
        <input type="submit" value="Adauga concurs">
    </form>

    <table>
        <thead>
            <tr>
                <th>Locul</th>
                <th>Competitie</th>
                <th>Data</th>
                <th>Proba</th>
            </tr>
        </thead>
        <tbody>
            <?php
            // Conectare la baza de date
            $link = mysqli_connect("localhost", "root", "", "concursuri_sportive");

            if (!$link) {
                echo "Error: Unable to connect to MySQL.";
                exit;
            }

            // Interogare pentru a obține competițiile
            $query = "SELECT locul, competitie, data, proba FROM competitii";
            $result = mysqli_query($link, $query);

            if ($result) {
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<tr>";
                    echo "<td>{$row['locul']}</td>";
                    echo "<td>{$row['competitie']}</td>";
                    echo "<td>{$row['data']}</td>";
                    echo "<td>{$row['proba']}</td>";
                    echo "</tr>";
                }
            } else {
                echo "Error: " . $query . "<br>" . mysqli_error($link);
            }

            // Închide conexiunea la baza de date
            mysqli_close($link);
            ?>
        </tbody>
    </table>

    <script>
        function toggleFormVisibility() {
            var form = document.getElementById('competitionForm');
            form.style.display = form.style.display === 'none' ? 'block' : 'none';
        }
    </script>
</body>

</html>
